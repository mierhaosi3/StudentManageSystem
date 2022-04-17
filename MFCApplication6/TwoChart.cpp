// TwoChart.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "afxdialogex.h"
#include "TwoChart.h"
#include "ChartCtrl/ChartAxis.h"
#include "ChartCtrl\ChartTitle.h"  //标题头文件
#include "ChartCtrl/ChartStandardAxis.h"
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartLineSerie.h"
#include "ChartCtrl/ChartTitle.h"  //标题头文件
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"
#include "MFCApplication6Dlg.h"


// TwoChart 对话框

IMPLEMENT_DYNAMIC(TwoChart, CDialogEx)

TwoChart::TwoChart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(two, pParent)
{

}

TwoChart::~TwoChart()
{
}

void TwoChart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM9, TwoChart1);
}


BEGIN_MESSAGE_MAP(TwoChart, CDialogEx)
END_MESSAGE_MAP()


// TwoChart 消息处理程序


BOOL TwoChart::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMFCApplication6Dlg* parent;
	parent = (CMFCApplication6Dlg*)theApp.m_pMainWnd;
	CChartStandardAxis* line_pBottomAxis =
		TwoChart1.CreateStandardAxis(CChartCtrl::BottomAxis);	//绘制坐标轴
	line_pBottomAxis->SetMinMax(0, 20);	//暂时只用得到20
	CChartStandardAxis* line_pLeftAxis =
		TwoChart1.CreateStandardAxis(CChartCtrl::LeftAxis);
	CChartAxis* line_pAxis1;
	CChartAxisLabel* line_pLabel;
	CString str1;
	line_pLeftAxis->SetMinMax(0, 300);
	line_pBottomAxis->SetTickIncrement(false, 1.0);	//间距设为1
	line_pLeftAxis->SetDiscrete(true);
	CChartLineSerie* pSeries = TwoChart1.CreateLineSerie();
	TwoChart1.GetBottomAxis()->GetLabel()->SetText(L"学号");
	TwoChart1.GetLeftAxis()->GetLabel()->SetText(L"成绩");
	TwoChart1.SetBackGradient(RGB(255, 255, 255), (RGB(252, 230, 201)), gtVertical);//花里胡哨的背景
	TwoChart1.EnableRefresh(false);
	TwoChart1.GetLegend()->SetVisible(true);			//分类图
	TwoChart1.GetLegend()->SetHorizontalMode(true);
	TwoChart1.GetLegend()->UndockLegend(1000, 800);
	int index = parent->list1.GetItemCount();
	double  y_yw[100];
	double  y_sx[100];
	double  y_yy[100];
	double  x[100];

	for (int i = 0; i < 100; i++)
	{
		double SX; double num; double YY; double YW;
		SX = _ttoi(parent->list1.GetItemText(i, 4));			//cstring转float
		num = _ttoi(parent->list1.GetItemText(i, 1));			//cstring转float
		YW = _ttoi(parent->list1.GetItemText(i, 3));
		YY = _ttoi(parent->list1.GetItemText(i, 5));
		y_sx[i] = SX;
		y_yw[i] = YW;
		y_yy[i] = YY;
		x[i] = num;	//输出学号
	}
	CChartLineSerie* two_pLineSerie1;
	CChartLineSerie* two_pLineSerie2;
	CChartLineSerie* two_pLineSerie3;
	CChartBarSerie* pBarSeries1 = TwoChart1.CreateBarSerie();	//第一个柱子
	pBarSeries1->SetColor(RGB(25, 202, 173));			//柱子颜色
	pBarSeries1->SetName(_T("平均分"));
	CChartBarSerie* pBarSeries2 = TwoChart1.CreateBarSerie();//第二个柱子
	pBarSeries2->SetColor(RGB(68, 68, 255));		//线的颜色
	pBarSeries2->SetGradient(RGB(214, 213, 183), gtVerticalDouble);//花里胡哨的渐变背景色
	pBarSeries2->SetName(_T("总成绩"));
	pBarSeries2->SetBorderColor(RGB(0, 0, 255));	//设置柱状图颜色
	pBarSeries2->SetBorderWidth(1);					//柱子宽度
	double  y_average[100];	//平均数
	double  y_sum[100];	//总数
	double x2[100];
	for (int i = 0; i < 100; i++)
	{

		double average; double sum; double num;//平均值，总数
		average = _ttoi(parent->list1.GetItemText(i, 7));			//cstring转float
		sum = _ttoi(parent->list1.GetItemText(i, 6));			//cstring转float
		num = _ttoi(parent->list1.GetItemText(i, 1));
		y_average[i] = average;
		y_sum[i] = sum;
		x2[i] = num;
		pBarSeries1->AddPoint(x2[i], y_average[i]);
		pBarSeries2->AddPoint(x2[i], y_sum[i]);
	}
	TwoChart1.EnableRefresh(true);
	two_pLineSerie1 = TwoChart1.CreateLineSerie();
	two_pLineSerie1->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	two_pLineSerie1->SetColor(RGB(244, 96, 108));//颜色
	two_pLineSerie1->SetWidth(3);//设置线的宽度
	two_pLineSerie1->SetName(_T("数学"));//设置曲线名
	two_pLineSerie1->AddPoints(x, y_sx, 100);
	two_pLineSerie2 = TwoChart1.CreateLineSerie();
	two_pLineSerie2->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	two_pLineSerie2->SetColor(RGB(190, 237, 119));//颜色
	two_pLineSerie2->SetWidth(3);
	two_pLineSerie2->SetName(_T("语文"));//设置曲线名
	two_pLineSerie2->AddPoints(x, y_yw, 100);
	two_pLineSerie3 = TwoChart1.CreateLineSerie();
	two_pLineSerie3->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	two_pLineSerie3->AddPoints(x, y_yy, 100);
	two_pLineSerie3->SetColor(RGB(209, 186, 116));//颜色
	two_pLineSerie3->SetWidth(3);//设置线的宽度
	two_pLineSerie3->SetName(_T("英语 "));//设置曲线名
	TwoChart1.GetLegend()->SetVisible(true);//设置曲线名可见，不加这一句不显示曲线名
	TwoChart1.EnableRefresh(true);
	CChartCrossHairCursor* pCrossHair =
		TwoChart1.CreateCrossHairCursor();
	CChartDragLineCursor* pDragLine =
		TwoChart1.CreateDragLineCursor(CChartCtrl::BottomAxis);
	TwoChart1.ShowMouseCursor(false); 
	//用于创建与底部和左侧轴相关联的十字准线光标,以及与底部轴相关联的“拉线”光标：

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



BOOL TwoChart::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;	//esc键
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;	//回车
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
