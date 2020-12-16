// DateDlg.h : header file
//
#pragma once
#include "CCIRCCTRL1.h"
/////////////////////////////////////////////////////////////////////////////
// CDateDlg dialog
//{{AFX_INCLUDES()
//}}AFX_INCLUDES

class CDateDlg : public CDialog
{
// Construction
public:
	CDateDlg(CWnd* pParent = NULL);   // standard constructor
	CDateDlg(COleDateTime dt, CWnd* pParent = NULL);
// Dialog Data
	//{{AFX_DATA(CDateDlg)
	enum { IDD = IDD_DATE };
	//}}AFX_DATA

//	COleDateTime m_dtDate;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDateDlg)
	virtual BOOL OnInitDialog();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


public:
	double OnClickinCircctrl1(long x, long y, float a, double b);
	void OnClickoutCircctrl1();
	CCIRCCTRL1 m_circle;
};


