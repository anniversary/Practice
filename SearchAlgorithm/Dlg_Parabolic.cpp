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
	//////设置用户定义参数表的显示
	
	m_GridCtrl_Parabolic_info.EnableDragAndDrop(FALSE);
	m_GridCtrl_Parabolic_info.EnableSelection(FALSE);
	m_GridCtrl_Parabolic_info.SetColumnResize(TRUE);
	m_GridCtrl_Parabolic_info.SetRowResize(FALSE);
	m_GridCtrl_Parabolic_info.SetEditable(FALSE);
	m_GridCtrl_Parabolic_info.SetListMode(TRUE);
	m_GridCtrl_Parabolic_info.SetHeaderSort(TRUE);//允许排序
	m_GridCtrl_Parabolic_info.SetCompareFunction(NULL);//默认字符排序
	m_GridCtrl_Parabolic_info.SetVirtualMode(FALSE);
	m_GridCtrl_Parabolic_info.SetSingleRowSelection();
	m_GridCtrl_Parabolic_info.SetBkColor(RGB(255,255,255));
	
	
	//设置列个数
	int nParcolCount = 10;
	m_GridCtrl_Parabolic_info.SetColumnCount(nParcolCount);
	m_GridCtrl_Parabolic_info.SetFixedRowCount(1);
	m_GridCtrl_Parabolic_info.SetSortColumn(2);
	m_GridCtrl_Parabolic_info.SetFixedBkColor(RGB(128,128,128));
	
	//客户区设置
	
	CRect clientRect;
	//long ldistance=clientRect.right - clientRect.left;
	m_GridCtrl_Parabolic_info.GetClientRect(&clientRect);
	m_GridCtrl_Parabolic_info.SetColumnWidth(0,(clientRect.right - clientRect.left)*1/10);    //循环次数
	m_GridCtrl_Parabolic_info.SetColumnWidth(1,(clientRect.right - clientRect.left)*1/10);    //起始点x1
	m_GridCtrl_Parabolic_info.SetColumnWidth(2,(clientRect.right - clientRect.left)*1/10);    //起始点x2
	m_GridCtrl_Parabolic_info.SetColumnWidth(3,(clientRect.right - clientRect.left)*1/10);    //起始点x3
	m_GridCtrl_Parabolic_info.SetColumnWidth(4,(clientRect.right - clientRect.left)*1/10);    //新的点x*
	m_GridCtrl_Parabolic_info.SetColumnWidth(5,(clientRect.right - clientRect.left)*1/10);    //f(x1)>f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(6,(clientRect.right - clientRect.left)*1/10);    //f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(7,(clientRect.right - clientRect.left)*1/10);    //f(x3)>f(x2)
	m_GridCtrl_Parabolic_info.SetColumnWidth(8,(clientRect.right - clientRect.left)*1/10);    //f(x*)
	m_GridCtrl_Parabolic_info.SetColumnWidth(9,(clientRect.right - clientRect.left)*1/10);    //|f(x1*)-f(x2*)|
    
	m_GridCtrl_Parabolic_info.SetRowCount(1); //设置行数
	
	CString str;
    GV_ITEM Item;
	//设置列头
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
	   MessageBox("请在原函数自变量处输入系数!","警告",MB_ICONWARNING);
   } 
   else if (m_accuracy==0)
   {
	   MessageBox("请输入搜索结束的条件，即搜索精度!","警告",MB_ICONWARNING);
   }
   else
   {   
	   m_GridCtrl_Parabolic_info.DeleteAllItems(); //清除所有已显示的信息
	   m_Parabolic.RemoveAll(); //清除所有存储信息
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
		   MessageBox("请输入合适的x1,x2,x3,即必须满足f(x1)>f(x2),f(x3)>f(x2)","警告",MB_ICONWARNING);
		   return ; 
	   }
	   double d_denominator,d_numerator;
	   while(1)
	   {  
		  d_valueFx1 = ValueFx(d_valueX1);
		  d_valueFx2 = ValueFx(d_valueX2);
          d_valueFx3 = ValueFx(d_valueX3);
		  d_denominator = (d_valueX2-d_valueX3)*d_valueFx1+(d_valueX3-d_valueX1)*d_valueFx2
			                      +(d_valueX1-d_valueX2)*d_valueFx3;   //分母   
          if ((d_denominator)!=0)
          {
			  d_numerator = (d_valueX2*d_valueX2-d_valueX3*d_valueX3)*d_valueFx1
				                  +(d_valueX3*d_valueX3-d_valueX1*d_valueX1)*d_valueFx2
								  +(d_valueX1*d_valueX1-d_valueX2*d_valueX2)*d_valueFx3; //分子
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
	   //更新GridCtrl控件，显示算法信息
	   //显示存储的变量信息
	   initGrid_Parabolic();
	   for (int i=0;i<m_Parabolic.GetSize();i++)
	   {   
		   CString strFormat;
		   int iRow=m_GridCtrl_Parabolic_info.InsertRow("",-1);
		   strFormat.Format("%d",m_Parabolic.GetAt(i)->number);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,0,strFormat); //循环次数
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX1);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,1,strFormat); //开始点x1
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX2);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,2,strFormat); //开始点x2
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->startX3);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,3,strFormat); //开始点x3
		   strFormat.Format("%f",m_Parabolic.GetAt(i)->newX);
		   m_GridCtrl_Parabolic_info.SetItemText(iRow,4,strFormat); //新的计算点x*
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
		   
		   //求出的近似解更新入控件中
		   UpdateData(FALSE);
		   //刷新GridCtrl控件
		   m_GridCtrl_Parabolic_info.Refresh();
		}
   }
}

BOOL CDlg_Parabolic::OnInitDialog() 
{
	CDialog::OnInitDialog();
    	
	// TODO: Add extra initialization here
	//初始化GridCtrl控件
    initGrid_Parabolic();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_Parabolic::OnBegin() 
{
	// TODO: Add your control notification handler code here
	//将编辑框中的数值更新进变量
	UpdateData();
	//算法开始
	Parabolic_Algorithm();
}

void CDlg_Parabolic::OnFx() 
{
	// TODO: Add your control notification handler code here
	//由输入更新控件数据
	UpdateData();
	//计算f(x)的值
    m_valueFx = ValueFx(m_valueX);  
	//将计算的f(x)的值输出到控件中
	UpdateData(false);


	
}

double CDlg_Parabolic::ValueFx(double x)
{
   return m_x0+m_x1*x+m_x2*(pow(x,2))+m_x3*(pow(x,3))+m_x4*(pow(x,4))+m_x5*(pow(x,5));
}
