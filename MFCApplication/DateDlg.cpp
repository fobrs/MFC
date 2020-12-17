// DateDlg.cpp : implementation file
//

#include "pch.h"
#include "Resource.h"
#include "framework.h"
#include "DateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDateDlg dialog


CDateDlg::CDateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDateDlg::CDateDlg(COleDateTime dt, CWnd* pParent /*=NULL*/)
	: CDialog(CDateDlg::IDD, pParent)
{
}

void CDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDateDlg)
	//}}AFX_DATA_MAP
	//  DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
	//DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
	//  DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
	//  DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
	//  DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
	DDX_Control(pDX, IDC_CIRCCTRL1, m_circle);
}


BEGIN_MESSAGE_MAP(CDateDlg, CDialog)
	//{{AFX_MSG_MAP(CDateDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateDlg message handlers

BEGIN_EVENTSINK_MAP(CDateDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CDateDlg)
	ON_EVENT(CDateDlg, IDC_CIRCCTRL1, 1, CDateDlg::OnClickinCircctrl1, VTS_I4 VTS_I4 VTS_R4 VTS_R8)
	ON_EVENT(CDateDlg, IDC_CIRCCTRL1, 2, CDateDlg::OnClickoutCircctrl1, VTS_NONE)
END_EVENTSINK_MAP()


BOOL CDateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



double CDateDlg::OnClickinCircctrl1(long x, long y, float a, double b)
{
	// TODO: Add your message handler code here
	TRACE("%d %d %f %f", x, y, a, b);
	return b;
}


void CDateDlg::OnClickoutCircctrl1()
{
	// TODO: Add your message handler code here
	m_circle.AboutBox();
}
