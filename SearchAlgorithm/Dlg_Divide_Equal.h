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

	//������ʾ�㷨��ϸ��Ϣ�Ķ�̬����
	CArray<Divide_EQ*,Divide_EQ*> m_Divide_EQ;
// Dialog Data
	//{{AFX_DATA(CDlg_Divide_Equal)
	enum { IDD = IDD_DIALOG_DIVIDE_EQUAL };
		// NOTE: the ClassWizard will add data members here
	double	m_x0; //����
	double	m_x2; //x^2��ϵ��
	double	m_x3; //x^3��ϵ��
	double	m_x1; //x^1��ϵ��
	double	m_x4; //x^4��ϵ��
	double	m_x5; //x^5��ϵ��
	double	m_zone1; //������
	double	m_zone2; //������
	double	m_accuracy; //����
	double	m_value_similar; //���ս���ֵ
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
