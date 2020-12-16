// circ.cpp : Implementation of CCircApp and DLL registration.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "circ.h"

#include "CatHelp.h"

const CATID CATID_SafeForScripting =
{ 0x7dd95801,0x9882,0x11cf,{0x9f,0xa9,0x00,0xaa,0x00,0x6c,0x42,0xc4 } };
const CATID CATID_SafeForInitializing =
{ 0x7dd95802,0x9882,0x11cf,{0x9f,0xa9,0x00,0xaa,0x00,0x6c,0x42,0xc4 } };

const GUID CDECL CATID_AppContainerCompatible =
{ 0x59fb2056, 0xd625, 0x48d0, { 0xa9, 0x44, 0x1a, 0x85, 0xb5, 0xab, 0x26, 0x40 } };


const GUID CATID_PropertyNotifyControl =
{ 0x157083E1, 0x2368, 0x11cf, {0x87, 0xB9, 0x00, 0xAA, 0x00, 0x6C, 0x81, 0x66} };



const GUID CDECL BASED_CODE _ctlid =
{ 0x9dbafccf, 0x592f, 0x101b, { 0x85, 0xce, 0x0, 0x60, 0x8c, 0xec, 0x29, 0x7b } };

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


CCircApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x9dbafcd2, 0x592f, 0x101b, { 0x85, 0xce, 0x0, 0x60, 0x8c, 0xec, 0x29, 0x7b } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


////////////////////////////////////////////////////////////////////////////
// CCircApp::InitInstance - DLL initialization

BOOL CCircApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CCircApp::ExitInstance - DLL termination

int CCircApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(CreateComponentCategory(
		CATID_SafeForScripting,
		L"Controls that are safely scriptable")))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(CreateComponentCategory(
		CATID_SafeForInitializing,
		L"Controls safely initializable from persistent data")))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(RegisterCLSIDInCategory(
		_ctlid, CATID_SafeForScripting)))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(RegisterCLSIDInCategory(
		_ctlid, CATID_SafeForInitializing)))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(RegisterCLSIDInCategory(
		_ctlid, CATID_AppContainerCompatible)))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(RegisterCLSIDInCategory(
		_ctlid, CATID_Insertable)))
		return ResultFromScode(SELFREG_E_CLASS);

	if (FAILED(RegisterCLSIDInCategory(
		_ctlid, CATID_Control)))
		return ResultFromScode(SELFREG_E_CLASS);

	
	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
