#include"ChartCtrl/ChartCtrl.h"
#include "ChartCtrl\ChartLineSerie.h"
// MFCApplication6Dlg.h: 头文件
//
#include "ChartCtrl\ChartTitle.h"  //标题头文件
#pragma once



// CMFCApplication6Dlg 对话框
class CMFCApplication6Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication6Dlg(CWnd* pParent = nullptr);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list1;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCloseupCombo1();
	void sort(int col);
	CComboBox box;
	afx_msg void OnBnClickedButton1();
	CEdit Fname;
	CEdit Fnumber;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton7();
	bool save = false;
	afx_msg void OnClose();
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButton8();
	BOOL PreTranslateMessage(MSG* pMsg);
	void OnMUEMsave();
	CString edit_name;
	CString edit_num;
	CFont m_oFont;												//用来调节文字大小
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CMenu* pMenu;
	afx_msg void OnMuemOpen();
	//void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	CButton M_change;
	CEdit Main_name;
	CEdit Main_number;
	CEdit Main_sex;
	CEdit Main_YW;
	CEdit Main_SX;
	CEdit Main_YY;
	CString Vmain_name;
	CString Vmain_number;
	CString Vmain_sex;
	CString Vmain_YW;
	CString Vmain_SX;
	CString Vmain_YY;
	afx_msg void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonMainchange();
	CString Vmain_average;
	CString Vmain_summ;
	afx_msg void Onnewhold();
	afx_msg void Onnweopen();
	CButton m_fold_line;
	CButton m_historgram;
	CButton m_view;
	afx_msg void OnBnClickedButton4();
	CButton rigth_move;
	CButton left_move;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnThing();
	CChartCtrl m_chartctrl;
	afx_msg void OnBnClickedButton6();
	CChartCtrl m_chartctr2;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onlinechart();
	afx_msg void OnBarchart();
	afx_msg void Ontwochart();
	CTime t1;//实例化一个时间类，用于保存获取的系统时间。
	void ShowtimeNow();//定时器调用的刷新函数，将实时获取的系统时间反复写入。
	void InitStatus();//初始化状态栏，此函数中将状态栏的显示进行初始化。
	CStatusBar m_bar;//创建一个状态栏实例。
	CRect rect; //实例一个Rect，这个东西后面对状态栏进行等分宽度用。
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
