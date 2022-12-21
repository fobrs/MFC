
#include "framework.h"
#include "resource.h"
#include "DateDlg.h"

// to ensure no mfc(m)XXX(u)(d).lib 's are #pragma comment(lib referenced
#define _AFX_NOFORCE_LIBS
#define MFCM_BUILD
#include <afxwinforms.h>
#using <mscorlib.dll>

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;



#include "CAboutBox.h"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

	CWinFormsControl<Button>	m_NetBut;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();


	void OnWinformButtonClicked(System::Object^,
		System::EventArgs^);
public:
	BEGIN_DELEGATE_MAP(CAboutDlg)
		EVENT_DELEGATE_ENTRY(OnWinformButtonClicked, System::Object^,
			System::EventArgs^)
	END_DELEGATE_MAP()

};


// CAboutDlg dialog used for App About

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_NetBut->Text = gcnew System::String("Winforms button: Click me");

	m_NetBut->Click += MAKE_DELEGATE(System::EventHandler, OnWinformButtonClicked);

	return TRUE;
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_ManagedControl(pDX, IDC_NET_BUTTON, m_NetBut);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

void CAboutDlg::OnBnClickedButton1()
{
	try {
		CString str;
		//CEdit
		CDateDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
		}
	}

	catch (...)
	{
		AfxMessageBox(L"Exception during loading of Active X Object!");
	}

}

void CAboutDlg::OnWinformButtonClicked(System::Object^,
	System::EventArgs^ args)
{
	m_NetBut->Text = gcnew System::String("clicked!");

}


void ShowAboutBox()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}