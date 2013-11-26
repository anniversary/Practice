// GoldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchAlgorithm.h"
#include "GoldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoldDlg dialog


CGoldDlg::CGoldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoldDlg)
	m_x0 = 0.0;
	m_x2 = 0.0;
	m_x3 = 0.0;
	m_x1 = 0.0;
	m_x4 = 0.0;
	m_x5 = 0.0;
	m_zone1 = 0.0;
	m_zone2 = 0.0;
	m_accuracy = 0.0;
	m_value_similar = 0.0;
	//}}AFX_DATA_INIT
}


void CGoldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoldDlg)
	DDX_Text(pDX, IDC_EDIT_ZERO, m_x0);
	DDX_Text(pDX, IDC_EDIT_TWO, m_x2);
	DDX_Text(pDX, IDC_EDIT_THREE, m_x3);
	DDX_Text(pDX, IDC_EDIT_ONE, m_x1);
	DDX_Text(pDX, IDC_EDIT_FOUR, m_x4);
	DDX_Text(pDX, IDC_EDIT_FIVE, m_x5);
	DDX_Text(pDX, IDC_EDIT_SEVEN, m_zone1);
	DDX_Text(pDX, IDC_EDIT_EIGHT, m_zone2);
	DDX_Text(pDX, IDC_EDIT_NINE, m_accuracy);
	DDX_GridControl(pDX,IDC_GRIDE_INF,m_GridCtrl_info);
	DDX_Text(pDX, IDC_VALUE_SIMILAR, m_value_similar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoldDlg, CDialog)
	//{{AFX_MSG_MAP(CGoldDlg)
	ON_BN_CLICKED(IDBEGIN, OnBegin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoldDlg message handlers

void CGoldDlg::OnOK() 
{
	// TODO: Add extra validation here

	DestroyWindow();
	//CDialog::OnOK();
}

void CGoldDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	//delete this;
	CDialog::PostNcDestroy();
}

BOOL CGoldDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//��ʼ��GridCtrl�ؼ�
	initGrid();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGoldDlg::OnBegin() 
{
	// TODO: Add your control notification handler code here
	//���༭���е���ֵ���½�����
	UpdateData();
	//�㷨��ʼ
    Gold618Algorithm();
	
}

void CGoldDlg::initGrid()
{
	m_GridCtrl_info.DeleteAllItems();
	//////�����û�������������ʾ

	m_GridCtrl_info.EnableDragAndDrop(FALSE);
	m_GridCtrl_info.EnableSelection(FALSE);
	//m_GridCtrl_info.SetColumnResize(TRUE);
	//m_GridCtrl_info.SetRowResize(FALSE);
	m_GridCtrl_info.SetEditable(FALSE);
	m_GridCtrl_info.SetListMode(TRUE);
	//m_GridCtrl_info.SetHeaderSort(TRUE);//��������
	//m_GridCtrl_info.SetCompareFunction(NULL);//Ĭ���ַ�����
	m_GridCtrl_info.SetVirtualMode(FALSE);
	//m_GridCtrl_info.SetSingleRowSelection();
	m_GridCtrl_info.SetBkColor(RGB(255,255,255));


	//�����и���
	int nParcolCount = 8;
	m_GridCtrl_info.SetColumnCount(nParcolCount);
	m_GridCtrl_info.SetFixedRowCount(1);
	m_GridCtrl_info.SetSortColumn(2);
	m_GridCtrl_info.SetFixedBkColor(RGB(128,128,128));

	//�ͻ�������

	CRect clientRect;
	//long ldistance=clientRect.right - clientRect.left;
	m_GridCtrl_info.GetClientRect(&clientRect);
	m_GridCtrl_info.SetColumnWidth(0,(clientRect.right - clientRect.left)*1/8);    //ѭ������
	m_GridCtrl_info.SetColumnWidth(1,(clientRect.right - clientRect.left)*1/8);    //��ʼ����
	m_GridCtrl_info.SetColumnWidth(2,(clientRect.right - clientRect.left)*1/8);    //��������
	m_GridCtrl_info.SetColumnWidth(3,(clientRect.right - clientRect.left)*1/8);    //�����С
	m_GridCtrl_info.SetColumnWidth(4,(clientRect.right - clientRect.left)*1/8);    //X1
	m_GridCtrl_info.SetColumnWidth(5,(clientRect.right - clientRect.left)*1/8);    //X2
	m_GridCtrl_info.SetColumnWidth(6,(clientRect.right - clientRect.left)*1/8);    //f(x1)
	m_GridCtrl_info.SetColumnWidth(7,(clientRect.right - clientRect.left)*1/8);    //f(x2)  
    
	m_GridCtrl_info.SetRowCount(1); //��������
	
	CString str;
    GV_ITEM Item;
	//������ͷ
    for (int col = 0; col < m_GridCtrl_info.GetColumnCount(); col++)
    {
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = 0;
		Item.col = col;
		Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS ;
		Item.nState = 0 ;
		
		switch(col) {
		case 0:
			{
				str.LoadString(IDS_NUMBERS);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 1:
			{
				str.LoadString(IDS_BEGINZONE);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 2:
			{
				str.LoadString(IDS_ENDZONE);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 3:
			{
				str.LoadString(IDS_ZONEAREA);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 4:
			{
				str.LoadString(IDS_X1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 5:
			{
				str.LoadString(IDS_X2);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		case 6:
			{
				str.LoadString(IDS_FX1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 7:
			{
				str.LoadString(IDS_FX2);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		default:
			break;
		}
		m_GridCtrl_info.SetItem(&Item);
	}

}

void CGoldDlg::Gold618Algorithm()
{
    if ((m_x0==0)&&(m_x1==0)&&(m_x2==0)&&(m_x3==0)&&(m_x4==0)&&(m_x5==0))
    {
		MessageBox("����ԭ�����Ա���������ϵ��!","����",MB_ICONWARNING);
    }
	else if ((m_zone1>=m_zone2))
	{
		MessageBox("��������ȷ����������!","����",MB_ICONWARNING);
	}
	else if (m_accuracy==0)
	{
		MessageBox("��������������������������������!","����",MB_ICONWARNING);
	}
	else
	{
        m_GridCtrl_info.DeleteAllItems(); //�����������ʾ����Ϣ
		m_Gold618.RemoveAll(); //������д洢��Ϣ
		int i_number=1;
		double d_x1,d_x2,d_zoneL,d_zoneR,d_zoneArear,d_fx1,d_fx2;
		d_zoneL=m_zone1;
		d_zoneR=m_zone2;
		d_zoneArear=0;

		d_x1 = d_zoneL+0.382*(d_zoneR-d_zoneL);
	    d_x2 = d_zoneL+d_zoneR-d_x1;
		d_zoneArear = fabs(d_zoneL-d_zoneR);
		//��x��n�η����ú���pow(x,n);
		d_fx1 = m_x0+m_x1*d_x1+m_x2*(pow(d_x1,2))+m_x3*(pow(d_x1,3))+m_x4*(pow(d_x1,4))+m_x5*(pow(d_x1,5));
        d_fx2 = m_x0+m_x1*d_x2+m_x2*(pow(d_x2,2))+m_x3*(pow(d_x2,3))+m_x4*(pow(d_x2,4))+m_x5*(pow(d_x2,5));


        //����ʼ��Ϣ�ȴ���
		Gold618* newItem = new Gold618;
		newItem->number = i_number;
		newItem->zoneLeft = d_zoneL;
		newItem->zoneRight = d_zoneR;
		newItem->zoneArea = d_zoneArear;
		newItem->valueX1 = d_x1;
		newItem->valueX2 = d_x2;
		newItem->valueFx1 = d_fx1;
		newItem->valueFx2 = d_fx2;
		m_Gold618.Add(newItem);
		//�������б������洢
        while (1)
        {  
           i_number++;
		   if (d_fx1>d_fx2)
		   {
			   d_zoneL = d_x1;
			   d_zoneArear = fabs(d_zoneL-d_zoneR);
			   //���䳤��С�ھ���ʱ�˳�
			   if (d_zoneArear<=m_accuracy)
			   {
				   Gold618* newItem = new Gold618;
				   newItem->number = i_number;
				   newItem->zoneLeft = d_zoneL;
				   newItem->zoneRight = d_zoneR;
				   newItem->zoneArea = d_zoneArear;
				   newItem->valueX1 = 0;
				   newItem->valueX2 = 0;
				   newItem->valueFx1 = 0;
				   newItem->valueFx2 = 0;
				   m_Gold618.Add(newItem);
				   m_value_similar = (d_zoneR+d_zoneL)/2;
				   break;
			   }
			   d_x1 = d_x2;
			   d_x2 = d_zoneL+d_zoneR-d_x1;
			   d_fx1 = d_fx2;
			   d_fx2 = m_x0+m_x1*d_x2+m_x2*(pow(d_x2,2))+m_x3*(pow(d_x2,3))+m_x4*(pow(d_x2,4))+m_x5*(pow(d_x2,5));

		   } 
		   else
		   {
			   d_zoneR = d_x2;
			   d_zoneArear = fabs(d_zoneL-d_zoneR);
			   //���䳤��С�ھ���ʱ�˳�
			   if (d_zoneArear<=m_accuracy)
			   {   
				   Gold618* newItem = new Gold618;
				   newItem->number = i_number;
				   newItem->zoneLeft = d_zoneL;
				   newItem->zoneRight = d_zoneR;
				   newItem->zoneArea = d_zoneArear;
				   newItem->valueX1 = 0;
				   newItem->valueX2 = 0;
				   newItem->valueFx1 = 0;
				   newItem->valueFx2 = 0;
				   m_Gold618.Add(newItem);
				   m_value_similar = (d_zoneR+d_zoneL)/2;
				   break;
			   }
			   d_x2 = d_x1;
			   d_x1 = d_zoneL+d_zoneR-d_x2;
		       d_fx2 = d_fx1;
			   d_fx1 = m_x0+m_x1*d_x1+m_x2*(pow(d_x1,2))+m_x3*(pow(d_x1,3))+m_x4*(pow(d_x1,4))+m_x5*(pow(d_x1,5));
		   }
		   Gold618* newItem = new Gold618;
		   newItem->number = i_number;
		   newItem->zoneLeft = d_zoneL;
		   newItem->zoneRight = d_zoneR;
		   newItem->zoneArea = d_zoneArear;
		   newItem->valueX1 = d_x1;
		   newItem->valueX2 = d_x2;
		   newItem->valueFx1 = d_fx1;
		   newItem->valueFx2 = d_fx2;
		   m_Gold618.Add(newItem);
        }

		//��ʾ�洢�ı�����Ϣ
		initGrid();
		for (int i=0;i<m_Gold618.GetSize();i++)
		{   
			CString strFormat;
			int iRow=m_GridCtrl_info.InsertRow("",-1);
			strFormat.Format("%d",m_Gold618.GetAt(i)->number);
			m_GridCtrl_info.SetItemText(iRow,0,strFormat); //ѭ������
			strFormat.Format("%f",m_Gold618.GetAt(i)->zoneLeft);
			m_GridCtrl_info.SetItemText(iRow,1,strFormat); //������
			strFormat.Format("%f",m_Gold618.GetAt(i)->zoneRight);
			m_GridCtrl_info.SetItemText(iRow,2,strFormat); //������
			strFormat.Format("%f",m_Gold618.GetAt(i)->zoneArea);
			m_GridCtrl_info.SetItemText(iRow,3,strFormat); //���䳤��
			strFormat.Format("%f",m_Gold618.GetAt(i)->valueX1);
			m_GridCtrl_info.SetItemText(iRow,4,strFormat); //X1��ֵ
			strFormat.Format("%f",m_Gold618.GetAt(i)->valueX2);
			m_GridCtrl_info.SetItemText(iRow,5,strFormat); //X2��ֵ
			strFormat.Format("%f",m_Gold618.GetAt(i)->valueFx1);
			m_GridCtrl_info.SetItemText(iRow,6,strFormat); //f(x1)��ֵ
			strFormat.Format("%f",m_Gold618.GetAt(i)->valueFx2);
			m_GridCtrl_info.SetItemText(iRow,7,strFormat); //f(x2)��ֵ

		}
		m_GridCtrl_info.Refresh();
		UpdateData(FALSE);
	}

}
