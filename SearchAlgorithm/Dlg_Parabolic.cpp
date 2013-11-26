// Dlg_Parabolic.cpp : implementation file
//

#include "stdafx.h"
#include "SearchAlgorithm.h"
#include "Dlg_Parabolic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Parabolic dialog


CDlg_Parabolic::CDlg_Parabolic(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Parabolic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Parabolic)
		// NOTE: the ClassWizard will add member initialization here
	m_x0 = 0;
	m_x1 = 0;
	m_x2 = 0;
	m_x3 = 0;
	m_x4 = 0;
	m_x5 = 0;
	m_valueX = 0;
	m_valueFx = 0;
	m_startX1 = 0;
	m_startX2 = 0;
	m_startX3 = 0;
	m_accuracy = 0;
	m_value_similar = 0;

	//}}AFX_DATA_INIT
}


void CDlg_Parabolic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Parabolic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX,IDC_EDIT_ZERO,m_x0);
	DDX_Text(pDX,IDC_EDIT_ONE,m_x1);
	DDX_Text(pDX,IDC_EDIT_TWO,m_x2);
	DDX_Text(pDX,IDC_EDIT_THREE,m_x3);
	DDX_Text(pDX,IDC_EDIT_FOUR,m_x4);
	DDX_Text(pDX,IDC_EDIT_FIVE,m_x5);
	DDX_Text(pDX,IDC_EDIT_SIX,m_valueX);
	DDX_Text(pDX,IDC_EDIT_SEVEN,m_valueFx);
	DDX_Text(pDX,IDC_EDIT_EIGHT1,m_startX1);
	DDX_Text(pDX,IDC_EDIT_NINE,m_startX2);
	DDX_Text(pDX,IDC_EDIT_TEN,m_startX3);
	DDX_Text(pDX,IDC_EDIT_ELEVEN,m_accuracy);
	DDX_Text(pDX,IDC_VALUE_SIMILAR,m_value_similar);
	DDX_GridControl(pDX,IDC_GRID_PARABOLIC_INF,m_GridCtrl_Parabolic_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_Parabolic, CDialog)
	//{{AFX_MSG_MAP(CDlg_Parabolic)
	ON_BN_CLICKED(IDBEGIN, OnBegin)
	ON_BN_CLICKED(IDC_FX, OnFx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Parabolic message handlers

void CDlg_Parabolic::initGrid_Parabolic()
{
	m_GridCtrl_Parabolic_info.DeleteAllItems();
	//////�����û�������������ʾ
	
	m_GridCtrl_Parabolic_info.EnableDragAndDrop(FALSE);
	m_GridCtrl_Parabolic_info.EnableSelection(FALSE);
	m_GridCtrl_Parabolic_info.SetColumnResize(TRUE);
	m_GridCtrl_Parabolic_info.SetRowResize(FALSE);
	m_GridCtrl_Parabolic_info.SetEditable(FALSE);
	m_GridCtrl_Parabolic_info.SetListMode(TRUE);
	m_GridCtrl_Parabolic_info.SetHeaderSort(TRUE);//��������
	m_GridCtrl_Parabolic_info.SetCompareFunction(NULL);//Ĭ���ַ�����
	m_GridCtrl_Parabolic_info.SetVirtualMode(FALSE);
	m_GridCtrl_Parabolic_info.SetSingleRowSelection();
	m_GridCtrl_Parabolic_info.SetBkColor(RGB(255,255,255));
	
	
	//�����и���
	int nParcolCount = 10;
	m_GridCtrl_Parabolic_info.SetColumnCount(nParcolCount);
	m_GridCtrl_Parabolic_info.SetFixedRowCount(1);
	m_GridCtrl_Parabolic_info.SetSortColumn(2);
	m_GridCtrl_Parabolic_info.SetFixedBkColor(RGB(128,128,128));
	
	//�ͻ�������
	
	CRect clientRect;
	//long ldistance=clientRect.right - clientRect.left;
	m_GridCtrl_Parabolic_info.GetClientRect(&clientRect);
	m_GridCtrl_Parabolic_info.SetColumnWidth(0,(clientRect.right - clientRect.left)*1/10);    //ѭ������
	m_GridCtrl_Parabolic_info.SetColumnWidth(1,(clientRect.right - clientRect.left)*1/10);    //��ʼ��x1
	m_GridCtrl_Parabolic_info.SetColumnWidth(2,(clientRect.right - clientRect.left)*1/10);    //��ʼ��x2
	m_GridCtrl_Parabolic_info.SetColumnWidth(3,(clientRect.right - clientRect.left)*1/10);    //��ʼ��x3
	m_GridCtrl_Parabolic_info.SetColumnWidth(4,(clientRect.right - clientRect.left)*1/10);    //�µĵ�x*
	m_GridCtrl_Parabolic_info.SetColumnWidth(5,(clientRect.right - clientRect.left)*1/10);    //f(x1)>f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(6,(clientRect.right - clientRect.left)*1/10);    //f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(7,(clientRect.right - clientRect.left)*1/10);    //f(x3)>f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(8,(clientRect.right - clientRect.left)*1/10);    //f(x*)
	m_GridCtrl_Parabolic_info.SetColumnWidth(9,(clientRect.right - clientRect.left)*1/10);    //|f(x1*)-f(x2*)|
    
	m_GridCtrl_Parabolic_info.SetRowCount(1); //��������
	
	CString str;
    GV_ITEM Item;
	//������ͷ
    for (int col = 0; col < m_GridCtrl_Parabolic_info.GetColumnCount(); col++)
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
				str.LoadString(IDS_X1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 2:
			{
				str.LoadString(IDS_X2);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 3:
			{
				str.LoadString(IDS_X3);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 4:
			{
				str.LoadString(IDS_NEW_X);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 5:
			{
				str.LoadString(IDS_FX1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 6:
			{
				str.LoadString(IDS_FX2);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 7:
			{
				str.LoadString(IDS_FX3);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 8:
			{
				str.LoadString(IDS_NEW_FX);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 9:
			{
				str.LoadString(IDS_VALUE_FABS);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		default:
			break;
		}
		m_GridCtrl_Parabolic_info.SetItem(&Item);
	}  
}

void CDlg_Parabolic::Parabolic_Algorithm()
{
   if ((m_x0==0)&&(m_x1==0)&&(m_x2==0)&&(m_x3==0)&&(m_x4==0)&&(m_x5==0))
   {
	   MessageBox("����ԭ�����Ա���������ϵ��!","����",MB_ICONWARNING);
   } 
   else if (m_accuracy==0)
   {
	   MessageBox("��������������������������������!","����",MB_ICONWARNING);
   }
   else
   {   
	   m_GridCtrl_Parabolic_info.DeleteAllItems(); //�����������ʾ����Ϣ
	   m_Parabolic.RemoveAll(); //������д洢��Ϣ
	   int i_number = 1;
       double d_valueFx1,d_valueFx2,d_valueFx3,d_valueNewFx,d_valueX1,d_valueX2,d_valueX3,d_valueNewX,d_fabsNewAandB;
	   d_valueX1 = m_startX1;
	   d_valueX2 = m_startX2;
	   d_valueX3 = m_startX3;
	   d_valueFx1 = ValueFx(d_valueX1);
	   d_valueFx2 = ValueFx(d_valueX2);
       d_valueFx3 = ValueFx(d_valueX3);

	   if (!(d_valueFx3>d_valueFx2) || !(d_valueFx1>d_valueFx2))
	   {
		   MessageBox("��������ʵ�x1,x2,x3,����������f(x1)>f(x2),f(x3)>f(x2)","����",MB_ICONWARNING);
		   return ; 
	   }
	   double d_denominator,d_numerator;
	   while(1)
	   {  
		  d_valueFx1 = ValueFx(d_valueX1);
		  d_valueFx2 = ValueFx(d_valueX2);
          d_valueFx3 = ValueFx(d_valueX3);
		  d_denominator = (d_valueX2-d_valueX3)*d_valueFx1+(d_valueX3-d_valueX1)*d_valueFx2
			                      +(d_valueX1-d_valueX2)*d_valueFx3;   //��ĸ   
          if ((d_denominator)!=0)
          {
			  d_numerator = (d_valueX2*d_valueX2-d_valueX3*d_valueX3)*d_valueFx1
				                  +(d_valueX3*d_valueX3-d_valueX1*d_valueX1)*d_valueFx2
								  +(d_valueX1*d_valueX1-d_valueX2*d_valueX2)*d_valueFx3; //����
			  d_valueNewX = d_numerator/(2*d_denominator);
			  d_valueNewFx = ValueFx(d_valueNewX);
			  if (m_Parabolic.GetSize()!=0)
			  {
				  d_fabsNewAandB = fabs(d_valueNewFx-m_Parabolic.GetAt(i_number-2)->valueNewFx);
				  if (d_fabsNewAandB<=m_accuracy)
				  {
					  Parabolic* newItem = new Parabolic;
					  newItem->number = i_number;
					  newItem->startX1 = d_valueX1;
					  newItem->startX2 = d_valueX2;
					  newItem->startX3 = d_valueX3;
					  newItem->newX = d_valueNewX;
					  newItem->valueFx1 = d_valueFx1;
					  newItem->valueFx2 = d_valueFx2;
					  newItem->valueFx3 = d_valueFx3;
					  newItem->valueNewFx = d_valueNewFx;
					  newItem->fabsAandB = d_fabsNewAandB;
				      m_Parabolic.Add(newItem);

					  m_value_similar = d_valueNewX;
					  break;
				  }
				  else
				  {   
					  Parabolic* newItem = new Parabolic;
					  newItem->number = i_number;
					  newItem->startX1 = d_valueX1;
					  newItem->startX2 = d_valueX2;
					  newItem->startX3 = d_valueX3;
					  newItem->newX = d_valueNewX;
					  newItem->valueFx1 = d_valueFx1;
					  newItem->valueFx2 = d_valueFx2;
					  newItem->valueFx3 = d_valueFx3;
					  newItem->valueNewFx = d_valueNewFx;
					  newItem->fabsAandB = d_fabsNewAandB;
					  m_Parabolic.Add(newItem);
				      
					  if (d_valueNewX>d_valueX2)
					  {

						  d_valueX1 = d_valueX2;
						  d_valueX2 = d_valueNewX;

					  }
					  else
					  {
                          d_valueX2 = d_valueNewX;
						  d_valueX3 = d_valueX2;
					  }

					  i_number++;
				  }
			  }
			  else
			  {
                  Parabolic* newItem = new Parabolic;
				  newItem->number = i_number;
				  newItem->startX1 = d_valueX1;
				  newItem->startX2 = d_valueX2;
				  newItem->startX3 = d_valueX3;
				  newItem->newX = d_valueNewX;
				  newItem->valueFx1 = d_valueFx1;
				  newItem->valueFx2 = d_valueFx2;
				  newItem->valueFx3 = d_valueFx3;
				  newItem->valueNewFx = d_valueNewFx;
				  newItem->fabsAandB = 0;
				  m_Parabolic.Add(newItem);

				  if (d_valueNewX>d_valueX2)
				  {
					  
					  d_valueX1 = d_valueX2;
					  d_valueX2 = d_valueNewX;
					  
				  }
				  else
				  {
					  d_valueX2 = d_valueNewX;
					  d_valueX3 = d_valueX2;
				  }

				  i_number++;

			  }

			  
          }
	   }
	   //����GridCtrl�ؼ�����ʾ�㷨��Ϣ
	   //��ʾ�洢�ı�����Ϣ
	   initGrid_Parabolic();
	   for (int i=0;i<m_Parabolic.GetSize();i++)
	   {   
		   CString strFormat;
		   int iRow=m_GridCtrl_Parabolic_info.InsertRow("",-1);
		   strFormat.Format("%d",m_Parabolic.GetAt(i)->number);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,0,strFormat); //ѭ������
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX1);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,1,strFormat); //��ʼ��x1
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX2);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,2,strFormat); //��ʼ��x2
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX3);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,3,strFormat); //��ʼ��x3
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->newX);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,4,strFormat); //�µļ����x*
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->valueFx1);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,5,strFormat); //f(x1)
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->valueFx2);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,6,strFormat); //f(x2)
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->valueFx3);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,7,strFormat); //f(x3)
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->valueNewFx);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,8,strFormat); //f(x*)
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->fabsAandB);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,9,strFormat); //|f(x1*)-f(x2*)|
		   
		   //����Ľ��ƽ������ؼ���
		   UpdateData(FALSE);
		   //ˢ��GridCtrl�ؼ�
		   m_GridCtrl_Parabolic_info.Refresh();
		}
   }
}

BOOL CDlg_Parabolic::OnInitDialog() 
{
	CDialog::OnInitDialog();
    	
	// TODO: Add extra initialization here
	//��ʼ��GridCtrl�ؼ�
    initGrid_Parabolic();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_Parabolic::OnBegin() 
{
	// TODO: Add your control notification handler code here
	//���༭���е���ֵ���½�����
	UpdateData();
	//�㷨��ʼ
	Parabolic_Algorithm();
}

void CDlg_Parabolic::OnFx() 
{
	// TODO: Add your control notification handler code here
	//��������¿ؼ�����
	UpdateData();
	//����f(x)��ֵ
    m_valueFx = ValueFx(m_valueX);  
	//�������f(x)��ֵ������ؼ���
	UpdateData(false);


	
}

double CDlg_Parabolic::ValueFx(double x)
{
   return m_x0+m_x1*x+m_x2*(pow(x,2))+m_x3*(pow(x,3))+m_x4*(pow(x,4))+m_x5*(pow(x,5));
}
