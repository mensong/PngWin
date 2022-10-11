#pragma once
#include <afxdialogex.h>

/*
 * 注意：使用之前先初始化GDI+
 *
 *  定义全局token
 *  ULONG_PTR g_diplusToken;
 *
 *  在程序初始化的地方
 *  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
 *  GdiplusStartup(&g_diplusToken, &gdiplusStartupInput, NULL);
 *
 *  在程序退出的地方
 *  Gdiplus::GdiplusShutdown(g_diplusToken);
 */

class CCtrlsLayer;
class CPngLayer
	: public CDialogEx
{
public:
	//pCtrlsLayer must not be NULL
	CPngLayer(CCtrlsLayer *pCtrlsLayer, CWnd* pParent = NULL);
	virtual ~CPngLayer();

public:
	BOOL loadFromFile(const WCHAR *pFile);
	BOOL loadFromResource(INT nID, const WCHAR *sType, HINSTANCE hInst = AfxGetResourceHandle());

protected:
	//{{AFX_VIRTUAL(CPngLayer)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPngLayer)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	Gdiplus::Image *m_pImage;
	BLENDFUNCTION m_Blend;
	HDC m_hdcMemory;

	CCtrlsLayer *m_pCtrlsLayer;	//子窗体
};
