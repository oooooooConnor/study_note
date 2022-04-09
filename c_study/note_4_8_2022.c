#define _CRT_SECURE_NO_WARNINGS 1

//打印 - 引用stdio头文件
#include <stdio.h>

//求一下字符串的长度 - 引用<string.h>
#include <string.h>


//一个工程可以有多个.c文件
//多个.c文件只能有一个main函数（一个工程只能有一个main函数）
//main函数是程序的入口

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

//编译+链接+运行代码
//快捷键：1.ctrl+f5
//        2.菜单中：【调试】→【开始执行不调试】


//数据类型
//计算机语言 - 写程序 - 解决生活中的问题
//必须有能力来描述生活中的问题
//购物商城 - 上架商品 价格 - 15.6元 - 小数  1.56*10^1
//年龄 - 20岁 -整数
//体重 - 55.5公斤 - 小数 

//char       字符数据类型
//short      短整型
//int        整形
//long       长整型
//long long  更长整型
//float      单精度浮点数
//double     双精度浮点数

int dataType() {

	//字符类型
	//'a' - 字符a
	char ch = 'a';

	//整形
	int age = 20;
	//短整型
	short num0 = 10;
	//长整型
	long num1 = 100000;
	//更长整形
	long long num2 = 1000000000;

	//单精度浮点型
	float price = 15.6f;
	//双精度浮点型
	double weight = 55.5;

	return 0;
}

int size() {

	//打印一个整数 - %d
	printf("%d\n", 100);

	//计算机中的单位
	//bit - 比特位
	//byte - 字节 = 8bit
	//kb - 1024byte
	//mb - 1024kb
	//gb - 1024mb
	//tb - 1024gb
	//pb - 1024tb

	//sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间的大小
	//       - 单位 - 字节byte
	printf("%lld\n", sizeof(char));       //1
	printf("%lld\n", sizeof(short));      //2
	printf("%lld\n", sizeof(int));        //4
	printf("%lld\n", sizeof(long));       //4
	printf("%lld\n", sizeof(long long));  //8
	printf("%lld\n", sizeof(float));      //4
	printf("%lld\n", sizeof(double));     //8

	return 0;
}

//创建一个变量
//类型  变量的名字 = 0；//推荐 - 给个初始值
//类型  变量的名字；//不推荐

//全局变量 - {}外部定义
int age = 0;

int amount() {

	//局部变量 - {}内部定义
	//当局部变量和全局变量名字冲突的情况下，局部优先
	//不建议：把全局变量和局部变量的名字写出一样的
	int age = 20;
	printf("%d\n", age);

	//%f - float
	//%lf - double
	float weight = 75.3f;
	weight = weight - 1;
	printf("%f\n", weight);

	return 0;
}

//求两个整数的和
//scanf函数是输入函数
//第一行加上：#define _CRT_SECURE_NO_WARNINGS 1
//想创建新.c文件时自动输入这句话，以记事本打开newc++file.cpp，复制粘贴即可
//不要用scanf_s - vs编译提供，不是c语言标准规定
int sum() {

	int a = 0;
	int b = 0;
	int sum = 0;
	int monitor;

	//monitor是用来检测有几个数被输入并获取
	printf("输入两个整数\n");
	monitor = scanf("%d %d", &a, &b);

	if (monitor == 2) {
		sum = a + b;
		printf("%d\n", sum);
	}
	else
		printf("数字之间用空格间隔\n");

	return 0;
}

//变量的作用域和生命周期
//
//作用域 
//局部变量的作用域：就是变量所在的局部范围
//全局变量的作用域：整个工程

int g_val = 2021;  //全局变量
//extern int g_val; - 声明这个变量存在

int scope() {

	//局部变量的作用域
	int a = 10;
	printf("a = %d\n", a);
	//{
	//	a = 10;
	//}
	return 0;
}

//生命周期
//变量的生命周期：变量的创建和销毁之间的时间段
//
//局部变量的生命周期：进入局部范围生命开始，出局部范围生命结束
//全局变量的生命周期：程序的生命周期

int lifeCycle() {

	//局部变量的生命周期
	{  //开始
		int a = 10;
		printf("%d\n", a);
	}  //结束
	return 0;
}

//常量

int constant() {

	//1、字面常量
	3.14;
	10;
	'a';
	"abcdef";

	//2、const修饰的常变量
	const int num = 10;  //常变量 - 具有常属性（不能被改变的属性）

	int arr0[10] = { 0 };

	//报错 - 需要常量
	//int n1 = 10;
	//int arr1[n1] = { 0 };

	//报错 - 常变量本质还是变量
	//const int n2 = 10;
	//int arr2[n2] = { 0 };

	//3、#define 定义的标识符常量
#define MAX 10000

	int n = MAX;
	printf("%d\n", n);

	//报错 - 标识符常量
	//MAX = 20000;

	//4、枚举常量
	//可以一一列举的常量

	//性别
	enum Sex {

		//这种枚举类型的变量的未来可能取值
		//枚举常量 - 常量
		MALE = 3,  //赋初值
		FEMALE,    //默认是从0开始计数
		SECRET
	};

	//枚举类型的变量
	enum Sex s = MALE;
	//MALE = 3; - err 

	printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);

	return 0;
}

//字符串+转义字符+注释
//
//字符串 - 一串字符 - 用双引号括起来的一串字符

int characterString() {

	"abcdef";
	"hello,word";
	return 0;
}

int characterArray() {

	//字符数组 - 数组是一组相同类型的元素
	//逐过程调试 - F10 - 发现有6个字符
	//字符串在结尾的位置隐藏了一个\0的字符
	//\0是字符串的结束标志
	char arr[] = "hello";

	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	char arr3[] = { 'a','b','c','\0' };

	//%s - 字符类型
	printf("%s\n", arr1);

	//arr2出现乱码 - abc烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫號U?
	//arr3并没有出现乱码
	//证明\0是字符串的结束标志
	printf("%s\n", arr2);
	printf("%s\n", arr3);

	//求一下字符串的长度 - strlen() - string length
	//warning C4013: “strlen”未定义；假设外部返回 int
	//没有引用头文件 - #include <string.h>
	//
	//在计算字符串长度的时候\0是结束标志，不算字符串内容
	long long len = strlen("abc");
	printf("%lld\n", len);           //3
	printf("%lld\n", strlen(arr1));  //3
	printf("%lld\n", strlen(arr2));  //随机值 - war - 没有添加字符串零终止符
	printf("%lld\n", strlen(arr3));  //3

	return 0;
}

//转义字符

int escape() {

	printf("c:\test\text.c");  //\t -- <tab> - 水平制表符
	//用\\可以防止被理解为一个转义序列符
	//printf("c:\\test\\text.c");
	printf("\v");              //\v -- 垂直制表符
	printf("ab\ncd");          //\n -- 换行
	printf("\b");              //\b -- 退格
	printf("\r");              //\r -- <enter> - 回车
	printf("\f");              //\f -- 进纸符
	printf("(are you ok??)");  //??) -- ] - 三字母词
	//(are you ok]
	
	printf("%c\n", '\'');
	printf("%s\n", "abc");
	printf("%s\n", "a");
	printf("%s\n", "\"");

	printf("\a\a\a");  //\a -- 蜂鸣声 - 警告字符

	printf("%c\n", '\130');  //\130 -- \ddd - 表示1-3个八进制的数字
	                         //八进制130 = 十进制88
	//X -- ASCII码值是88
	
	printf("%d\n", 'A');
	printf("%c\n", '\101');
	//A -- ASCII码值是65 - 八进制101
	//ASCII码表 - 每个字符都有一个ASCII值
	//A -- 65， B - 66…… a - 97， b - 98

	printf("%c\n", '\x30');  //\x30 -- \xdd - 表示2个十六进制数字
	                         //十六进制30 = 十进制48
	//0 - 48
	
	printf("%lld\n", strlen("c:\test\328\text.c"));
	//14 - 一个转义字符计数1

	return 0;
}

//注释 - 解释复杂代码

int notes() {

	//int a = 10;  //C++注释风格

	/*
	int b = 0;
	*/            //C注释风格
	//缺陷
	// /*
	// /*
	// */ - 在这就终止了 - 不支持嵌套注释
	// */
	
	return 0;
}