#pragma once
#include "afxdialogex.h"
#include "ChartCtrl\ChartLineSerie.h"
#include "ChartCtrl\ChartTitle.h"  //标题头文件


// LineChart 对话框

class LineChart : public CDialogEx
{
	DECLARE_DYNAMIC(LineChart)

public:
	LineChart(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LineChart();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = foldline };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CChartCtrl m_linechart;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
