#define _CRT_SECURE_NO_WARNINGS 1

//��ӡ - ����stdioͷ�ļ�
#include <stdio.h>

//��һ���ַ����ĳ��� - ����<string.h>
#include <string.h>


//һ�����̿����ж��.c�ļ�
//���.c�ļ�ֻ����һ��main������һ������ֻ����һ��main������
//main�����ǳ�������

int main() {

	printf("hello,word\n");

	extern int size();
	size();
	//printf("%d\n",size());

	extern int amount();
	amount();
	//printf("%d\n", amount());

	extern int sum();
	sum();
	//printf("%d\n", sum());

	extern int constant();
	constant();

	extern int characterArray();
	characterArray();

	extern int escape();
	escape();

	return 0;
}

//����+����+���д���
//��ݼ���1.ctrl+f5
//        2.�˵��У������ԡ�������ʼִ�в����ԡ�


//��������
//��������� - д���� - ��������е�����
//���������������������е�����
//�����̳� - �ϼ���Ʒ �۸� - 15.6Ԫ - С��  1.56*10^1
//���� - 20�� -����
//���� - 55.5���� - С�� 

//char       �ַ���������
//short      ������
//int        ����
//long       ������
//long long  ��������
//float      �����ȸ�����
//double     ˫���ȸ�����

int dataType() {

	//�ַ�����
	//'a' - �ַ�a
	char ch = 'a';

	//����
	int age = 20;
	//������
	short num0 = 10;
	//������
	long num1 = 100000;
	//��������
	long long num2 = 1000000000;

	//�����ȸ�����
	float price = 15.6f;
	//˫���ȸ�����
	double weight = 55.5;

	return 0;
}

int size() {

	//��ӡһ������ - %d
	printf("%d\n", 100);

	//������еĵ�λ
	//bit - ����λ
	//byte - �ֽ� = 8bit
	//kb - 1024byte
	//mb - 1024kb
	//gb - 1024mb
	//tb - 1024gb
	//pb - 1024tb

	//sizeof - �ؼ��� - ������ - �������ͻ��߱�����ռ�ռ�Ĵ�С
	//       - ��λ - �ֽ�byte
	printf("%lld\n", sizeof(char));       //1
	printf("%lld\n", sizeof(short));      //2
	printf("%lld\n", sizeof(int));        //4
	printf("%lld\n", sizeof(long));       //4
	printf("%lld\n", sizeof(long long));  //8
	printf("%lld\n", sizeof(float));      //4
	printf("%lld\n", sizeof(double));     //8

	return 0;
}

//����һ������
//����  ���������� = 0��//�Ƽ� - ������ʼֵ
//����  ���������֣�//���Ƽ�

//ȫ�ֱ��� - {}�ⲿ����
int age = 0;

int amount() {

	//�ֲ����� - {}�ڲ�����
	//���ֲ�������ȫ�ֱ������ֳ�ͻ������£��ֲ�����
	//�����飺��ȫ�ֱ����;ֲ�����������д��һ����
	int age = 20;
	printf("%d\n", age);

	//%f - float
	//%lf - double
	float weight = 75.3f;
	weight = weight - 1;
	printf("%f\n", weight);

	return 0;
}

//�����������ĺ�
//scanf���������뺯��
//��һ�м��ϣ�#define _CRT_SECURE_NO_WARNINGS 1
//�봴����.c�ļ�ʱ�Զ�������仰���Լ��±���newc++file.cpp������ճ������
//��Ҫ��scanf_s - vs�����ṩ������c���Ա�׼�涨
int sum() {

	int a = 0;
	int b = 0;
	int sum = 0;
	int monitor;

	//monitor����������м����������벢��ȡ
	printf("������������\n");
	monitor = scanf("%d %d", &a, &b);

	if (monitor == 2) {
		sum = a + b;
		printf("%d\n", sum);
	}
	else
		printf("����֮���ÿո���\n");

	return 0;
}

//���������������������
//
//������ 
//�ֲ������������򣺾��Ǳ������ڵľֲ���Χ
//ȫ�ֱ�������������������

int g_val = 2021;  //ȫ�ֱ���
//extern int g_val; - ���������������

int scope() {

	//�ֲ�������������
	int a = 10;
	printf("a = %d\n", a);
	//{
	//	a = 10;
	//}
	return 0;
}

//��������
//�������������ڣ������Ĵ���������֮���ʱ���
//
//�ֲ��������������ڣ�����ֲ���Χ������ʼ�����ֲ���Χ��������
//ȫ�ֱ������������ڣ��������������

int lifeCycle() {

	//�ֲ���������������
	{  //��ʼ
		int a = 10;
		printf("%d\n", a);
	}  //����
	return 0;
}

//����

int constant() {

	//1�����泣��
	3.14;
	10;
	'a';
	"abcdef";

	//2��const���εĳ�����
	const int num = 10;  //������ - ���г����ԣ����ܱ��ı�����ԣ�

	int arr0[10] = { 0 };

	//���� - ��Ҫ����
	//int n1 = 10;
	//int arr1[n1] = { 0 };

	//���� - ���������ʻ��Ǳ���
	//const int n2 = 10;
	//int arr2[n2] = { 0 };

	//3��#define ����ı�ʶ������
#define MAX 10000

	int n = MAX;
	printf("%d\n", n);

	//���� - ��ʶ������
	//MAX = 20000;

	//4��ö�ٳ���
	//����һһ�оٵĳ���

	//�Ա�
	enum Sex {

		//����ö�����͵ı�����δ������ȡֵ
		//ö�ٳ��� - ����
		MALE = 3,  //����ֵ
		FEMALE,    //Ĭ���Ǵ�0��ʼ����
		SECRET
	};

	//ö�����͵ı���
	enum Sex s = MALE;
	//MALE = 3; - err 

	printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);

	return 0;
}

//�ַ���+ת���ַ�+ע��
//
//�ַ��� - һ���ַ� - ��˫������������һ���ַ�

int characterString() {

	"abcdef";
	"hello,word";
	return 0;
}

int characterArray() {

	//�ַ����� - ������һ����ͬ���͵�Ԫ��
	//����̵��� - F10 - ������6���ַ�
	//�ַ����ڽ�β��λ��������һ��\0���ַ�
	//\0���ַ����Ľ�����־
	char arr[] = "hello";

	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	char arr3[] = { 'a','b','c','\0' };

	//%s - �ַ�����
	printf("%s\n", arr1);

	//arr2�������� - abc��������������������������������̖U��?
	//arr3��û�г�������
	//֤��\0���ַ����Ľ�����־
	printf("%s\n", arr2);
	printf("%s\n", arr3);

	//��һ���ַ����ĳ��� - strlen() - string length
	//warning C4013: ��strlen��δ���壻�����ⲿ���� int
	//û������ͷ�ļ� - #include <string.h>
	//
	//�ڼ����ַ������ȵ�ʱ��\0�ǽ�����־�������ַ�������
	long long len = strlen("abc");
	printf("%lld\n", len);           //3
	printf("%lld\n", strlen(arr1));  //3
	printf("%lld\n", strlen(arr2));  //���ֵ - war - û������ַ�������ֹ��
	printf("%lld\n", strlen(arr3));  //3

	return 0;
}

//ת���ַ�

int escape() {

	printf("c:\test\text.c");  //\t -- <tab> - ˮƽ�Ʊ��
	//��\\���Է�ֹ�����Ϊһ��ת�����з�
	//printf("c:\\test\\text.c");
	printf("\v");              //\v -- ��ֱ�Ʊ��
	printf("ab\ncd");          //\n -- ����
	printf("\b");              //\b -- �˸�
	printf("\r");              //\r -- <enter> - �س�
	printf("\f");              //\f -- ��ֽ��
	printf("(are you ok??)");  //??) -- ] - ����ĸ��
	//(are you ok]
	
	printf("%c\n", '\'');
	printf("%s\n", "abc");
	printf("%s\n", "a");
	printf("%s\n", "\"");

	printf("\a\a\a");  //\a -- ������ - �����ַ�

	printf("%c\n", '\130');  //\130 -- \ddd - ��ʾ1-3���˽��Ƶ�����
	                         //�˽���130 = ʮ����88
	//X -- ASCII��ֵ��88
	
	printf("%d\n", 'A');
	printf("%c\n", '\101');
	//A -- ASCII��ֵ��65 - �˽���101
	//ASCII��� - ÿ���ַ�����һ��ASCIIֵ
	//A -- 65�� B - 66���� a - 97�� b - 98

	printf("%c\n", '\x30');  //\x30 -- \xdd - ��ʾ2��ʮ����������
	                         //ʮ������30 = ʮ����48
	//0 - 48
	
	printf("%lld\n", strlen("c:\test\328\text.c"));
	//14 - һ��ת���ַ�����1

	return 0;
}

//ע�� - ���͸��Ӵ���

int notes() {

	//int a = 10;  //C++ע�ͷ��

	/*
	int b = 0;
	*/            //Cע�ͷ��
	//ȱ��
	// /*
	// /*
	// */ - �������ֹ�� - ��֧��Ƕ��ע��
	// */
	
	return 0;
}