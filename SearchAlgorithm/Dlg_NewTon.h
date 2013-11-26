#if !defined(AFX_DLG_NEWTON_H__50CF0C8A_E6BA_4B3A_B0C3_9076D23D477A__INCLUDED_)
#define AFX_DLG_NEWTON_H__50CF0C8A_E6BA_4B3A_B0C3_9076D23D477A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_NewTon.h : header file
//
//#include "GridBtnCell_src\BtnDataBase.h"
/////////////////////////////////////////////////////////////////////////////
// CDlg_NewTon dialog

class CDlg_NewTon : public CDialog
{
// Construction
public:
	void NewTon_Algorithm();
	void initGrid_NewTon();
	CDlg_NewTon(CWnd* pParent = NULL);   // standard constructor
    CGridCtrl m_GridCtrl_NewTon_info;

	//定义显示算法详细信息的动态数组
	CArray<NewTon*,NewTon*> m_NewTow;
// Dialog Data
	//{{AFX_DATA(CDlg_NewTon)
	enum { IDD = IDD_DIALOG_NEWTON };
		// NOTE: the ClassWizard will add data members here
	double	m_x0; //常数
	double	m_x2; //x^2的系数
	double	m_x3; //x^3的系数
	double	m_x1; //x^1的系数
	double	m_x4; //x^4的系数
	double	m_x5; //x^5的系数
	double	m_startX; //初始x点的值
	double	m_accuracy; //精度
	double	m_value_similar; //最终近似值
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_NewTon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_NewTon)
	virtual BOOL OnInitDialog();
	afx_msg void OnBegin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_NEWTON_H__50CF0C8A_E6BA_4B3A_B0C3_9076D23D477A__INCLUDED_)
