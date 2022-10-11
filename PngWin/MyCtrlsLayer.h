#pragma once
#include "src/CtrlsLayer.h"


// CMyCtrlsLayer 对话框

class CMyCtrlsLayer : public CCtrlsLayer
{
	DECLARE_DYNAMIC(CMyCtrlsLayer)

public:
	CMyCtrlsLayer();   // 标准构造函数
	virtual ~CMyCtrlsLayer();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

protected:
	CBitmapButton 
		m_bt1, m_bt2, m_bt3, m_bt4, m_bt5, 
		m_bt6, m_bt7, m_bt8, m_bt9, m_bt10, 
		m_bt11, m_bt12, m_bt13, m_bt14, m_bt15, 
		m_bt16, m_bt17, m_bt18, m_bt19, m_bt20, 
		m_bt21, m_bt22, m_bt23, m_bt24, m_bt25, 
		m_bt26, m_bt27, m_bt28, m_bt29, m_bt30, 
		m_bt31, m_bt32;
	CBitmapButton m_min, m_close;
	CBitmapButton m_refresh;
	CBitmapButton m_return;
	CBitmapButton m_enter;

public:
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedMin();
};
