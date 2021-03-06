// Enroll.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "Enroll.h"
#include "afxdialogex.h"
#include "MFCApplication6Dlg.h"

// Enroll 对话框


student::student(CMFCApplication6Dlg*dlg)
{
	Dlg1 = dlg;
}

void student::set()
{
	for (int b = 0; b < 8; b++)
	{
		Dlg1->list1.SetItemText(Dlg1->list1.GetItemCount()-1, b, n[b]);	//添加每行中的每个元素的
		//从子窗口读出的东西，传到父窗口控件上
	}
}


IMPLEMENT_DYNAMIC(Enroll, CDialogEx)

Enroll::Enroll(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}


Enroll::~Enroll()
{
}

void Enroll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Name);
	DDX_Control(pDX, IDC_EDIT2, Number);
	DDX_Control(pDX, IDC_EDIT5, YY);
	DDX_Control(pDX, IDC_EDIT3, YW);
	DDX_Control(pDX, IDC_EDIT4, SX);
}


BEGIN_MESSAGE_MAP(Enroll, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Enroll::OnBnClickedButton1)
END_MESSAGE_MAP()


//Enroll 消息处理程序
//创建student类对象，用Enroll：：Dlg初始化student：：Dlg1。
//换取Enroll对话框的数据插入CMFCApplication6Dlg对话框的CListCtrl控件。
//如果输入信息不完整、学号重复，都会报错并退出子级对话框。
//录入成功则提示并退出子级对话框。
void Enroll::OnBnClickedButton1()//“录入”按钮代码。
{
	student stu(Dlg);
	Name.GetWindowTextW(stu.n[0]); //将控件上显示上的数据更新到关联变量
	Number.GetWindowTextW(stu.n[1]);
	YW.GetWindowTextW(stu.n[3]); 
	SX.GetWindowTextW(stu.n[4]);
	YY.GetWindowTextW(stu.n[5]);
	//写出单选框始末，最后一个是初始化时默认选择的单选框，选择一个单选框的同时删掉另一个单选框
	UINT nID = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);

	if (!nID)
	{
		MessageBox(L"请输入完整信息！", L"提示!"); Enroll::OnOK(); return;
	}
	GetDlgItemText(nID, stu.n[2]);
	for (int g = 0; g < 6; g++)
	{
		if (stu.n[g].IsEmpty())
		{
			MessageBox(L"请输入完整信息！", L"提示!");
			Enroll::OnOK();
			return;
		}
	}
	for (int i = 0; i < Dlg->list1.GetItemCount(); i++)
	{
		if (Dlg->list1.GetItemText(i, 1) == stu.n[1])
		{
			CString str("学号为");
			str += stu.n[1]; str += "的学生信息已录入！";
			MessageBox(str, L"提示!");
			Enroll::OnOK();
			return;
		}
	}
	Dlg->list1.InsertItem(Dlg->list1.GetItemCount(), L"");// 从子窗口获取内容传到父类控件上
	double x = _ttof(stu.n[3]) + _ttof(stu.n[4]) + _ttof(stu.n[5]);
	double y = x / 3;
	stu.n[6].Format(L"%f", x); stu.n[7].Format(L"%f", y);
	stu.set();
	MessageBox(L"录入成功", L"提示!");
	Dlg->save = false;
	Enroll::OnOK();
}


BOOL Enroll::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, 0);	//初始化选择框未选
	Dlg = (CMFCApplication6Dlg*)AfxGetMainWnd();	//换取主窗口指针,不加会冲突
	return TRUE; 
}
BOOL Enroll::PreTranslateMessage(MSG* pMsg)

{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:     // 按回车表示确定
			OnBnClickedButton1();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}