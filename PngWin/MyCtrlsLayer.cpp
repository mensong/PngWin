// MyCtrlsLayer.cpp : 实现文件
//

#include "stdafx.h"
#include "PngWin.h"
#include "MyCtrlsLayer.h"

// CMyCtrlsLayer 对话框

IMPLEMENT_DYNAMIC(CMyCtrlsLayer, CCtrlsLayer)

CMyCtrlsLayer::CMyCtrlsLayer()
: CCtrlsLayer(CMyCtrlsLayer::IDD)
{

}

CMyCtrlsLayer::~CMyCtrlsLayer()
{
}

void CMyCtrlsLayer::DoDataExchange(CDataExchange* pDX)
{
	CCtrlsLayer::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyCtrlsLayer, CCtrlsLayer)
	
	ON_BN_CLICKED(IDC_CLOSE, &CMyCtrlsLayer::OnBnClickedClose)
	ON_BN_CLICKED(IDC_MIN, &CMyCtrlsLayer::OnBnClickedMin)
END_MESSAGE_MAP()

BOOL CMyCtrlsLayer::OnInitDialog()
{
	BOOL bRet = CCtrlsLayer::OnInitDialog();

	m_bt1.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt2.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt3.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt4.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt5.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt6.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt7.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt8.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt9.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt10.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt11.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt12.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt13.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt14.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt15.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt16.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt17.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt18.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt19.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt20.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt21.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt22.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt23.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt24.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt25.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt26.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt27.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt28.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt29.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt30.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt31.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_bt32.LoadBitmaps(IDB_BTNORMAL, IDB_BTDOWN);
	m_min.LoadBitmaps(IDB_MINNORMAL, IDB_MINDOWN);
	m_close.LoadBitmaps(IDB_CLOSENORMAL, IDB_CLOSEDOWN);
	m_refresh.LoadBitmaps(IDB_REFRESHNORMAL, IDB_REFRESHDOWN);
	m_return.LoadBitmaps(IDB_RETURNNORMAL, IDB_RETURNDOWN);
	m_enter.LoadBitmaps(IDB_ENTERNORMAL, IDB_ENTERDOWN);

	m_bt1.SubclassDlgItem(IDC_BT1, this);
	m_bt2.SubclassDlgItem(IDC_BT2, this);
	m_bt3.SubclassDlgItem(IDC_BT3, this);
	m_bt4.SubclassDlgItem(IDC_BT4, this);
	m_bt5.SubclassDlgItem(IDC_BT5, this);
	m_bt6.SubclassDlgItem(IDC_BT6, this);
	m_bt7.SubclassDlgItem(IDC_BT7, this);
	m_bt8.SubclassDlgItem(IDC_BT8, this);
	m_bt9.SubclassDlgItem(IDC_BT9, this);
	m_bt10.SubclassDlgItem(IDC_BT10, this);
	m_bt11.SubclassDlgItem(IDC_BT11, this);
	m_bt12.SubclassDlgItem(IDC_BT12, this);
	m_bt13.SubclassDlgItem(IDC_BT13, this);
	m_bt14.SubclassDlgItem(IDC_BT14, this);
	m_bt15.SubclassDlgItem(IDC_BT15, this);
	m_bt16.SubclassDlgItem(IDC_BT16, this);
	m_bt17.SubclassDlgItem(IDC_BT17, this);
	m_bt18.SubclassDlgItem(IDC_BT18, this);
	m_bt19.SubclassDlgItem(IDC_BT19, this);
	m_bt20.SubclassDlgItem(IDC_BT20, this);
	m_bt21.SubclassDlgItem(IDC_BT21, this);
	m_bt22.SubclassDlgItem(IDC_BT22, this);
	m_bt23.SubclassDlgItem(IDC_BT23, this);
	m_bt24.SubclassDlgItem(IDC_BT24, this);
	m_bt25.SubclassDlgItem(IDC_BT25, this);
	m_bt26.SubclassDlgItem(IDC_BT26, this);
	m_bt27.SubclassDlgItem(IDC_BT27, this);
	m_bt28.SubclassDlgItem(IDC_BT28, this);
	m_bt29.SubclassDlgItem(IDC_BT29, this);
	m_bt30.SubclassDlgItem(IDC_BT30, this);
	m_bt31.SubclassDlgItem(IDC_BT31, this);
	m_bt32.SubclassDlgItem(IDC_BT32, this);
	m_min.SubclassDlgItem(IDC_MIN, this);
	m_close.SubclassDlgItem(IDC_CLOSE, this);
	m_refresh.SubclassDlgItem(IDC_REFRESH, this);
	m_return.SubclassDlgItem(IDC_RETURN, this);
	m_enter.SubclassDlgItem(IDC_ENTER, this);

	m_bt1.SizeToContent();
	m_bt2.SizeToContent();
	m_bt3.SizeToContent();
	m_bt4.SizeToContent();
	m_bt5.SizeToContent();
	m_bt6.SizeToContent();
	m_bt7.SizeToContent();
	m_bt8.SizeToContent();
	m_bt9.SizeToContent();
	m_bt10.SizeToContent();
	m_bt11.SizeToContent();
	m_bt12.SizeToContent();
	m_bt13.SizeToContent();
	m_bt14.SizeToContent();
	m_bt15.SizeToContent();
	m_bt16.SizeToContent();
	m_bt17.SizeToContent();
	m_bt18.SizeToContent();
	m_bt19.SizeToContent();
	m_bt20.SizeToContent();
	m_bt21.SizeToContent();
	m_bt22.SizeToContent();
	m_bt23.SizeToContent();
	m_bt24.SizeToContent();
	m_bt25.SizeToContent();
	m_bt26.SizeToContent();
	m_bt27.SizeToContent();
	m_bt28.SizeToContent();
	m_bt29.SizeToContent();
	m_bt30.SizeToContent();
	m_bt31.SizeToContent();
	m_bt32.SizeToContent();
	m_min.SizeToContent();
	m_close.SizeToContent();
	m_refresh.SizeToContent();
	m_return.SizeToContent();
	m_enter.SizeToContent();

	return bRet;
}


// CMyCtrlsLayer 消息处理程序


void CMyCtrlsLayer::OnBnClickedClose()
{
	// TODO:  在此添加控件通知处理程序代码
	DestroyWindow();
}


void CMyCtrlsLayer::OnBnClickedMin()
{
	// TODO:  在此添加控件通知处理程序代码
}
