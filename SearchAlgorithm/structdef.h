//0.618算法动态数组的结构
typedef struct  
{
    int number; //循环次数
	double  zoneLeft; //左区间
	double  zoneRight; //右区间
	double  zoneArea; //区间长度
	double  valueX1;  //X1的值
	double  valueX2;  //X2的值
	double  valueFx1; //f(x1)的值
	double  valueFx2; //f(X2)的值
}Gold618;

//对分算法动态数组的结构
typedef struct
{
	int number; //循环次数
	double  zoneLeft; //左区间
	double  zoneRight; //右区间
	double  zoneArea; //区间长度
	double  valueDerivaA;  //f'(a)的值
	double  valueDerivaB;  //f'(b)的值
	double  valueC; //c的值
	double  valueDerivaC; //f'(c)的值
	
}Divide_EQ;

//牛顿迭代算法动态数组的结构
typedef struct  
{
    int number; //循环次数
	double  startX1; //迭代起始点x1
	double  valueDerivaX1;  //x1的一阶导数值
	double  value2DerivaX1;  //x1的二阶导数值
	double  newX2; //新的计算点x2
}NewTon;

//抛物线算法动态数组的结构
typedef struct  
{
	int number;//循环次数
	double startX1; //x1的值
	double startX2; //x2的值
	double startX3; //x3的值
	double newX;   //新的计算点x*的值
	double valueFx1; //f(x1)的值
	double valueFx2; //f(x2)的值
	double valueFx3; //f(x3)的值
	double valueNewFx; //新的计算点的f(x*)的值
	double fabsAandB; //绝对值|f(x1*)-f(x2*)|
}Parabolic;