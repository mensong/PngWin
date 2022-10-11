#include "stdafx.h"
#include "CtrlsLayer.h"


CCtrlsLayer::CCtrlsLayer(UINT id)
: CDialogEx(id, NULL)
, m_nDlgId(id)
{
}

CCtrlsLayer::~CCtrlsLayer()
{
}

BOOL CCtrlsLayer::OnInitDialog()
{
	BOOL bRet = CDialogEx::OnInitDialog();
	if (TRUE == bRet)
	{
#define CLEAR_BK_COLOR RGB(255,0,255)	//�������ã���Щ��ɫ��ȫ��͸����
		m_brush.CreateSolidBrush(CLEAR_BK_COLOR);

		//SetWindowsLong����������Ϊ�㼶����
		DWORD dwExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, dwExStyle | 0x80000);

		//��SetLayeredWindowAttributes����͸��ɫΪ0������UpdateLayeredWindow��ʹ��Ҫ��Щ
		HMODULE hInst = LoadLibraryA("User32.DLL");
		typedef BOOL(WINAPI *MYFUNC)(HWND, COLORREF, BYTE, DWORD);
		MYFUNC SetLayeredWindowAttributes = NULL;
		SetLayeredWindowAttributes = (MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		SetLayeredWindowAttributes(this->GetSafeHwnd(), CLEAR_BK_COLOR, 0, 1);
		FreeLibrary(hInst);
	}

	return bRet;
}

void CCtrlsLayer::OnOK()
{
	HWND hWnd = GetParent()->m_hWnd;
	::SendMessage(hWnd, WM_CLOSE, 0, 0);

	CDialogEx::OnOK();
}

void CCtrlsLayer::OnCancel()
{
	HWND hWnd = GetParent()->m_hWnd;
	::SendMessage(hWnd, WM_CLOSE, 0, 0);

	CDialogEx::OnCancel();
}


BEGIN_MESSAGE_MAP(CCtrlsLayer, CDialogEx)
	//{{AFX_MSG_MAP(COnWindow)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HBRUSH CCtrlsLayer::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO: Change any attributes of the DC here
	if (nCtlColor = CTLCOLOR_DLG)
		return m_brush;
	return  CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}

LRESULT CCtrlsLayer::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_DESTROY)
	{
		HWND hWnd = GetParent()->m_hWnd;
		::SendMessage(hWnd, WM_CLOSE, 0, 0);
	}

	return CDialogEx::DefWindowProc(message, wParam, lParam);
}
