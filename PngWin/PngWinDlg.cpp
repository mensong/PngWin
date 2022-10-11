
// PngWinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PngWin.h"
#include "PngWinDlg.h"
#include "afxdialogex.h"
#include "MyCtrlsLayer.h"
#include "src/PngLayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPngWinDlg �Ի���



CPngWinDlg::CPngWinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPngWinDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPngWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPngWinDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPngWinDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPngWinDlg ��Ϣ�������

BOOL CPngWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPngWinDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPngWinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPngWinDlg::OnBnClickedButton1()
{
	CMyCtrlsLayer *pCtrlsLayer = new CMyCtrlsLayer;
	CPngLayer pngDlg(pCtrlsLayer,NULL);
	//pngDlg.loadFromFile(L"d:\\1.png");
	pngDlg.loadFromResource(IDB_MAINWIN, L"PNG");
	pngDlg.DoModal();
	delete pCtrlsLayer;
	pCtrlsLayer = NULL;
}
