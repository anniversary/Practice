#if !defined(AFX_GOLDDLG_H__FCAFAFBF_BA26_46B5_94A2_D801A9128477__INCLUDED_)
#define AFX_GOLDDLG_H__FCAFAFBF_BA26_46B5_94A2_D801A9128477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GoldDlg.h : header file
//
//#include "GridCtrl_src\GridCtrl.h"
//#include "GridBtnCell_src\BtnDataBase.h"
//#include "structdef.h"
/////////////////////////////////////////////////////////////////////////////
// CGoldDlg dialog

class CGoldDlg : public CDialog
{
// Construction
public:
	void Gold618Algorithm();
	void initGrid();
	CGoldDlg(CWnd* pParent = NULL);   // standard constructor
    CGridCtrl m_GridCtrl_info;

	//定义显示算法详细信息的动态数组
	CArray<Gold618*,Gold618*> m_Gold618;
// Dialog Data
	//{{AFX_DATA(CGoldDlg)
	enum { IDD = IDD_DIALOG_GOLD };
	double	m_x0;
	double	m_x2;
	double	m_x3;
	double	m_x1;
	double	m_x4;
	double	m_x5;
	double	m_zone1;
	double	m_zone2;
	double	m_accuracy; //精度
	double	m_value_similar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoldDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBegin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOLDDLG_H__FCAFAFBF_BA26_46B5_94A2_D801A9128477__INCLUDED_)
