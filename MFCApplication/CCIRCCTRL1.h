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


// Operations
public:
// _DCirc

// Functions
//

	double AboutBox()
	{
		double r;
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_R8, &r, nullptr);
		return r;
	}

// Properties
//

// _DCircEvents

// Functions
//

	void ClickIn(long x, long y)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, x, y);
	}
	void ClickOut()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

// Properties
//



};
