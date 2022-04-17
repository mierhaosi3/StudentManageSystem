// LineChart.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "afxdialogex.h"
#include "LineChart.h"
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"
#include "ChartCtrl/ChartCtrl.h"
#include "MFCApplication6Dlg.h"
#include "ChartCtrl\ChartLineSerie.h"



// LineChart 对话框
IMPLEMENT_DYNAMIC(LineChart, CDialogEx)

LineChart::LineChart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(foldline, pParent)
{
	const CMFCApplication6Dlg* parent;
	parent = (CMFCApplication6Dlg*)theApp.m_pMainWnd;
}

LineChart::~LineChart()
{
}

void LineChart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM7, m_linechart);
}


BEGIN_MESSAGE_MAP(LineChart, CDialogEx)
END_MESSAGE_MAP()


// LineChart 消息处理程序


BOOL LineChart::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMFCApplication6Dlg* parent;
	parent = (CMFCApplication6Dlg*)theApp.m_pMainWnd;
	CChartStandardAxis* line_pBottomAxis =
		m_linechart.CreateStandardAxis(CChartCtrl::BottomAxis);	//绘制坐标轴
	line_pBottomAxis->SetMinMax(0, 20);	//暂时只用得到20
	CChartStandardAxis* line_pLeftAxis =
		m_linechart.CreateStandardAxis(CChartCtrl::LeftAxis);
	CChartAxis* line_pAxis1;
	CChartAxisLabel* line_pLabel;
	CString str1;
	line_pLeftAxis->SetMinMax(0, 105);
	line_pBottomAxis->SetTickIncrement(false, 2.0);
	line_pLeftAxis->SetDiscrete(true);
	CChartLineSerie* pSeries = m_linechart.CreateLineSerie();
	m_linechart.GetBottomAxis()->GetLabel()->SetText(L"学号");
	m_linechart.GetLeftAxis()->GetLabel()->SetText(L"成绩");
	m_linechart.SetBackGradient(RGB(255, 255, 255), (RGB(252, 230, 201)), gtVertical);//花里胡哨的背景
	m_linechart.EnableRefresh(false);
	m_linechart.GetLegend()->SetVisible(true);			//分类图
	m_linechart.GetLegend()->SetHorizontalMode(true);
	m_linechart.GetLegend()->UndockLegend(650, 350);
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
	CChartLineSerie* pLineSerie1;
	CChartLineSerie* pLineSerie2;
	CChartLineSerie* pLineSerie3;
	m_linechart.RemoveAllSeries();//先清空
	pLineSerie1 = m_linechart.CreateLineSerie();
	pLineSerie1->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie1->SetColor(RGB(244, 96, 108));//颜色
	pLineSerie1->SetWidth(3);//设置线的宽度
	pLineSerie1->SetName(_T("数学"));//设置曲线名
	pLineSerie1->AddPoints(x, y_sx, 100);
	pLineSerie2 = m_linechart.CreateLineSerie();
	pLineSerie2->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie2->SetColor(RGB(190, 237, 119));//颜色
	pLineSerie2->SetWidth(3);
	pLineSerie2->SetName(_T("语文"));//设置曲线名
	pLineSerie2->AddPoints(x, y_yw, 100);
	pLineSerie3 = m_linechart.CreateLineSerie();
	pLineSerie3->SetSeriesOrdering(poXOrdering);//设置为以x递增顺序
	pLineSerie3->AddPoints(x, y_yy, 100);
	pLineSerie3->SetColor(RGB(209, 186, 116));//颜色
	pLineSerie3->SetWidth(3);//设置线的宽度
	pLineSerie3->SetName(_T("英语 "));//设置曲线名
	m_linechart.GetLegend()->SetVisible(true);//设置曲线名可见，不加这一句不显示曲线名
	m_linechart.EnableRefresh(true);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL LineChart::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;	//esc键
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;	//回车
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
