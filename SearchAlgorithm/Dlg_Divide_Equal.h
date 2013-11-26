#if !defined(AFX_DLG_DIVIDE_EQUAL_H__6AF7E9DF_FBA3_478A_96D5_9237032BB44D__INCLUDED_)
#define AFX_DLG_DIVIDE_EQUAL_H__6AF7E9DF_FBA3_478A_96D5_9237032BB44D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_Divide_Equal.h : header file
//
//#include "GridBtnCell_src\BtnDataBase.h"
//#include "structdef.h"
/////////////////////////////////////////////////////////////////////////////
// CDlg_Divide_Equal dialog

class CDlg_Divide_Equal : public CDialog
{
// Construction
public:
	void Divide_E_Algorithm();
	void initGridDivide();
	CDlg_Divide_Equal(CWnd* pParent = NULL);   // standard constructor
    CGridCtrl m_GridCtrl_Div_info;

	//定义显示算法详细信息的动态数组
	CArray<Divide_EQ*,Divide_EQ*> m_Divide_EQ;
// Dialog Data
	//{{AFX_DATA(CDlg_Divide_Equal)
	enum { IDD = IDD_DIALOG_DIVIDE_EQUAL };
		// NOTE: the ClassWizard will add data members here
	double	m_x0; //常数
	double	m_x2; //x^2的系数
	double	m_x3; //x^3的系数
	double	m_x1; //x^1的系数
	double	m_x4; //x^4的系数
	double	m_x5; //x^5的系数
	double	m_zone1; //左区间
	double	m_zone2; //右区间
	double	m_accuracy; //精度
	double	m_value_similar; //最终近似值
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Divide_Equal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_Divide_Equal)
	virtual BOOL OnInitDialog();
	afx_msg void OnBegin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_DIVIDE_EQUAL_H__6AF7E9DF_FBA3_478A_96D5_9237032BB44D__INCLUDED_)
