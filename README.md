# Compile MFC sources with Visual Studio 2019
In previous versions of Visual Studio the bundled MFC source files could be compiled into a static library or a DLL. But since Visual Studio 2008 the necessary files to build MFC are not supplied anymore. In this article I show you how you can compile the MFC sources with Visual Studio 2019.
# Introduction
With the latest Visual C++ versions (since 2008) it is not possible anymore to compile the bundled MFC sources. The necessary files, ie makefiles like <b>atlmfc.mak</b> and a DEF file are not provided anymore

In a LOB software project I needed a x86 MFC DLL without the DAO database classes. With statically linked MFC, I provided my own versions of the DAO classes (which internally use MySQL) by overriding the <b>dao*.obj</b> files, but MFC object files cannot be overridden when using the DLL form of MFC. 

So I took the road to build my own MFC vcxproj files.

The github project https://github.com/fobrs/MFC has all the necessary files to build the MFC sources as a DLL.

# Background, DEF file and LTCG
The first hurdle was the missing DEF file. The MFC DLL exports its symbols via a provided Module Definition File or DEF file. The linker uses this DEF file to create the LIB file for the DLL. I couldn't use the old VC++ 2005 DEF file because the MFC feature pack added a lot of new functions.

After some internet search I discovered the tool: <b>dumpexts.exe</b>.  I found the source code of it and modified it a little so it could create a DEF file for all the objs created by the compiler.

The tool is run as a pre-link Build Event for the MFCDLL project. Because Visual Studio has no macro with a list of all obj files, a DOS command enumerates all obj files in the Intermediate directory before calling <b>dumpexts.exe</b>. Be sure to first clean the MFCDLL project so that no old obj files are hiding in it.

When building the DLL the first time, be also sure Link Time Code Generation (LTCG) is not used. The object files the compiler generates when using LTCG cannot be read by <b>dumpexts.exe</b>. Luckilly when we once have generated a DEF file it can be used in a future LTCG build. 

# Using the code
When you clone the github project, and run the Solution with Visual Studio 2019, a default wizard created MFC application is compiled and run but it uses the private MFC DLL!

To overcome copyright issues, the MFC source files are not included but read during compilation from the $(VCToolsInstallDir) folder. So no original MFC source files are included in the Solution except for one file: ctlpset.cpp. The original file gave a compiler error, so a fixed version is included.

```
1>------ Build started: Project: MFCDLL, Configuration: Release Win32 ------
1>ctlpset.cpp
1>C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\ucrt\corecrt_memcpy_s.h(50): error C4789: buffer 'var' of size 24 bytes will be overrun; 24 bytes will be written starting at offset 8
1>Done building project "MFCDLL.vcxproj" -- FAILED.
```
Apparently there are still bugs present in MFC after all those 28 years!

The current Character Set in the project configuration is set to UNICODE. If you use Multi Byte Character Set then the file <b>afxtaskdialog.cpp</b> is excluded from the built (unload and edit the project file to see this).

In the original <b>mfcdll.mak</b> file the source file <b>dllmodul.cpp</b> is compiled twice with different flags. Therefore this file is copied to <b>dllmodulX.cpp</b> in the MFCstatic project. This project compiles a LIB file which needs to be linked to the exe which is using the MFC DLL.

The MFCres project is a resource DLL which is a localization for German. Alltough it's use is not very well tested in this project.

# Points of Interest
One last point, which I don't understand. I needed to supply the /ENTRY point to all builds except the Release|Win32 build of the main application linker settings. It is set to <b>wWinMainCRTStartup</b> for UNICODE builds.

# ARM64
For a successfull compilation for ARM64 the file <b>dispimpl_supporting.h</b> was reconstructed. <b>armasm.exe</b> is used on <b>objcall_.s</b> to create <b>objcall_.obj</b> This resolves the unknown symbols:
```
 UNSUPPORTEDPLAT_PARAMS (_ARM64_PARAMS)
 UnsupportedplatParamsReset
 UnsupportedplatParamsAddFloat
 UnsupportedplatParamsAddDouble
 ```
To test these functions an Active X Control is added (Circ) to test passing floats and doubles on ARM64. Open the Aboutbox and click 'Circle Active X control', then click outside the circle. Reg free COM is used to load the active X control when running the app. The circ.dll file has to be registered in an admin console with <b>regsvr32 circ.dll</b> before Visual Studio shows the control.
