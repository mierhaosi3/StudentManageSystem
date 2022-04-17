#pragma once
#include "afxdialogex.h"
#include "ChartCtrl/ChartAxis.h"
#include "ChartCtrl\ChartTitle.h"  //标题头文件
#include "ChartCtrl/ChartStandardAxis.h"
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartLineSerie.h"
#include "ChartCtrl/ChartTitle.h"  //标题头文件
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartBarSerie.h"
#include "ChartCtrl\ChartAxisLabel.h"

// TwoChart 对话框
#define MESSAGE_UPDATEPOS WM_USER+1001

class TwoChart : public CDialogEx
{
	DECLARE_DYNAMIC(TwoChart)

public:
	TwoChart(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TwoChart();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = two };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CChartCtrl TwoChart1;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
