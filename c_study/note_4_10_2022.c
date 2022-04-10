#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {

	extern int arithmetic();
	arithmetic();
	
	extern int displacement();
	displacement();

	extern int monocular();
	monocular();

	extern int logic();
	logic();

	extern int condition();
	condition();

	extern int subscript();
	subscript();

	extern function();
	function();

	extern keyword();
	keyword();

	return 0;
}

// 操作符
// 算术操作符 -- + - * / %
 
int arithmetic() {

	int a0 = 9 / 2;      // 4
	float a1 = 9 / 2;    // 4.000000
	float a2 = 9 / 2.0;  // 4.50000

	int a3 = 9 % 2;      // % - 取模（取余） - 1
	printf("%d\n", a3);
	return 0;
}

// 移位操作符 -- >> <<

int displacement() {

	int a = 2;

	// 左移操作符 - 移动的是二进制
	// 1 - 二进制 - 10
	// int - 整形 - 4bit -- 1bit = 8个二进制
	// 00000000000000000000000000000010 - 2^1
	// 00000000000000000000000000000100 - 2^2
	int b = a << 1;
	printf("%d\n", b);
	return 0;
}

// 位操作符 -- & ^ |
// & - 按位与
// | - 按位或
// ^ - 按位异或

// 赋值操作符 -- = += -= *= /= &= ^= |= >>= <<=

int assignment() {

	int a = 2;

	// a = a + 5;
	a += 5;
	printf("%d\n", a);
	return 0;
}

// a + b - +有2个操作数 - 双目操作符
// +a - 只有1个操作数 - 单目操作符
// 单目操作符 -- ! - + & sizof ~ -- ++ * (类型)
// ！- 逻辑反操作
// - - 负值
// + - 正值
// & - 取地址
// sizof - 操作数的类型长度（以字节为单位）
// ~ - 对一个数的二进制按位取反
// -- - 前置、后置自减
// ++ - 前置、后置自增
// * - 间接访问操作符（解引用操作符）
// (类型) - 强制类型转换

int monocular() {

	// 0 - 表示假，非零就是真
	int a = 10;
	printf("%d\n", !a);  // 打印 0

	if (!a) {
		// 如果a为假，执行
	}

	int b = 0;
	printf("%d\n", !b);  // 打印1

	// sizeof - 一个单目操作符
	// 计算类型或变量的大小 - 单位是字节byte
	printf("%lld\n", sizeof(int));  // 打印 4 - 类型不能省略()
	printf("%lld\n", sizeof(a));    // 打印 4

	// 不用() - 证明sizeof不是函数，是操作符
	printf("%lld\n", sizeof b);    // 打印 4

	// sizeof(int) = 4 - 10个元素 - 4*10
	int arr[10] = { 0 };
	printf("%lld\n", sizeof(arr));  // 打印 40 - 计算数组的总大小 

	// 求元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", sz);  // 打印10

	// ~ - 按（二进制）位取反
	// 把所以二进制位的数字，1变成0，0变成1
	// 整型 0 - 整形 4byte = 32 bit
	// 00000000000000000000000000000000
	// 11111111111111111111111111111111

	// 整数在内存中存储的是补码
	// 一个整数的二进制表示有三种
	// 最高位为符号位，其余位为有效位
	// 原码 - （-1） - 10000000000000000000000000000001
	// 反码 - （-1） - 11111111111111111111111111111110
	//      - 符号位不变，有效位0变1，1变0
	// 补码 - （-1） - 11111111111111111111111111111111
	//      - 反码+1

	int e = 0;
	printf("%d\n", ~e);  // 打印 -1
	
	int j = 10;
	int jj = ++j;         // 前置++，先自增，后执行
	int jjj = j++;        // 后置++，先执行，后自增
	printf("%d\n", j);    // 打印 12
	printf("%d\n", jj);   // 打印 11
	printf("%d\n", jjj);  // 打印 11

	// int a = 1;
	// int b = (++a) + (++a) + (++a);  // 错误的代码
	// printf("%d\n", b);              // 不同编辑器得到的答案不同

	// 强制类型转换
	int q = (int)3.14;
	printf("%d\n", q);  // 打印 3

	return 0;
}

// 关系操作符 -- > >= < <= != ==
// 逻辑操作符 -- && - 逻辑与， || - 逻辑或

int logic() {

	int a = 3;
	int b = -5;
	int c = 0;

	// c语言中，0为假，非0为真
	int d = a && b;
	int e = a && c;
	int f = a || c;
	printf("%d\n", d);  // 打印 1
	printf("%d\n", e);  // 打印 0
	printf("%d\n", f);  // 打印 1

	return 0;
}

// 条件操作符（三目操作符） -- exp1 ? exp2 : exp3
//   - exp1 成立。exp2计算，整个表达式的结果是：exp2的结果
//   - exp1 不成立。exp3计算，整个表达式的结果是：exp3的结果

int condition() {

	int a = 0;
	int b = 3;
	int max = 0;
	
	if (a > b)
		max = a;
	else
		max = b;

	max = a > b ? a : b;
	printf("%d\n", max);  // 打印 3

	// 逗号表达式 - 从左向右依次计算
	// 整个表达式的结果是最后一个表达式的结果

	      // a = 5   // max = 1   // b = 3
	int d = (a = b + 2, max = a - 4, b = max + 2);
	printf("%d\n", d);  // 打印 3

	return 0;
}

// 下标引用、函数调用和结构成员 -- [] () . ->

// 下标引用操作符
int subscript() {
	   
	     // [] - 此处是定义数组的语法
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	               // [] - 此处是下标引用操作符
	printf("%d\n", arr[5]);  // 打印 6

	return 0;
}

// 函数调用操作符
int function() {

	// 调用函数的时候，函数名后边的()就是函数调用操作符
	printf("眼镜蛇（震声）\n");
	printf("%d\n", 100);
	
	return 0;
}

// & * . -> 还没有介绍


// 常见关键字
// 1、c语言提供的，不能自己创建关键字
// 2、关键字不能做变量名
// auto、break、case、char、const、continue、default、do、double、
// else、enum、extern、float、for、goto、if、int、long、register、
// return、short、signed、sizeof、static、struct、switch、typedef、
// union、unsigned、void、volatile、while
//
// auto - 自动的 - 每个局部变量都是auto修饰的
// extern - 申明外部符号
// register - 寄存器关键字
// signed - 有符号的
// unsigned - 无符号的
// static - 静态的
//        - 1、static修饰局部变量
//        - 2、static修饰全局变量
//        - 3、static修饰函数
// typedef - 类型重定义（类型重命名）
// union - 联合体（共用体）
// void - 无（空）
// volatile - 段落 - c语言中暂时不用了解
// 

// define、include - 预处理指令 - 不是关键字

// typedef - 类型重定义
typedef unsigned int u_int;  // 张三 - 小三

// 内存 - 栈区、堆区、静态区
// 栈区 - 局部变量、函数的参数
// 堆区 - 动态内存分配
// 静态区 - 全局变量、static修饰的静态变量

void test() {

	// int a = 1;      // 打印10个2 - 局部变量的生命周期
	static int a = 1;  // 打印2~11 - 改变了生命周期
	                   // 本质上改变了变量的存储类型
	a++;
	printf("%d\n", a);
}

int keyword() {

	unsigned int num0 = 100;
	u_int num1 = 100;
	
	{
		int a = 10;  // 自动创建，自动销毁的 - 自动变量
		// auto 省略掉了
		// auto 新的c语言语法中有也有其他用法 - 暂时不考虑
	}

	int i = 0;
	while (i < 10) {

		test();
		i++;
	}

	// 大量、频繁被使用的数据，放在寄存器中，提升效率
	// 即使不使用register关键字，编译器也会自动判断这种数据用register修饰
	register int num = 100;  // 建议num的值存放在寄存器中
	// 计算中数据的存储
	// 数据可以存储到哪里 - 寄存器、高速缓存、内存、硬盘、网盘
	// cpu - 先从寄存器读取，再从高速缓存，再从内存。
	//     - 原因：cpu的计算能力大于内存的读取速度

	// extern - 声明外部符号
	extern int g_val;
	printf("%d\n", g_val);

	{
		int a = 10;
		int b = 20;
		// 声明函数
		extern int Add(int x, int y);
		int sum = Add(a, b);
		printf("%d\n", sum);
	}

	return 0;
}