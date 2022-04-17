#pragma once
#include "afxdialogex.h"
#include "ChartCtrl\ChartTitle.h"  //标题头文件
#include "ChartCtrl/ChartStandardAxis.h"
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartLineSerie.h"
#include "ChartCtrl/ChartTitle.h"  //标题头文件
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"



// BarChart 对话框

class BarChart : public CDialogEx
{
	DECLARE_DYNAMIC(BarChart)

public:
	BarChart(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BarChart();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = barchat };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CChartCtrl m_BarChart1;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
