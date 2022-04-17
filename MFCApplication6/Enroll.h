#pragma once


// Enroll 对话框
class CMFCApplication6Dlg;
//定义student类。
//CString n[8]用于保存学生各项信息。
//CMFCApplication6Dlg*Dlg1，保存父级对话框指针。
//student(CMFCApplication6Dlg*dlg)构造函数，将父级对话框指针传入。
//void set();成员函数。将n[8]分别插入到父级对话框的CListCtrl控件。
class student
{
public:
	CString n[8];
	CMFCApplication6Dlg*Dlg1 = NULL;	//创建父级对话框指针
	student(CMFCApplication6Dlg*dlg);
	void set();
};
class Enroll : public CDialogEx
{
	DECLARE_DYNAMIC(Enroll)	//动态创建表示可以运行时识别该类
public:
	Enroll(CWnd* pParent = nullptr); // 构造函数，指向夫类的空指针
	virtual ~Enroll();
	//Enroll(CMFCApplication6Dlg*dlg);
	CMFCApplication6Dlg*Dlg = NULL;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Name;
	CEdit Number;
	CEdit YY;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	BOOL PreTranslateMessage(MSG* pMsg);
	CEdit YW;
	CEdit SX;
};
