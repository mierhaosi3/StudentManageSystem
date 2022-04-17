// login.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "login.h"
#include "afxdialogex.h"
#include"MFCApplication6Dlg.h"
#include"Enroll.h"

// login 对话框

IMPLEMENT_DYNAMIC(login, CDialogEx)

login::login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_login, pParent)
	, password_value(_T(""))
	, username_value(_T(""))

{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1_username, m_edit_usingname);
	DDX_Control(pDX, IDC_EDIT2_password, m_edit_password);
	DDX_Text(pDX, IDC_EDIT2_password, password_value);
	DDX_Text(pDX, IDC_EDIT1_username, username_value);
	DDX_Control(pDX, IDC_YONG, m_user);
	DDX_Control(pDX, IDC_MI, m_password);
	DDX_Control(pDX, IDC_BUTTON_OK, m_ok);
	DDX_Control(pDX, IDC_BUTTON2, m_cancle);
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &login::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_CHECK1, &login::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON2, &login::OnBnClickedButton2)
END_MESSAGE_MAP()


// login 消息处理程序

BOOL login::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	cfont.CreatePointFont(120, L"Consolas");	
	m_edit_usingname.SetFont(&cfont);				//要加取地址符
	m_edit_password.SetFont(&cfont);
	m_user.SetFont(&cfont);
	m_password.SetFont(&cfont);
	m_ok.SetFont(&cfont);
	m_cancle.SetFont(&cfont);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void login::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	static int k = 3;
	CString name;
	CString password; // 创造两个字符串变量来接受用户输入的信息（用户名和密码等）
	GetDlgItemText(IDC_EDIT1, name); // 返回用户名
	GetDlgItemText(IDC_EDIT2, password); // 返回密码
	UpdateData(true);
	if (password_value.IsEmpty())
	{
		MessageBox(L"用户名不能为空");
	}
	if (password_value.IsEmpty())
		MessageBox(L"密码不能为空");
	if (username_value == "admin" && password_value == "123456")
	{
		// 进入主对话框界面
		m_SuccessLogin = true;
		CDialogEx::OnOK(); // 关闭登陆界面
	}
	else
	{
		// 弹出窗口提示用户名或密码不正确
		MessageBox(_T("用户名或密码不正确！"), _T("提示"), MB_OK);
		// 清空用户名和密码，便于重新输入
		username_value = "";
		password_value = "";
		UpdateData(FALSE); // 更新编辑框控件的显示值
	}
}


void login::OnBnClickedCheck1()			//显示密码按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (IsDlgButtonChecked(IDC_CHECK1) == BST_CHECKED)	//如果被选中
	{
		UpdateData(true);
		CEdit* pEdit = (CEdit*)(this)->GetDlgItem(IDC_EDIT2_password);
		pEdit->SetPasswordChar(0);
		SetDlgItemText(IDC_EDIT2_password, password_value);
		UpdateData(false);
	}
	else
	{
		UpdateData(true);
		CEdit* pEdit = (CEdit*)(this)->GetDlgItem(IDC_EDIT2_password);
		pEdit->SetPasswordChar('*');
		SetDlgItemText(IDC_EDIT2_password, password_value);
		UpdateData(false);
	}
	GetDlgItem(IDC_EDIT2_password)->SetFocus();
}
BOOL login::PreTranslateMessage(MSG* pMsg)	//屏蔽回车响应
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:     // 屏蔽回车
			OnBnClickedButtonOk();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}





void login::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
