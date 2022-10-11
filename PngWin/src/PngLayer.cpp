#include "stdafx.h"
#include "PngLayer.h"
#include "CtrlsLayer.h"

CPngLayer::CPngLayer(CCtrlsLayer *pCtrlsLayer, CWnd* pParent/* = NULL*/)
: CDialogEx(pCtrlsLayer->getTemplateId(), pParent)
, m_pCtrlsLayer(pCtrlsLayer)
, m_pImage(NULL)
{
}

CPngLayer::~CPngLayer()
{
	if (NULL != m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
}

void CPngLayer::DoDataExchange(CDataExchange* pDX)
{
	//CDialogEx::DoDataExchange(pDX);// png layer does not need add DDX DDV
}

BOOL CPngLayer::OnInitDialog()
{
	BOOL bRet = CDialogEx::OnInitDialog();
	if (TRUE == bRet && NULL != m_pImage)
	{
		//��ʼ��GDI+.
		m_Blend.BlendOp				= 0; //theonlyBlendOpdefinedinWindows2000
		m_Blend.BlendFlags			= 0; //nothingelseisspecial...
		m_Blend.AlphaFormat			= 1; //...
		m_Blend.SourceConstantAlpha = 255;//AC_SRC_ALPHA

		//������ʽΪ0x80000Ϊ�㼶����
		DWORD dwExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, dwExStyle ^ 0x80000);

		//Gdiplus::Image image(L"d:\\1.png", TRUE);			//GDI+�е���
		int nWidth = m_pImage->GetWidth();
		int nHeight = m_pImage->GetHeight();

		//�����ڴ�λͼ
		HDC hdcTemp = GetDC()->m_hDC;
		m_hdcMemory = CreateCompatibleDC(hdcTemp);
		HBITMAP hBitMap = CreateCompatibleBitmap(hdcTemp, nWidth, nHeight);
		SelectObject(m_hdcMemory, hBitMap);

		//ʹ��GDI+����PNGͼƬ
		HDC hdcScreen = ::GetDC(m_hWnd);
		RECT rct;
		GetWindowRect(&rct);
		POINT ptWinPos = { rct.left, rct.top };
		Gdiplus::Graphics graph(m_hdcMemory);				//GDI+�е���
		graph.DrawImage(m_pImage, 0, 0, nWidth, nHeight);	//������������Ҫ���óɸ�ͼƬһ����С�������ʧ��

		//ʹ��UpdateLayerWindow���д���͸������
		HMODULE hFuncInst = LoadLibraryA("User32.DLL");
		typedef BOOL(WINAPI *MYFUNC)(HWND, HDC, POINT*, SIZE*, HDC, POINT*, COLORREF, BLENDFUNCTION*, DWORD);
		MYFUNC UpdateLayeredWindow;
		UpdateLayeredWindow = (MYFUNC)GetProcAddress(hFuncInst, "UpdateLayeredWindow");
		SIZE sizeWindow = { nWidth, nHeight };
		POINT ptSrc = { 0, 0 };
		UpdateLayeredWindow(m_hWnd, hdcScreen, &ptWinPos, &sizeWindow, m_hdcMemory, &ptSrc, 0, &m_Blend, 2);
	}

	return bRet;
}


BEGIN_MESSAGE_MAP(CPngLayer, CDialogEx)
	//{{AFX_MSG_MAP(CPngLayer)
	ON_WM_CREATE()
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CPngLayer::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	//�����Ӵ���
	//m_pCtrlsLayer = new CCtrlsLayer(CCtrlsLayer::IDD, this);
	m_pCtrlsLayer->Create(m_pCtrlsLayer->getTemplateId(), this);

	if (NULL != m_pImage)
	{
		ModifyStyle(WS_CAPTION, 0);				// ȥ��������  
		ModifyStyleEx(WS_EX_DLGMODALFRAME, 0);	// ȥ���߿� 
		ModifyStyle(WS_THICKFRAME, 0);			// ȥ��Resize��

		m_pCtrlsLayer->ModifyStyle(WS_CAPTION, 0);				// ȥ��������  
		m_pCtrlsLayer->ModifyStyleEx(WS_EX_DLGMODALFRAME, 0);	// ȥ���߿�  
		m_pCtrlsLayer->ModifyStyle(WS_THICKFRAME, 0);			// ȥ��Resize��
	}

	m_pCtrlsLayer->ShowWindow(SW_SHOW);

	return 0;
}

void CPngLayer::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
	// TODO: Add your message handler code here
	if (::IsWindow(m_pCtrlsLayer->m_hWnd))
	{
		CRect rcWindow;
		GetWindowRect(rcWindow);
		m_pCtrlsLayer->MoveWindow(&rcWindow);
	}
}

void CPngLayer::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ֹ��ʾ�ƶ����δ����
	::SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
	//�Ǳ������ƶ���������
	SendMessage(WM_SYSCOMMAND, 0xF012, 0);
	// PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));

	CDialogEx::OnLButtonDown(nFlags, point);
}

BOOL CPngLayer::loadFromFile(const WCHAR *pFile)
{
	Gdiplus::Image *pImage = Gdiplus::Image::FromFile(pFile);
	if (NULL == pImage)
		return FALSE;
	if (NULL != m_pImage)
		delete m_pImage;
	m_pImage = pImage;
	return TRUE;
}

BOOL CPngLayer::loadFromResource(INT nID, const WCHAR *sType, HINSTANCE hInst/* = AfxGetResourceHandle()*/)
{
	HRSRC hRsrc = ::FindResourceW(hInst, MAKEINTRESOURCEW(nID), sType); // type
	if (NULL == hRsrc)
		return FALSE;
	// load resource into memory
	DWORD len = SizeofResource(hInst, hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(hInst, hRsrc);
	if (NULL == lpRsrc)
		return FALSE;
	// Allocate global memory on which to create stream
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem, lpRsrc, len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem, FALSE, &pstm);
	// load from stream
	m_pImage = Gdiplus::Image::FromStream(pstm);
	// free/release stuff
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);

	return TRUE;
}
