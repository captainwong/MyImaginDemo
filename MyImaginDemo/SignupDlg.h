#pragma once
#include "afxwin.h"


// CSignupDlg dialog
namespace Imagin
{
	class AccSignUp;
};

class CSignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSignupDlg)

public:
	CSignupDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSignupDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SIGNUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	AccSignUp* _signup;
	CString m_email;
	CString m_vcode;
	CString m_passwd;
	bool m_bEmailExists;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnKillfocusEdit1();
	CStatic m_staticNote;
};
