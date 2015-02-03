// SignupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyImaginDemo.h"
#include "SignupDlg.h"
#include "afxdialogex.h"
#include <regex>
#include "./Imagin/AccSignUp.h"

// CSignupDlg dialog

IMPLEMENT_DYNAMIC(CSignupDlg, CDialogEx)

DECLARE_CALLBACK_USER(get_code_on_result, CSignupDlg, GetCodeOnResult)

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
	ON_BN_CLICKED(IDC_BUTTON2, &CSignupDlg::OnBnClickedButton2)
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
	_signup->CheckIfEmailExists(W2A(m_email));
}


void CSignupDlg::OnBnClickedButton2()
{
	
}


// called by static callback functions
void CSignupDlg::GetCodeOnResult(FUNCTION_PARAMETER_USER_3)
{
	CString strLogInfo;
	if (success) {
		strLogInfo = _T("验证码已送到邮箱");
	} else {
		USES_CONVERSION;
		strLogInfo.Format(_T("获取验证码失败：%s code:%d"), A2W(phrase), code);
	}
	MessageBox(strLogInfo);
}


void CSignupDlg::SignupOnResult(FUNCTION_PARAMETER_USER_3)
{
	CString strLogInfo;
	if (success) {
		strLogInfo = _T("注册成功");
	} else {
		USES_CONVERSION;
		strLogInfo.Format(_T("注册失败：%s code:%d"), A2W(phrase), code);
	}
	MessageBox(strLogInfo);
}


void CSignupDlg::EmailExistsOnResult(FUNCTION_PARAMETER_USER_3, bool exists)
{
	if (success) {
		if (exists) {
			m_bEmailExists = TRUE;
			m_staticNote.SetWindowText(_T("邮箱已注册"));
		} else {
			m_bEmailExists = FALSE;
			m_staticNote.SetWindowText(_T("邮箱可使用"));
		}
	} else {
		CString strLogInfo;
		USES_CONVERSION;
		strLogInfo.Format(_T("验证邮箱失败：%s code:%d"), A2W(phrase), code);
		MessageBox(strLogInfo);
	}
}

