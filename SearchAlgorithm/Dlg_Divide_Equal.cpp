// Dlg_Divide_Equal.cpp : implementation file
//

#include "stdafx.h"
#include "SearchAlgorithm.h"
#include "Dlg_Divide_Equal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Divide_Equal dialog


CDlg_Divide_Equal::CDlg_Divide_Equal(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Divide_Equal::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Divide_Equal)
		// NOTE: the ClassWizard will add member initialization here
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


void CDlg_Divide_Equal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Divide_Equal)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Text(pDX, IDC_EDIT_ZERO, m_x0);
	DDX_Text(pDX, IDC_EDIT_TWO, m_x2);
	DDX_Text(pDX, IDC_EDIT_THREE, m_x3);
	DDX_Text(pDX, IDC_EDIT_ONE, m_x1);
	DDX_Text(pDX, IDC_EDIT_FOUR, m_x4);
	DDX_Text(pDX, IDC_EDIT_FIVE, m_x5);
	DDX_Text(pDX, IDC_EDIT_SEVEN, m_zone1);
	DDX_Text(pDX, IDC_EDIT_EIGHT, m_zone2);
	DDX_Text(pDX, IDC_EDIT_NINE, m_accuracy);
	DDX_Text(pDX, IDC_VALUE_SIMILAR, m_value_similar);
	DDX_GridControl(pDX,IDC_GRIDE_DIV_INF,m_GridCtrl_Div_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_Divide_Equal, CDialog)
	//{{AFX_MSG_MAP(CDlg_Divide_Equal)
	ON_BN_CLICKED(IDBEGIN, OnBegin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Divide_Equal message handlers

BOOL CDlg_Divide_Equal::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	//��ʼ��GridCtrl�ؼ�
	initGridDivide();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_Divide_Equal::OnBegin() 
{
	// TODO: Add your control notification handler code here
	//���༭���е���ֵ���½�����
	UpdateData();
	//�㷨��ʼ
    Divide_E_Algorithm();
}

void CDlg_Divide_Equal::initGridDivide()
{
    m_GridCtrl_Div_info.DeleteAllItems();
	//////�����û�������������ʾ

	m_GridCtrl_Div_info.EnableDragAndDrop(FALSE);
	m_GridCtrl_Div_info.EnableSelection(FALSE);
	m_GridCtrl_Div_info.SetColumnResize(TRUE);
	m_GridCtrl_Div_info.SetRowResize(FALSE);
	m_GridCtrl_Div_info.SetEditable(FALSE);
	m_GridCtrl_Div_info.SetListMode(TRUE);
	m_GridCtrl_Div_info.SetHeaderSort(TRUE);//��������
	m_GridCtrl_Div_info.SetCompareFunction(NULL);//Ĭ���ַ�����
	m_GridCtrl_Div_info.SetVirtualMode(FALSE);
	m_GridCtrl_Div_info.SetSingleRowSelection();
	m_GridCtrl_Div_info.SetBkColor(RGB(255,255,255));


	//�����и���
	int nParcolCount = 8;
	m_GridCtrl_Div_info.SetColumnCount(nParcolCount);
	m_GridCtrl_Div_info.SetFixedRowCount(1);
	m_GridCtrl_Div_info.SetSortColumn(2);
	m_GridCtrl_Div_info.SetFixedBkColor(RGB(128,128,128));

	//�ͻ�������

	CRect clientRect;
	//long ldistance=clientRect.right - clientRect.left;
	m_GridCtrl_Div_info.GetClientRect(&clientRect);
	m_GridCtrl_Div_info.SetColumnWidth(0,(clientRect.right - clientRect.left)*1/8);    //ѭ������
	m_GridCtrl_Div_info.SetColumnWidth(1,(clientRect.right - clientRect.left)*1/8);    //��ʼ����
	m_GridCtrl_Div_info.SetColumnWidth(2,(clientRect.right - clientRect.left)*1/8);    //��������
	m_GridCtrl_Div_info.SetColumnWidth(3,(clientRect.right - clientRect.left)*1/8);    //�����С
	m_GridCtrl_Div_info.SetColumnWidth(4,(clientRect.right - clientRect.left)*1/8);    //X1
	m_GridCtrl_Div_info.SetColumnWidth(5,(clientRect.right - clientRect.left)*1/8);    //X2
	m_GridCtrl_Div_info.SetColumnWidth(6,(clientRect.right - clientRect.left)*1/8);    //f(x1)
	m_GridCtrl_Div_info.SetColumnWidth(7,(clientRect.right - clientRect.left)*1/8);    //f(x2)  
    
	m_GridCtrl_Div_info.SetRowCount(1); //��������
	
	CString str;
    GV_ITEM Item;
	//������ͷ
    for (int col = 0; col < m_GridCtrl_Div_info.GetColumnCount(); col++)
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
				str.LoadString(IDS_DERIVA_A);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 5:
			{
				str.LoadString(IDS_DERIVA_B);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		case 6:
			{
				str.LoadString(IDS_VALUE_C);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 7:
			{
				str.LoadString(IDS_DERIVA_C);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		default:
			break;
		}
		m_GridCtrl_Div_info.SetItem(&Item);
	}
}

void CDlg_Divide_Equal::Divide_E_Algorithm()
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
        m_GridCtrl_Div_info.DeleteAllItems();
		m_Divide_EQ.RemoveAll(); //������д洢��Ϣ
		int i_number=1;
		double d_derivate1,d_derivate2,d_zoneL,d_zoneR,d_zoneArear,d_c,d_derivate3;
		d_zoneL=m_zone1;
		d_zoneR=m_zone2;
		d_zoneArear=0;
        
		//f'(a)��ֵ
		d_derivate1 = m_x1+2*m_x2*d_zoneL+3*m_x3*(pow(d_zoneL,2))+4*m_x4*(pow(d_zoneL,3))+5*m_x5*(pow(d_zoneL,4));
		if (!(d_derivate1<0))
		{
            MessageBox("��������ȷ������������!(Ҫ����ֵС����)","����",MB_ICONWARNING);
			return;
		}
	    //f'(b)��ֵ
		d_derivate2 = m_x1+2*m_x2*d_zoneR+3*m_x3*(pow(d_zoneR,2))+4*m_x4*(pow(d_zoneR,3))+5*m_x5*(pow(d_zoneR,4));
		if (!(d_derivate2>0))
		{
            MessageBox("��������ȷ������������!(Ҫ����ֵ������)","����",MB_ICONWARNING);
			return;
		}
		d_zoneArear = d_zoneR-d_zoneL;
		//c��ֵ
		d_c = (d_zoneL+d_zoneR)/2;
		//f'(c)��ֵ
        d_derivate3 = m_x1+2*m_x2*d_c+3*m_x3*(pow(d_c,2))+4*m_x4*(pow(d_c,3))+5*m_x5*(pow(d_c,4));


        //����ʼ��Ϣ�ȴ���
		Divide_EQ* newItem = new Divide_EQ;
		newItem->number = i_number;
		newItem->zoneLeft = d_zoneL;
		newItem->zoneRight = d_zoneR;
		newItem->zoneArea = d_zoneArear;
		newItem->valueDerivaA = d_derivate1;
		newItem->valueDerivaB = d_derivate2;
		newItem->valueC = d_c;
		newItem->valueDerivaC = d_derivate3;
		m_Divide_EQ.Add(newItem);
		//�������б������洢
        while (1)
        {  
           i_number++;

		   if (d_derivate3==0)
		   {
              m_value_similar = d_c;
			  break;
		   }
		   else if (d_derivate3<0)
		   {
              d_zoneL = d_c;
			  d_derivate1 = d_derivate3;
		   }
		   else
		   {
			   d_zoneR = d_c;
			   d_derivate2 = d_derivate3;
		   }
		   d_zoneArear = d_zoneR-d_zoneL;
           d_c = (d_zoneL+d_zoneR)/2;
		   d_derivate3 = m_x1+2*m_x2*d_c+3*m_x3*(pow(d_c,2))+4*m_x4*(pow(d_c,3))+5*m_x5*(pow(d_c,4));
		   if (d_zoneArear<=m_accuracy)
           {
			   Divide_EQ* newItem = new Divide_EQ;
			   newItem->number = i_number;
			   newItem->zoneLeft = d_zoneL;
			   newItem->zoneRight = d_zoneR;
			   newItem->zoneArea = d_zoneArear;
			   newItem->valueDerivaA = d_derivate1;
			   newItem->valueDerivaB = d_derivate2;
			   newItem->valueC = d_c;
			   newItem->valueDerivaC = d_derivate3;
		       m_Divide_EQ.Add(newItem);

               m_value_similar = d_c;
			   break;
           }
		   Divide_EQ* newItem = new Divide_EQ;
		   newItem->number = i_number;
		   newItem->zoneLeft = d_zoneL;
		   newItem->zoneRight = d_zoneR;
		   newItem->zoneArea = d_zoneArear;
		   newItem->valueDerivaA = d_derivate1;
		   newItem->valueDerivaB = d_derivate2;
		   newItem->valueC = d_c;
		   newItem->valueDerivaC = d_derivate3;
		   m_Divide_EQ.Add(newItem);
		}
		//��ʾ�洢�ı�����Ϣ
		initGridDivide();
		for (int i=0;i<m_Divide_EQ.GetSize();i++)
		{   
			CString strFormat;
			int iRow=m_GridCtrl_Div_info.InsertRow("",-1);
			strFormat.Format("%d",m_Divide_EQ.GetAt(i)->number);
			m_GridCtrl_Div_info.SetItemText(iRow,0,strFormat); //ѭ������
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->zoneLeft);
			m_GridCtrl_Div_info.SetItemText(iRow,1,strFormat); //������
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->zoneRight);
			m_GridCtrl_Div_info.SetItemText(iRow,2,strFormat); //������
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->zoneArea);
			m_GridCtrl_Div_info.SetItemText(iRow,3,strFormat); //���䳤��
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->valueDerivaA);
			m_GridCtrl_Div_info.SetItemText(iRow,4,strFormat); //f'(a)��ֵ	
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->valueDerivaB);
			m_GridCtrl_Div_info.SetItemText(iRow,5,strFormat); //f'(b)��ֵ
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->valueC);
			m_GridCtrl_Div_info.SetItemText(iRow,6,strFormat); //c��ֵ
			strFormat.Format("%f",m_Divide_EQ.GetAt(i)->valueDerivaC);
			m_GridCtrl_Div_info.SetItemText(iRow,7,strFormat); //f'(c)��ֵ

		}
		m_GridCtrl_Div_info.Refresh();
		UpdateData(FALSE);
	}
}
