#pragma once

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated
// by Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CCIRCCTRL1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCIRCCTRL1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x9dbafccf,0x592f,0x101b,{0x85,0xce,0x00,0x60,0x8c,0xec,0x29,0x7b}};
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:
	OLE_COLOR GetBackColor()
	{
		OLE_COLOR result;
		GetProperty(DISPID_BACKCOLOR, VT_I4, (void*)&result);
		return result;
	}
	double GetDouble()
	{
		double d;
		GetProperty(5, VT_R8, (void*)&d);
		return d;
	}

// Operations
public:
// _DCirc

// Functions
//

	void AboutBox()
	{
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	double CalcDouble(double a, double b, double c, double d)
	{
		double r;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_R8;
		InvokeHelper(6, DISPATCH_METHOD, VT_R8, &r, parms, a, b, c, d);
		return r;
	}
	float CalcFloat(float a, float b, float c, float d)
	{
		float r;
		static BYTE parms[] = VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(7, DISPATCH_METHOD, VT_R4, &r, parms, a, b, c, d);
		return r;
	}

// Properties
//


// _DCircEvents

// Functions
//

	void ClickIn(long x, long y, float a, double b)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_R8 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, x, y, a, b);
	}
	void ClickOut()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

// Properties
//



};
