// Dlg_NewTon.cpp : implementation file
//

#include "stdafx.h"
#include "SearchAlgorithm.h"
#include "Dlg_NewTon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_NewTon dialog


CDlg_NewTon::CDlg_NewTon(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_NewTon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_NewTon)
		// NOTE: the ClassWizard will add member initialization here
	m_x0 = 0.0;
	m_x2 = 0.0;
	m_x3 = 0.0;
	m_x1 = 0.0;
	m_x4 = 0.0;
	m_x5 = 0.0;
	m_startX = 0.0;
	m_accuracy = 0.0;
	m_value_similar = 0.0;
	//}}AFX_DATA_INIT
}


void CDlg_NewTon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_NewTon)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Text(pDX, IDC_EDIT_ZERO, m_x0);
	DDX_Text(pDX, IDC_EDIT_TWO, m_x2);
	DDX_Text(pDX, IDC_EDIT_THREE, m_x3);
	DDX_Text(pDX, IDC_EDIT_ONE, m_x1);
	DDX_Text(pDX, IDC_EDIT_FOUR, m_x4);
	DDX_Text(pDX, IDC_EDIT_FIVE, m_x5);
	DDX_Text(pDX, IDC_EDIT_SEVEN, m_startX);
	DDX_Text(pDX, IDC_EDIT_NINE, m_accuracy);
	DDX_Text(pDX, IDC_VALUE_SIMILAR, m_value_similar);
	DDX_GridControl(pDX,IDC_GRIDE_NEWTON_INF,m_GridCtrl_NewTon_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_NewTon, CDialog)
	//{{AFX_MSG_MAP(CDlg_NewTon)
	ON_BN_CLICKED(IDBEGIN, OnBegin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_NewTon message handlers

BOOL CDlg_NewTon::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	//初始化GridCtrl控件
	initGrid_NewTon();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_NewTon::OnBegin() 
{
	// TODO: Add your control notification handler code here
	//将编辑框中的数值更新进变量
	UpdateData();
	//算法开始
	NewTon_Algorithm();
	
}

void CDlg_NewTon::initGrid_NewTon()
{
    m_GridCtrl_NewTon_info.DeleteAllItems();
	//////设置用户定义参数表的显示

	m_GridCtrl_NewTon_info.EnableDragAndDrop(FALSE);
	m_GridCtrl_NewTon_info.EnableSelection(FALSE);
	m_GridCtrl_NewTon_info.SetColumnResize(TRUE);
	m_GridCtrl_NewTon_info.SetRowResize(FALSE);
	m_GridCtrl_NewTon_info.SetEditable(FALSE);
	m_GridCtrl_NewTon_info.SetListMode(TRUE);
	m_GridCtrl_NewTon_info.SetHeaderSort(TRUE);//允许排序
	m_GridCtrl_NewTon_info.SetCompareFunction(NULL);//默认字符排序
	m_GridCtrl_NewTon_info.SetVirtualMode(FALSE);
	m_GridCtrl_NewTon_info.SetSingleRowSelection();
	m_GridCtrl_NewTon_info.SetBkColor(RGB(255,255,255));


	//设置列个数
	int nParcolCount = 5;
	m_GridCtrl_NewTon_info.SetColumnCount(nParcolCount);
	m_GridCtrl_NewTon_info.SetFixedRowCount(1);
	m_GridCtrl_NewTon_info.SetSortColumn(2);
	m_GridCtrl_NewTon_info.SetFixedBkColor(RGB(128,128,128));

	//客户区设置

	CRect clientRect;
	//long ldistance=clientRect.right - clientRect.left;
	m_GridCtrl_NewTon_info.GetClientRect(&clientRect);
	m_GridCtrl_NewTon_info.SetColumnWidth(0,(clientRect.right - clientRect.left)*1/9);    //循环次数
	m_GridCtrl_NewTon_info.SetColumnWidth(1,(clientRect.right - clientRect.left)*2/9);    //起始点x1
	m_GridCtrl_NewTon_info.SetColumnWidth(2,(clientRect.right - clientRect.left)*2/9);    //x1的一阶导数值
	m_GridCtrl_NewTon_info.SetColumnWidth(3,(clientRect.right - clientRect.left)*2/9);    //x1的二阶导数值
	m_GridCtrl_NewTon_info.SetColumnWidth(4,(clientRect.right - clientRect.left)*2/9);    //新的点x2
    
	m_GridCtrl_NewTon_info.SetRowCount(1); //设置行数
	
	CString str;
    GV_ITEM Item;
	//设置列头
    for (int col = 0; col < m_GridCtrl_NewTon_info.GetColumnCount(); col++)
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
				str.LoadString(IDS_NEWTON_X1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 2:
			{
				str.LoadString(IDS_DERIVA_X1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 3:
			{
				str.LoadString(IDS_2DERIVA_X1);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
		case 4:
			{
				str.LoadString(IDS_NEWTON_X2);
				Item.strText = str;
				str.ReleaseBuffer();
				break;
			}
			
		default:
			break;
		}
		m_GridCtrl_NewTon_info.SetItem(&Item);
	}
}

void CDlg_NewTon::NewTon_Algorithm()
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
		m_GridCtrl_NewTon_info.DeleteAllItems();//清除所有已显示的信息
        m_NewTow.RemoveAll();//清除所有已保存的信息，重新计算
		int i_number = 1;
		double d_valueX1,d_valueX2,d_derivateX1,d_2derivateX1;
		d_valueX1 = m_startX;		
		while(1)
		{   
			//x1的一阶导数值
			d_derivateX1 = m_x1+2*m_x2*d_valueX1+3*m_x3*(pow(d_valueX1,2))+4*m_x4*(pow(d_valueX1,3))+5*m_x5*(pow(d_valueX1,4));
			if (fabs(d_derivateX1)<=m_accuracy)
			{
				//找到近似值，则结束算法
				NewTon* newItem = new NewTon;
				newItem->number = i_number;
				newItem->startX1 = d_valueX1;
				newItem->valueDerivaX1 = d_derivateX1;
				newItem->value2DerivaX1 = 0;
				newItem->newX2 = 0;
				m_NewTow.Add(newItem);
				//更新近似解
				m_value_similar = d_valueX1;
				break;
			} 
            else
			{
				d_2derivateX1 = 2*m_x2+6*m_x3*d_valueX1+12*m_x4*(pow(d_valueX1,2))+20*m_x5*(pow(d_valueX1,3));
				if ((d_2derivateX1)!=0)  //二阶导数不为0
				{
					d_valueX2 = d_valueX1-d_derivateX1/d_2derivateX1;

					//增加循环信息
					NewTon* newItem = new NewTon;
					newItem->number = i_number;
					newItem->startX1 = d_valueX1;
					newItem->valueDerivaX1 = d_derivateX1;
					newItem->value2DerivaX1 = d_2derivateX1;
					newItem->newX2 = d_valueX2;
				    m_NewTow.Add(newItem);
                    //增加循环次数
                    i_number++;	
					
					d_valueX1 = d_valueX2;
				}
				else    //二阶导数为0时
				{ 
					//找到近似值，则结束算法
					NewTon* newItem = new NewTon;
					newItem->number = i_number;
					newItem->startX1 = d_valueX1;
					newItem->valueDerivaX1 = d_derivateX1;
					newItem->value2DerivaX1 = 0;
					newItem->newX2 = 0;
				    m_NewTow.Add(newItem);

                    m_value_similar = d_valueX1;
                    break;
				}
			}
		}
		//更新GridCtrl控件，显示算法信息
		//显示存储的变量信息
		initGrid_NewTon();
		for (int i=0;i<m_NewTow.GetSize();i++)
		{   
			CString strFormat;
			int iRow=m_GridCtrl_NewTon_info.InsertRow("",-1);
			strFormat.Format("%d",m_NewTow.GetAt(i)->number);
			m_GridCtrl_NewTon_info.SetItemText(iRow,0,strFormat); //循环次数
			strFormat.Format("%f",m_NewTow.GetAt(i)->startX1);
			m_GridCtrl_NewTon_info.SetItemText(iRow,1,strFormat); //当前迭代点
			strFormat.Format("%f",m_NewTow.GetAt(i)->valueDerivaX1);
			m_GridCtrl_NewTon_info.SetItemText(iRow,2,strFormat); //当前迭代点的一阶导数值
			strFormat.Format("%f",m_NewTow.GetAt(i)->value2DerivaX1);
			m_GridCtrl_NewTon_info.SetItemText(iRow,3,strFormat); //当前迭代点的二阶导数值
			strFormat.Format("%f",m_NewTow.GetAt(i)->newX2);
			m_GridCtrl_NewTon_info.SetItemText(iRow,4,strFormat); //新的迭代点	

		    //求出的近似解更新入控件中
		    UpdateData(FALSE);
		    //刷新GridCtrl控件
		    m_GridCtrl_NewTon_info.Refresh();
		}
	}
}