// SignupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyImaginDemo.h"
#include "SignupDlg.h"
#include "afxdialogex.h"
#include <regex>

// CSignupDlg dialog

IMPLEMENT_DYNAMIC(CSignupDlg, CDialogEx)

CSignupDlg::CSignupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignupDlg::IDD, pParent)
	, _signup(NULL)
	, m_email(_T(""))
	, m_vcode(_T(""))
	, m_passwd(_T(""))
	, m_bEmailExists(false)
{

}

CSignupDlg::~CSignupDlg()
{
}

void CSignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_email);
	DDX_Text(pDX, IDC_EDIT2, m_vcode);
	DDX_Text(pDX, IDC_EDIT3, m_passwd);
	DDX_Control(pDX, IDC_STATIC_NOTE, m_staticNote);
}


BEGIN_MESSAGE_MAP(CSignupDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSignupDlg::OnBnClickedButton1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CSignupDlg::OnEnKillfocusEdit1)
END_MESSAGE_MAP()


// CSignupDlg message handlers


void CSignupDlg::OnBnClickedButton1()
{
	
}


static bool is_valid_email(const char* email)
{
	std::regex re("\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*");
	std::string mail(email);
	return std::regex_match(mail, re);
}


void CSignupDlg::OnEnKillfocusEdit1()
{
	UpdateData();
	if (m_email.IsEmpty()) {
		m_staticNote.SetWindowTextW(L"empty email!");
		return;
	}

	USES_CONVERSION;
	if (!is_valid_email(W2A(m_email))) {
		m_staticNote.SetWindowTextW(L"invalid email!");
		return;
	}

	m_bEmailExists = false;

}
