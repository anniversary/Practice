//0.618�㷨��̬����Ľṹ
typedef struct  
{
    int number; //ѭ������
	double  zoneLeft; //������
	double  zoneRight; //������
	double  zoneArea; //���䳤��
	double  valueX1;  //X1��ֵ
	double  valueX2;  //X2��ֵ
	double  valueFx1; //f(x1)��ֵ
	double  valueFx2; //f(X2)��ֵ
}Gold618;

//�Է��㷨��̬����Ľṹ
typedef struct
{
	int number; //ѭ������
	double  zoneLeft; //������
	double  zoneRight; //������
	double  zoneArea; //���䳤��
	double  valueDerivaA;  //f'(a)��ֵ
	double  valueDerivaB;  //f'(b)��ֵ
	double  valueC; //c��ֵ
	double  valueDerivaC; //f'(c)��ֵ
	
}Divide_EQ;

//ţ�ٵ����㷨��̬����Ľṹ
typedef struct  
{
    int number; //ѭ������
	double  startX1; //������ʼ��x1
	double  valueDerivaX1;  //x1��һ�׵���ֵ
	double  value2DerivaX1;  //x1�Ķ��׵���ֵ
	double  newX2; //�µļ����x2
}NewTon;

//�������㷨��̬����Ľṹ
typedef struct  
{
	int number;//ѭ������
	double startX1; //x1��ֵ
	double startX2; //x2��ֵ
	double startX3; //x3��ֵ
	double newX;   //�µļ����x*��ֵ
	double valueFx1; //f(x1)��ֵ
	double valueFx2; //f(x2)��ֵ
	double valueFx3; //f(x3)��ֵ
	double valueNewFx; //�µļ�����f(x*)��ֵ
	double fabsAandB; //����ֵ|f(x1*)-f(x2*)|
}Parabolic;