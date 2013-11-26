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

	//������ʾ�㷨��ϸ��Ϣ�Ķ�̬����
	CArray<NewTon*,NewTon*> m_NewTow;
// Dialog Data
	//{{AFX_DATA(CDlg_NewTon)
	enum { IDD = IDD_DIALOG_NEWTON };
		// NOTE: the ClassWizard will add data members here
	double	m_x0; //����
	double	m_x2; //x^2��ϵ��
	double	m_x3; //x^3��ϵ��
	double	m_x1; //x^1��ϵ��
	double	m_x4; //x^4��ϵ��
	double	m_x5; //x^5��ϵ��
	double	m_startX; //��ʼx���ֵ
	double	m_accuracy; //����
	double	m_value_similar; //���ս���ֵ
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
