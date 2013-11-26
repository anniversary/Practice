#if !defined(AFX_DLG_PARABOLIC_H__C9686360_42FA_4B5E_A856_70A05242A828__INCLUDED_)
#define AFX_DLG_PARABOLIC_H__C9686360_42FA_4B5E_A856_70A05242A828__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_Parabolic.h : header file
//
//#include "GridBtnCell_src\BtnDataBase.h"
/////////////////////////////////////////////////////////////////////////////
// CDlg_Parabolic dialog

class CDlg_Parabolic : public CDialog
{
// Construction
public:
	double ValueFx(double x);
	void Parabolic_Algorithm();
	void initGrid_Parabolic();
	CDlg_Parabolic(CWnd* pParent = NULL);   // standard constructor
    CGridCtrl m_GridCtrl_Parabolic_info;

	//定义显示算法详细信息的动态数组
	CArray<Parabolic*,Parabolic*> m_Parabolic;
// Dialog Data
	//{{AFX_DATA(CDlg_Parabolic)
	enum { IDD = IDD_DIALOG_PARABOLIC };
		// NOTE: the ClassWizard will add data members here
	double	m_x0;//函数的系数
	double	m_x2;
	double	m_x3;
	double	m_x1;
	double	m_x4;
	double	m_x5;
	double  m_valueX; //x的值
	double  m_valueFx;//f(x)的值
	double	m_startX1;//开始点x1 ,需满足f(x1)>f(x2),f(x3)>f(x2),即两头大中间小
	double	m_startX2;//开始点x2
    double	m_startX3;//开始点x3
	double	m_accuracy; //精度
	double	m_value_similar; //近似解
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Parabolic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_Parabolic)
	virtual BOOL OnInitDialog();
	afx_msg void OnBegin();
	afx_msg void OnFx();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_PARABOLIC_H__C9686360_42FA_4B5E_A856_70A05242A828__INCLUDED_)
