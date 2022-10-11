#pragma once

class CCtrlsLayer
	: public CDialogEx
{
public:
	CCtrlsLayer(UINT id);
	virtual ~CCtrlsLayer();
	
public:
	virtual UINT getTemplateId() { return m_nDlgId; }

protected:
	//{{AFX_VIRTUAL(CPngLayer)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPngLayer)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	CBrush m_brush;		//±³¾°»­Ë¢
	UINT m_nDlgId;
	
};

