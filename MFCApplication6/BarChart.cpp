// BarChart.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "afxdialogex.h"
#include "BarChart.h"
#include "ChartCtrl/ChartStandardAxis.h"
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartLineSerie.h"
#include "ChartCtrl/ChartTitle.h"  //标题头文件
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"
#include "MFCApplication6Dlg.h"



// BarChart 对话框

IMPLEMENT_DYNAMIC(BarChart, CDialogEx)

BarChart::BarChart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(barchat, pParent)
{

}

BarChart::~BarChart()
{
}

void BarChart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM8, m_BarChart1);
}


BEGIN_MESSAGE_MAP(BarChart, CDialogEx)
END_MESSAGE_MAP()


// BarChart 消息处理程序


BOOL BarChart::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMFCApplication6Dlg* barparent;
	barparent = (CMFCApplication6Dlg*)theApp.m_pMainWnd;
	CChartStandardAxis* Bar_pBottomAxis_z = m_BarChart1.CreateStandardAxis(CChartCtrl::BottomAxis);	//绘制坐标轴(x)
	Bar_pBottomAxis_z->SetMinMax(0, 20);	//一共有0到20
	Bar_pBottomAxis_z->SetDiscrete(true);
	CChartStandardAxis* Bar_pLeftAxis_z = m_BarChart1.CreateStandardAxis(CChartCtrl::LeftAxis);//y轴
	Bar_pLeftAxis_z->SetMinMax(0, 400);
	Bar_pLeftAxis_z->GetLabel()->SetText(_T("成绩"));
	m_BarChart1.GetBottomAxis()->GetLabel()->SetText(L"学号");
	m_BarChart1.GetTitle()->AddString(_T("柱状图"));	//设置柱状图的表头
	CChartFont titleFont;
	titleFont.SetFont(_T("Arial Black"), 120, true, false, true);	//设置标题字体
	m_BarChart1.GetTitle()->SetFont(titleFont);
	m_BarChart1.GetTitle()->SetColor(RGB(0, 0, 128));
	m_BarChart1.SetBackGradient(RGB(255, 255, 255), RGB(255, 127, 80), gtVertical);	//花里胡哨背景色
	m_BarChart1.EnableRefresh(false);
	m_BarChart1.GetLegend()->SetVisible(true);
	m_BarChart1.GetLegend()->SetHorizontalMode(true);
	m_BarChart1.GetLegend()->UndockLegend(550, 10);
	m_BarChart1.RemoveAllSeries();//先清空
	CChartBarSerie* pBarSeries1 = m_BarChart1.CreateBarSerie();	//第一个柱子
	pBarSeries1->SetColor(RGB(25, 202, 173));			//柱子颜色
	pBarSeries1->SetName(_T("平均分"));
	CChartBarSerie* pBarSeries2 = m_BarChart1.CreateBarSerie();//第二个柱子
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
		average = _ttoi(barparent->list1.GetItemText(i, 7));			//cstring转float
		sum = _ttoi(barparent->list1.GetItemText(i, 6));			//cstring转float
		num = _ttoi(barparent->list1.GetItemText(i, 1));
		y_average[i] = average;
		y_sum[i] = sum;
		x[i] = num;
		pBarSeries1->AddPoint(x[i], y_average[i]);
		pBarSeries2->AddPoint(x[i], y_sum[i]);
	}
	m_BarChart1.EnableRefresh(true);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL BarChart::PreTranslateMessage(MSG* pMsg)
{

	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;	//esc键
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;	//回车
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
