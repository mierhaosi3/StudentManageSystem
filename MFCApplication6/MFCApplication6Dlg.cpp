
// MFCApplication6Dlg.cpp: 实现文件
//
#include"ChartCtrl/ChartCtrl.h"
#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"
#include"Enroll.h"
#include <iostream>
#include <iomanip>
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include "LineChart.h"
#include "BarChart.h"
#include "TwoChart.h"
using namespace std;
//在 CMFCApplication6Dlg 类里加入void sort（int col）函数并定义，用于排序数据。
//col参数为需要排序的数据对应的列的索引号。采用整行冒泡法排序。
void CMFCApplication6Dlg::sort(int col)		//降序排列
{
	if (col != 1)
	{
		int k = list1.GetItemCount();
		for (int i = k - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				CString a, b;
				a = list1.GetItemText(j, col); b = list1.GetItemText(j + 1, col);
				if (_ttof(a) < _ttof(b))
				{
					CString s[8];
					for (int o = 0; o < 8; o++)
						s[o] = list1.GetItemText(j, o);
					for (int o = 0; o < 8; o++)
						list1.SetItemText(j, o, list1.GetItemText(j + 1, o));
					for (int o = 0; o < 8; o++)
						list1.SetItemText(j + 1, o, s[o]);
				}
			}
	}
	else //升序
	{
		int k = list1.GetItemCount();	
		for (int i = k - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				CString a, b;
				a = list1.GetItemText(j, col); b = list1.GetItemText(j + 1, col);
				if (_ttof(a) > _ttof(b))
				{
					CString s[8];
					for (int o = 0; o < 8; o++)
						s[o] = list1.GetItemText(j, o);
					for (int o = 0; o < 8; o++)
						list1.SetItemText(j, o, list1.GetItemText(j + 1, o));
					for (int o = 0; o < 8; o++)
						list1.SetItemText(j + 1, o, s[o]);
				}
			}
	}
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32777();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication6Dlg 对话框



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent)
	, edit_name(_T(""))
	, edit_num(_T(""))
	, Vmain_name(_T(""))
	, Vmain_number(_T(""))
	, Vmain_sex(_T(""))
	, Vmain_YW(_T(""))
	, Vmain_SX(_T(""))
	, Vmain_YY(_T(""))
	, Vmain_average(_T(""))
	, Vmain_summ(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list1);
	DDX_Control(pDX, IDC_COMBO1, box);
	DDX_Control(pDX, IDC_EDIT1, Fname);
	DDX_Control(pDX, IDC_EDIT2, Fnumber);
	DDX_Text(pDX, IDC_EDIT1, edit_name);
	DDX_Text(pDX, IDC_EDIT2, edit_num);
	DDX_Control(pDX, IDC_BUTTON_Mainchange, M_change);
	DDX_Control(pDX, IDC_EDIT_Mainname, Main_name);
	DDX_Control(pDX, IDC_EDIT_Mainnumber, Main_number);
	DDX_Control(pDX, IDC_EDIT3, Main_sex);
	DDX_Control(pDX, IDC_EDIT_MainYW, Main_YW);
	DDX_Control(pDX, IDC_EDIT_MainSX, Main_SX);
	DDX_Control(pDX, IDC_EDIT_MainYY, Main_YY);
	DDX_Text(pDX, IDC_EDIT_Mainname, Vmain_name);
	DDX_Text(pDX, IDC_EDIT_Mainnumber, Vmain_number);
	DDX_Text(pDX, IDC_EDIT3, Vmain_sex);
	DDX_Text(pDX, IDC_EDIT_MainYW, Vmain_YW);
	DDX_Text(pDX, IDC_EDIT_MainSX, Vmain_SX);
	DDX_Text(pDX, IDC_EDIT_MainYY, Vmain_YY);
	DDX_Text(pDX, IDC_EDIT_average, Vmain_average);
	DDX_Text(pDX, IDC_EDIT_sum, Vmain_summ);
	DDX_Control(pDX, IDC_BUTTON4, rigth_move);
	DDX_Control(pDX, IDC_BUTTON5, left_move);
	DDX_Control(pDX, IDC_CUSTOM2, m_chartctrl);
	DDX_Control(pDX, IDC_CUSTOM1, m_chartctr2);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication6Dlg::OnCbnSelchangeCombo1)
	ON_CBN_CLOSEUP(IDC_COMBO1, &CMFCApplication6Dlg::OnCloseupCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6Dlg::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCApplication6Dlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication6Dlg::OnBnClickedButton7)
//	ON_COMMAND(ID_APP_EXIT, &CMFCApplication6Dlg::OnAppExit)
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication6Dlg::OnBnClickedButton8)
ON_WM_CTLCOLOR()
ON_COMMAND(ID_32774, &CMFCApplication6Dlg::OnMUEMsave)
ON_COMMAND(ID_32772, &CMFCApplication6Dlg::OnMuemOpen)
ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFCApplication6Dlg::OnNMClickList1)
ON_BN_CLICKED(IDC_BUTTON_Mainchange, &CMFCApplication6Dlg::OnBnClickedButtonMainchange)
ON_COMMAND(ID_32771, &CMFCApplication6Dlg::Onnewhold)
ON_COMMAND(ID_32775, &CMFCApplication6Dlg::Onnweopen)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication6Dlg::OnBnClickedButton5)
ON_COMMAND(ID_32777, &CMFCApplication6Dlg::OnThing)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication6Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication6Dlg::OnBnClickedButton9)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CMFCApplication6Dlg::OnColumnclickList1)
ON_COMMAND(ID_32788, &CMFCApplication6Dlg::Onlinechart)
ON_COMMAND(ID_32789, &CMFCApplication6Dlg::OnBarchart)
ON_COMMAND(ID_32790, &CMFCApplication6Dlg::Ontwochart)
ON_WM_TIMER()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CMFCApplication6Dlg 消息处理程序

BOOL CMFCApplication6Dlg::OnInitDialog()
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
	HACCEL	m_hAccel;		//用于快捷键的句柄
	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MENU1));
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CString tot;
	m_oFont.CreatePointFont(130, L"Consolas");	//fname表示给编辑框命名的控件，funmberr也是
	Fname.SetFont(&m_oFont);				//要加取地址符
	Fnumber.SetFont(&m_oFont);
	//在BOOL CMFCApplication6Dlg::OnInitDialog()函数里加入以下代码。
	//初始化CListctrl控件。并插入一些标头，设置宽度和序列号。

	list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT);
	//拓展list control的格式
	//绘制网格线，表头可以拖拽，可以选择整行或者整列
	CString col[8] = { _T("姓名"),_T("学号"),_T("性别"),_T("语文"),_T("数学"),_T("英语"),_T("总分"),_T("平均分")};
	RECT r;	//rect对象用来存储一个矩形框的左上角坐标、宽度和高度。
	list1.GetClientRect(&r);	//显示矩形框调用函数要加取地址符号
	for (int i = 0; i < 8; i++)
	{
		list1.InsertColumn(i, col[i], LVCFMT_CENTER, (r.right-r.left) / 8);
	}

	list1.SetBkColor(RGB(199, 237, 233));	//设置列表框背景颜色
	list1.SetTextColor(RGB(18, 53, 85));	//字体颜色
	list1.SetTextBkColor(RGB(175, 215, 237));//文字背景色
	InitStatus();	//初始化状态框
	CFile in(L"E://学生成绩记录.txt", CFile::modeRead);	//进去程序打开文件
	list1.DeleteAllItems();		//删除每行数据
	TCHAR* a = new TCHAR;  //tchar相当于任意类型的
	CString z;
	int i = 0, j = 0;
	list1.InsertItem(i, L"");

	while (in.Read(a, 2))	//一个一个汉字读，汉字需要两个字
	{
		if (*a != '\t')		//如果不是“	”则加
			z += *a;		
		else if (*a == '\t')//如果是空格，则存入控件
		{
			list1.SetItemText(i, j++, z); z = L"";
		}
		if (j == 8)
		{
			list1.InsertItem(++i, L"");//插入整行，++i并把j清零
			j = 0;
		}
	}
	list1.DeleteItem(list1.GetItemCount() - 1);//如果不加这个，显示就会多一行
	int index = list1.GetItemCount();	//开局显示文件中一共含有多少条数据
	tot.Format(_T("%d"), index);	//float转cstring
	MessageBox((tot), L"文件记录");

	//折线图
	CChartStandardAxis* pBottomAxis =
		m_chartctrl.CreateStandardAxis(CChartCtrl::BottomAxis);	//绘制坐标轴
	pBottomAxis->SetMinMax(0, 20);	//暂时只用得到20
	CChartStandardAxis* pLeftAxis =
		m_chartctrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	CChartAxis* pAxis1;
	CChartAxisLabel* pLabel;
	CString str1;
	pLeftAxis->SetMinMax(0, 105);
	pBottomAxis->SetTickIncrement(false, 2.0);
	pBottomAxis->SetDiscrete(true);
	CChartLineSerie* pSeries = m_chartctrl.CreateLineSerie();
	m_chartctrl.GetBottomAxis()->GetLabel()->SetText(L"学号");	
	m_chartctrl.SetBackGradient(RGB(255, 255, 255), (RGB(252,230,201)), gtVertical);//花里胡哨的背景
	m_chartctrl.EnableRefresh(false);
	m_chartctrl.GetLegend()->SetVisible(true);			//分类图
	m_chartctrl.GetLegend()->SetHorizontalMode(true);
	m_chartctrl.GetLegend()->UndockLegend(450, 250);
	////条形图

	CChartStandardAxis* pBottomAxis_z =m_chartctr2.CreateStandardAxis(CChartCtrl::BottomAxis);	//绘制坐标轴(x)
	pBottomAxis_z->SetMinMax(0, 20);	//一共有0到20
	pBottomAxis_z->SetDiscrete(true);
	CChartStandardAxis* pLeftAxis_z=m_chartctr2.CreateStandardAxis(CChartCtrl::LeftAxis);//y轴
	pLeftAxis_z->SetMinMax(0, 400);
	pLeftAxis_z->GetLabel()->SetText(_T("成绩"));
	m_chartctr2.GetBottomAxis()->GetLabel()->SetText(L"学号");
	m_chartctr2.GetTitle()->AddString(_T("柱状图"));	//设置柱状图的表头
	CChartFont titleFont;
	titleFont.SetFont(_T("Arial Black"), 120, true, false, true);	//设置标题字体
	m_chartctr2.GetTitle()->SetFont(titleFont);
	m_chartctr2.GetTitle()->SetColor(RGB(0, 0, 128));
	m_chartctr2.SetBackGradient(RGB(255, 255, 255), RGB(255, 127, 80), gtVertical);	//花里胡哨背景色
	m_chartctr2.EnableRefresh(false);
	m_chartctr2.GetLegend()->SetVisible(true);
	m_chartctr2.GetLegend()->SetHorizontalMode(true);
	m_chartctr2.GetLegend()->UndockLegend(450, 10);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


HBRUSH CMFCApplication6Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性	
	if (pWnd->GetDlgCtrlID() == IDC_EDIT1 ||
		pWnd->GetDlgCtrlID() == IDC_EDIT2)// IDC_Display为所选文本框ID    
	{
		pDC->SetTextColor(RGB(25, 60, 200));//设置字体颜色(编辑框)

		//pDC->SetBkColor(RGB(256, 256, 256));//设置背景颜色

		pDC->SetBkMode(TRANSPARENT);//设置背景透明    
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)	
//uint表示无符号整形，iparam使它成为指向一个相对统一的结构的指针，从而使用这个结构来传递复杂的信息
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();	//调用
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}

//创建CComboBox box；控件的OnCloseupCombo1（）函数。
void CMFCApplication6Dlg::OnCloseupCombo1()//“排序”选择列表代码
{
	//判断需要排序的数据，调用sort（int col）函数，将该数据的列的索引号传入col参数。
	CString a; box.GetWindowTextW(a);	//获取将指定窗口标题栏的文本
	if (a == _T("语文"))
		sort(3);
	else if (a == _T("数学"))
		sort(4);
	else if (a == _T("英语"))
		sort(5);
	else if (a == _T("平均分"))
		sort(7);
	else if (a == _T("学号"))	//学号的排列是升序
		sort(1);
	list1.UpdateData();
}


void CMFCApplication6Dlg::OnBnClickedButton1()//“添加”按钮代码
{
	//列表插入一行。创建Enroll对话框对象，并运行。
	
	Enroll enroll;
	enroll.DoModal();
	
}



void CMFCApplication6Dlg::OnBnClickedButton2()//“查找”按钮代码。
{
	CString fname, fnumber;int index = list1.GetItemCount();
	int q = 0;	//用来做flag

	for (int i = 0; i < index; i++)//初始化各行信息的选择状态，设置为未选择。
	{
		list1.SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
	}
	Fname.GetWindowTextW(fname); Fnumber.GetWindowTextW(fnumber);//获取需要搜索的姓名和学号，传入fname和fnumber。
	CString temp;
	//判断fname和fnumber是否为空，并做出对应操作。用int q的值判断是否找到符合信息的学生。
	if (fname!=""&&fnumber!="")
	{
		for (int i = 0; i < index; i++)
		{
			temp = list1.GetItemText(i, 0);
			temp.TrimLeft();	//去掉左面空格//防止非定长函数对结果进行印象
			if (temp == fname && list1.GetItemText(i, 1) == fnumber)
			{
				list1.SetFocus();
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				list1.EnsureVisible(i, true); q = 1;
				CString name, number, sex, YW, SX, YY;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); sex = list1.GetItemText(i, 2);
				YW = list1.GetItemText(i, 3); SX = list1.GetItemText(i, 4); YY = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_number = number; Vmain_sex = sex; Vmain_YW = YW; Vmain_SX = SX; Vmain_YY = YY;
				UpdateData(false);
			}
		}
	}
	else if (fname!="" && fnumber=="")
	{
		for (int i = 0; i < index; i++)
		{
			temp = list1.GetItemText(i, 0);
			temp.TrimLeft();	//去掉左面空格
			if (temp == fname)
			{
				list1.SetFocus();//获得焦点
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				//选中第一行，当鼠标点击列表光标悬浮在上面
				list1.EnsureVisible(i, true); q = 1;//确保可视化
				CString name, number, sex, YW, SX, YY;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); sex = list1.GetItemText(i, 2);
				YW = list1.GetItemText(i, 3); SX = list1.GetItemText(i, 4); YY = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_number = number; Vmain_sex = sex; Vmain_YW = YW; Vmain_SX = SX; Vmain_YY = YY;
				UpdateData(false);
			}
		}
	}
	else if (fname==""&&fnumber!="")
	{
		for (int i = 0; i < index; i++)
		{
			if (list1.GetItemText(i, 1) == fnumber)
			{
				list1.SetFocus();
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				list1.EnsureVisible(i, true); q = 1;
				CString name, number, sex, YW, SX, YY;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); sex = list1.GetItemText(i, 2);
				YW = list1.GetItemText(i, 3); SX = list1.GetItemText(i, 4); YY = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_number = number; Vmain_sex = sex; Vmain_YW = YW; Vmain_SX = SX; Vmain_YY = YY;
				UpdateData(false);
			}
		}
	}
	else if (fname == "" && fnumber == "")
	{
		MessageBox(L"请输入查找信息！",L"输入错误");
		return;
	}
	if (q == 0)
		MessageBox(L"没有找到该学生！",L"输入错误或没有该学生!");
}


void CMFCApplication6Dlg::OnBnClickedButton3()//“删除”按钮代码。
{
	//将已被选择的信息全部删除。if没有选择信息，弹出窗口显示错误信息。
	int message = MessageBox(_T("确认删除么？"), _T("删除确认"), MB_YESNO);	//选项是 YES 或者 NO
	int count = list1.GetSelectedCount();
	POSITION pos = list1.GetFirstSelectedItemPosition();	//得到列表框的那一行
	if (pos)
	{
		int p = 0;
		while (pos)
		{
			int k = list1.GetNextSelectedItem(pos);//则返回条目的POSITION值
			list1.DeleteItem(k-p);	//则返回列表视图控件中下一个被选中的条目索引
			p++;
		}
		save = false;
	}
	else
		MessageBox(L"请选择需要删除的信息！", L"提示!");
}


void CMFCApplication6Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//指针之间、不同类型的引用之间以及指针和能容纳指针的整数类型之间的转换
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication6Dlg::OnBnClickedButton7()
{
	CFile s(L"D://学生成绩记录.txt", CFile::modeCreate | CFile::modeReadWrite);
	//如果文件不存在，请创建一个新文件。 如果该文件已存在，它是被覆盖，并最初设置为长度为零。
	//以读写方式打开文件
	int index = list1.GetItemCount();
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CString a;
			if (j != 7)
				a = list1.GetItemText(i, j) + '\t';	//从控件获取信息
			if (j == 7 && i != index - 1)
			{
				a = list1.GetItemText(i, j) + '\t';	//回退一格
				a += "\r\n";	//回车+换行
			}
			if (j == 7 && i == index - 1)
				a = list1.GetItemText(i, j) + '\t';
			s.Write(a, a.GetLength());	//统计cstring类的长度
		}
	}
	save = true;
}
void CMFCApplication6Dlg::Onnewhold()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(FALSE, _T("txt"), _T("test.txt"));//FALSE表示为“另存为”对话框，否则为“打开”对话框
	if (dlg.DoModal() == IDOK)
	{
		CString strFile = dlg.GetPathName();//获取完整路径
		int index = list1.GetItemCount();
		CStdioFile file;
		if (file.Open(strFile, CStdioFile::modeCreate | CStdioFile::modeNoTruncate | CStdioFile::modeWrite))
			//创建/打开文件//二进制文件
		{
			for (int i = 0; i < index; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					CString a;
					if (j != 7)
						a = list1.GetItemText(i, j) + '\t';
					if (j == 7 && i != index - 1)
					{
						a = list1.GetItemText(i, j) + '\t';	//回退一格
						a += "\r\n";	//回车+换行
					}
					if (j == 7 && i == index - 1)
						a = list1.GetItemText(i, j) + '\t';
					file.Write(a, a.GetLength() * 2);	//统计cstring类的长度
				}
			}
			save = true;
		}

	}
}


void CMFCApplication6Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!save)
	{
		if (MessageBox(L"信息还未保存！是否退出？", L"提示!", MB_YESNO)==IDNO)
		{
			return;
		}	
	}
	CDialogEx::OnClose();
}


BOOL CMFCApplication6Dlg::DestroyWindow()
{
	return CDialogEx::DestroyWindow();
}

void CMFCApplication6Dlg::Onnweopen()
{
	// TODO: 在此添加命令处理程序代码
	CString strFile;	//用来获取系统路径的(用来记录)
	strFile = "(*.txt)|所有文件(*.*)||";
	CFileDialog dlg(TRUE, NULL, _T(" "), OFN_HIDEREADONLY 
		| OFN_OVERWRITEPROMPT, _T("(*.txt)|*.txt|All Files(*.*)|*.*||"), AfxGetMainWnd());
	//打开文本文件
	dlg.DoModal();	//打开系统对话框
	strFile = dlg.GetPathName();	//获取路径
	CStdioFile in(strFile, CFile::modeRead);	///按照路径打开文件
	list1.DeleteAllItems();	//清除行 //把控件里已有的数据清除
	TCHAR* a = new TCHAR; //tchar相当于任意类型的
	CString z;	//标注一下这个没有标记的东西，别忘了，这是个cstring
	int i = 0, j = 0;
	list1.InsertItem(i, L"");
	while (in.Read(a, 2))	//读
	{
		if (*a != '\t')
			z += *a;
		else if (*a == '\t')
		{
			list1.SetItemText(i, j++, z); z = L"";
		}
		if (j == 8)
		{
			list1.InsertItem(++i, L"");
			j = 0;
		}
	}
	list1.DeleteItem(list1.GetItemCount() - 1);
}

void CMFCApplication6Dlg::OnBnClickedButton8()
{
	CFile in(L"E://学生成绩记录.txt", CFile::modeRead);
	list1.DeleteAllItems();		//删除每行数据
	TCHAR*a = new TCHAR;  //tchar相当于任意类型的
	CString z;	
	int i = 0, j = 0;
	list1.InsertItem(i, L"");
	while (in.Read(a, 2))	//
	{
		if (*a != '\t')
			z += *a;
		else if (*a == '\t')
		{
			list1.SetItemText(i, j++, z); z = L"";
		}
		if (j == 8)
		{
			list1.InsertItem(++i, L"");
			j = 0;
		}
	}
	list1.DeleteItem(list1.GetItemCount()-1);

}
BOOL CMFCApplication6Dlg::PreTranslateMessage(MSG* pMsg)	//屏蔽回车响应
{

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;	//esc键
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;	//回车
	else
		return CDialog::PreTranslateMessage(pMsg);
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == ID_ACCELERATOR32786)
	{

		OnBnClickedButton7();
		return TRUE;
	}
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{

		HACCEL ihAccel = ihAccel;

		if (ihAccel && ::TranslateAccelerator(GetSafeHwnd(), ihAccel, pMsg))

			return TRUE;
	}

}

void CMFCApplication6Dlg::OnMUEMsave()
{
	// TODO: 在此添加命令处理程序代码
	CFile s(L"E://学生成绩记录.txt", CFile::modeCreate | CFile::modeReadWrite);
	//如果文件不存在，请创建一个新文件。 如果该文件已存在，它是被覆盖，并最初设置为长度为零。
	//以读写方式打开文件
	int index = list1.GetItemCount();
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CString a;
			if (j != 7)
				a = list1.GetItemText(i, j) + '\t';
			if (j == 7 && i != index - 1)
			{
				a = list1.GetItemText(i, j) + '\t';	//回退一格
				a += "\r\n";	//回车+换行
			}
			if (j == 7 && i == index - 1)
				a = list1.GetItemText(i, j) + '\t';
			s.Write(a, a.GetLength() * 2);
		}
	}
	save = true;
}


void CMFCApplication6Dlg::OnMuemOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFile in(L"E://学生成绩记录.txt", CFile::modeRead);
	list1.DeleteAllItems();	//清除所有东西
	TCHAR* a = new TCHAR;
	CString z;
	int i = 0, j = 0;
	list1.InsertItem(i, L"");
	while (in.Read(a, 2))
	{
		if (*a != '\t')
			z += *a;
		else if (*a == '\t')
		{
			list1.SetItemText(i, j++, z); z = L"";	//从文件到控件
		}
		if (j == 8)
		{
			list1.InsertItem(++i, L"");
			j = 0;
		}
	}
	list1.DeleteItem(list1.GetItemCount() - 1);
}

void CMFCApplication6Dlg::OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult)	//更改
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int nIndex = list1.GetSelectionMark();	//选中行、
	//获取索引指定内容
	CString name = list1.GetItemText(nIndex, 0);
	CString number = list1.GetItemText(nIndex, 1);
	CString sex = list1.GetItemText(nIndex, 2);
	CString YW = list1.GetItemText(nIndex, 3);
	CString SX = list1.GetItemText(nIndex, 4);
	CString YY = list1.GetItemText(nIndex, 5);
	Vmain_name = name;	//把获得的内容传到编辑框
	Vmain_number = number;
	Vmain_sex = sex;
	Vmain_YW = YW;
	Vmain_SX = SX;
	Vmain_YY = YY;
	UpdateData(FALSE);			//变量更新到编辑框
}

void CMFCApplication6Dlg::OnBnClickedButtonMainchange()
{
	// TODO: 在此添加控件通知处理程序代码

	if (MessageBox(L"确定修改吗！", L"提示", MB_YESNO) == IDNO)	//消息弹出框，点击“否”则退出
			return;
	else//如果点击"是"则进行程序
	{
		UpdateData(TRUE);	//编辑框到变量
		int nIndex = list1.GetSelectionMark();//获取整行
		list1.SetItemText(nIndex, 0, Vmain_name);	//设置字符到编辑框
		list1.SetItemText(nIndex, 1, Vmain_number);
		list1.SetItemText(nIndex, 2, Vmain_sex);
		list1.SetItemText(nIndex, 3, Vmain_YW);
		list1.SetItemText(nIndex, 4, Vmain_SX);
		list1.SetItemText(nIndex, 5, Vmain_YY);
		float yw = _ttoi(Vmain_YW);			//cstring转float
		float sx = _ttoi(Vmain_SX);
		float yy = _ttoi(Vmain_YY);
		float sum = yw + sx + yy;			//用来计算
		Vmain_summ.Format(_T("%f"), sum);	//float转cstring
		list1.SetItemText(nIndex, 6, Vmain_summ);
		float aver = sum / 3.0;
		Vmain_average.Format(_T("%f"), aver);
		list1.SetItemText(nIndex, 7, Vmain_average);
	}
}

int count1;
void CMFCApplication6Dlg::OnBnClickedButton4()	//指向下一条（有点Bug暂时没修复）所以暂时隐藏起来了
{
	// TODO: 在此添加控件通知处理程序代码{}
	int index = list1.GetItemCount();
	if (count1 < index-1)
	{
		rigth_move.EnableWindow(1);
		for (int i = 0; i < index; i++)//初始化各行信息的选择状态，设置为未选择。
		{
			list1.SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
		}
		count1 += 1;
		CString name, number, sex, YW, SX, YY;
		name = list1.GetItemText(count1, 0); number = list1.GetItemText(count1, 1); sex = list1.GetItemText(count1, 2);
		YW = list1.GetItemText(count1, 3); SX = list1.GetItemText(count1, 4); YY = list1.GetItemText(count1, 5);
		Vmain_name = name; Vmain_number = number; Vmain_sex = sex; Vmain_YW = YW; Vmain_SX = SX; Vmain_YY = YY;
		list1.SetFocus();
		list1.SetItemState(count1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		UpdateData(false);
	}
	else
	{
		MessageBox(L"已经指向最后一条记录", L"浏览记录");
		//rigth_move.EnableWindow(0);
	}
}



void CMFCApplication6Dlg::OnBnClickedButton5()//指向上一条（有点Bug暂时没修复）所以暂时隐藏起来了
{
	// TODO: 在此添加控件通知处理程序代码
	int index = list1.GetItemCount();	//列表一共有多少了列
	if (count1 > 1)
	{
		rigth_move.EnableWindow(1);
		for (int i = 0; i < index; i++)//初始化各行信息的选择状态，设置为未选择。
		{
			list1.SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
		}
		count1 -= 1;
		CString name, number, sex, YW, SX, YY;
		name = list1.GetItemText(count1, 0); number = list1.GetItemText(count1, 1); sex = list1.GetItemText(count1, 2);
		YW = list1.GetItemText(count1, 3); SX = list1.GetItemText(count1, 4); YY = list1.GetItemText(count1, 5);
		Vmain_name = name; Vmain_number = number; Vmain_sex = sex; Vmain_YW = YW; Vmain_SX = SX; Vmain_YY = YY;
		list1.SetFocus();
		list1.SetItemState(count1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		UpdateData(false);
	}
	else
	{
		MessageBox(L"已经指向第一条记录", L"浏览记录");
		//rigth_move.EnableWindow(0);
	}
}

void CMFCApplication6Dlg::OnThing()
{
	// TODO: 
	int a = list1.GetItemCount();
	CString number_of_things;
	number_of_things.Format(_T("%d"), a);//inVec是double类型的值
	MessageBox(number_of_things, L"数值统计");
}

void CMFCApplication6Dlg::OnBnClickedButton6()
{
	//TODO: 在此添加控件通知处理程序代码
	int index = list1.GetItemCount();
	double  y_yw[100];
	double  y_sx[100];
	double  y_yy[100];
	double  x[100];

	for (int i = 0; i < 100; i++)
	{
		double SX; double num; double YY; double YW;
		SX = _ttoi(list1.GetItemText(i, 4));			//cstring转float
		num = _ttoi(list1.GetItemText(i, 1));			//cstring转float
		YW = _ttoi(list1.GetItemText(i, 3));
		YY = _ttoi(list1.GetItemText(i, 5));
		y_sx[i] = SX;
		y_yw[i] = YW;
		y_yy[i] = YY;
		x[i] = num;	//输出学号
	}
	CChartLineSerie* pLineSerie1;
	CChartLineSerie* pLineSerie2;
	CChartLineSerie* pLineSerie3;
	m_chartctrl.RemoveAllSeries();//先清空
	pLineSerie1 = m_chartctrl.CreateLineSerie();
	pLineSerie1->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie1->SetColor(RGB(244, 96, 108));//颜色
	pLineSerie1->SetWidth(3);//设置线的宽度
	pLineSerie1->SetName(_T("数学"));//设置曲线名
	pLineSerie1->AddPoints(x, y_sx, 100);
	pLineSerie2 = m_chartctrl.CreateLineSerie();
	pLineSerie2->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie2->SetColor(RGB(190, 237, 119));//颜色
	pLineSerie2->SetWidth(3);
	pLineSerie2->SetName(_T("语文"));//设置曲线名
	pLineSerie2->AddPoints(x, y_yw, 100);
	pLineSerie3 = m_chartctrl.CreateLineSerie();
	pLineSerie3->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie3->AddPoints(x, y_yy, 100);
	pLineSerie3->SetColor(RGB(209, 186, 116));//颜色
	pLineSerie3->SetWidth(3);//设置线的宽度
	pLineSerie3->SetName(_T("英语 "));//设置曲线名
	m_chartctrl.GetLegend()->SetVisible(true);//设置曲线名可见，不加这一句不显示曲线名
	m_chartctrl.EnableRefresh(true);
}


void CMFCApplication6Dlg::OnBnClickedButton9()
{
//	// TODO: 在此添加控件通知处理程序代码

	m_chartctr2.RemoveAllSeries();//先清空
	CChartBarSerie* pBarSeries1 = m_chartctr2.CreateBarSerie();	//第一个柱子
	pBarSeries1->SetColor(RGB(25, 202, 173));			//柱子颜色
	pBarSeries1->SetName(_T("平均分"));
	CChartBarSerie* pBarSeries2 = m_chartctr2.CreateBarSerie();//第二个柱子
	pBarSeries2->SetColor(RGB(68, 68, 255));		//线的颜色
	pBarSeries2->SetGradient(RGB(214, 213, 183), gtVerticalDouble);//花里胡哨的渐变背景色
	pBarSeries2->SetName(_T("总成绩"));
	pBarSeries2->SetBorderColor(RGB(0, 0, 255));	//设置柱状图颜色
	pBarSeries2->SetBorderWidth(1);					//柱子宽度
	double  y_average[100];	//平均数
	double  y_sum[100];	//总数
	double x[100];
	for (int i = 0; i < 100; i++)
	{
		
		double average; double sum; double num;//平均值，总数
		average = _ttoi(list1.GetItemText(i, 7));			//cstring转float
		sum = _ttoi(list1.GetItemText(i, 6));			//cstring转float
		num = _ttoi(list1.GetItemText(i, 1));
		y_average[i] = average;
		y_sum[i] = sum;
		x[i] = num;	
		pBarSeries1->AddPoint(x[i], y_average[i]);
		pBarSeries2->AddPoint(x[i], y_sum[i]);
	}
	m_chartctr2.EnableRefresh(true);

}
DWORD select_line;//选择列
bool ASC = FALSE;//是否升序
bool method; // 记录比较方法
static int CALLBACK CompareFunc(LPARAM  select_line1, LPARAM  select_line2, LPARAM  Sort);
void CMFCApplication6Dlg::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

		select_line = pNMLV->iSubItem;//点击的列
		int count = list1.GetItemCount();
		for (int i = 0; i < count; i++)
			list1.SetItemData(i, i); //每行的比较关键字，此处为列序号（点击的列号），可以设置为其他比较函数的第一二个参数
		list1.SortItems(CompareFunc, (DWORD_PTR)&list1); // 排序第二个参数是比较函数的第三个参数
		method = !method;
		*pResult = 0;
}
static int CALLBACK CompareFunc(LPARAM  select_line1, LPARAM  select_line2, LPARAM  Sort)
{

	USES_CONVERSION;
	int row1 = (int)select_line1;
	int row2 = (int)select_line2;

	CListCtrl* lc = (CListCtrl*)Sort;

	CString lp1 = lc->GetItemText(row1, select_line);
	CString lp2 = lc->GetItemText(row2, select_line);

	if (select_line != (0||2))	//只有名字和性别那列是无序排列
	{
		if (method)
			return lp1.CompareNoCase(lp2);
		else
			return lp2.CompareNoCase(lp1);

	}
	else           //float类型的比较
	{
		if (method)
			return _ttof(lp1) - _ttof(lp2);
		else
			return _ttof(lp2) - _ttof(lp1);
	}
	return 0;
}


void CMFCApplication6Dlg::Onlinechart()
{
	// TODO: 在此添加命令处理程序代码
	CFile s(L"E://学生成绩记录.txt", CFile::modeCreate | CFile::modeReadWrite);
	//如果文件不存在，请创建一个新文件。 如果该文件已存在，它是被覆盖，并最初设置为长度为零。
	//以读写方式打开文件
	int index = list1.GetItemCount();
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CString a;
			if (j != 7)
				a = list1.GetItemText(i, j) + '\t';
			if (j == 7 && i != index - 1)
			{
				a = list1.GetItemText(i, j) + '\t';	//回退一格方便对齐
				a += "\r\n";	//回车+换行
			}
			if (j == 7 && i == index - 1)
				a = list1.GetItemText(i, j) + '\t';
			s.Write(a, a.GetLength() * 2);
		}
	}
	save = true;
	LineChart dlg_login;    //建立登陆对话框对象
	dlg_login.DoModal();   //弹出登陆对话框
}


void CMFCApplication6Dlg::OnBarchart()
{
	// TODO: 在此添加命令处理程序代码

	BarChart dlg_login;    //建立登陆对话框对象
	dlg_login.DoModal();   //弹出登陆对话框
}


void CMFCApplication6Dlg::Ontwochart()
{
	// TODO: 在此添加命令处理程序代码
	TwoChart two_dlg;
	two_dlg.DoModal();
}

static UINT indicators[] = { ID_STATUSBAR_0,ID_STATUSBAR_1 };
void CMFCApplication6Dlg::InitStatus()
{
	m_bar.Create(this);
	m_bar.SetIndicators(indicators, 3);
	GetClientRect(&rect);
	CString str1;
	t1 = CTime::GetCurrentTime();
	str1 = t1.Format("%Y年%m月%d日 %H:%M:%S");
	m_bar.SetPaneInfo(0, ID_STATUSBAR_0, SBPS_POPOUT, rect.Width() / 3);
	m_bar.SetPaneInfo(0, ID_STATUSBAR_1, SBPS_POPOUT, rect.Width() - 500);
	//第三列显示时间
	m_bar.SetPaneText(2, str1, 1);
	//启动定时器SetTimer(ID,间隔时间，窗口句柄)
	SetTimer(1, 1000, NULL);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, AFX_IDW_CONTROLBAR_FIRST);
}
void CMFCApplication6Dlg::ShowtimeNow()
{
	//初始化状态栏，将状态栏设置为三列，前两列固定显示内容，第三列实时显示时间
	CString str1;
	t1 = CTime::GetCurrentTime();
	str1 = t1.Format("%Y年%m月%d日 %H:%M:%S");
	m_bar.SetPaneText(2, str1, 1);// 设置状态栏的窗格文本
}

void CMFCApplication6Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		ShowtimeNow();       //反复调用这个函数，进行时间显示刷新
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication6Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	CDC* pDC = GetDC();//CDC类定义的是设备上下文对象的类，CDC对象的成员函数进行所有的绘图。
	s.Format(_T("X = %d,y=%d"), point.x, point.y);//unicode环境下
	m_bar.SetPaneText(0, s);
	ReleaseDC(pDC);
	CDialogEx::OnMouseMove(nFlags, point);
}
