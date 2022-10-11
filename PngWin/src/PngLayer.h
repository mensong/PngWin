#pragma once
#include <afxdialogex.h>

/*
 * ע�⣺ʹ��֮ǰ�ȳ�ʼ��GDI+
 *
 *  ����ȫ��token
 *  ULONG_PTR g_diplusToken;
 *
 *  �ڳ����ʼ���ĵط�
 *  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
 *  GdiplusStartup(&g_diplusToken, &gdiplusStartupInput, NULL);
 *
 *  �ڳ����˳��ĵط�
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

	CCtrlsLayer *m_pCtrlsLayer;	//�Ӵ���
};
