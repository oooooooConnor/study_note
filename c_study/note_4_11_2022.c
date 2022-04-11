#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {

	extern macro();
	macro();

	extern pointer();
	pointer();

	extern int structure();
	structure();

	return 0;
}

// define定义常量和宏 - 预处理指令
// 1、define定义符号
#define MAX 10000
// 2、define定义宏
#define ADD(x, y) ((x)+(y))

int macro() {

	printf("%d\n", ADD(2, 3));    // 打印 5
	printf("%d\n", 4*ADD(2, 3));  // 打印 20 - 4*((2)+(3))
	return 0;
}

// 指针
// 内存 - 空间 地址
// 1、内存是怎么编号的
// 电信号转换成数字信息：1和0组成的二进制序列
// 32位 - 32根地址线 - 物理线 - 通电 - 1/0
// 00000000000000000000000000000000
// ...
// 01111111111111111111111111111111
// 11111111111111111111111111111111
// 一共有2^32个二进制序列，就有2^32个地址（内存单元）
// 
// 64位
// 
// 2、一个这样的内存单元是多大空间
// 假设：一个内存单元是1bit
// 4,294,967,296 bit - 比特位
// /8 = 536,870,912 byte - 字节
// /1024 = 524,288 kb
// /1024 = 512 mb
// /1024 = 0.5 gb
// 那char - 1 byte = 8 bit - 要8个地址
// 所以：一个内存单元是一个字节，然后分配地址

int pointer() {

	int a = 10;  // a在内存中要分配4个字节
	// %p - 专门打印地址
	printf("%p\n", & a);  // 取第一个地址即可
	                      // 因为地址都是依次排列
	                      // 例：第一个地址最后两位（58）
	                      // 剩下三个地址依次是（59）（5A）（5B） - 16进制
	
	int* pa = &a;  // pa是用来存放地址的，在c语言中pa叫指针变量
	// *说明 pa是指针变量
	// int说明 pa执行的对象是int型

	char ch = 'w';
	char* pc = &ch;

	*pa = 20;  // * - 解引用操作 - *pa就是通过pa里面的地址，找到a
	printf("%d\n", a);

	// 指针变量的大小 - 大小是相同的
	// 指针是用来存放地址的
	// 指针需要多大空间，取决于地址的存储需要多大空间
	// 32位 - 32 bit - 4 byte
	// 64位 - 64 bit - 8 byte
	// 
	printf("%lld\n", sizeof(char*));
	printf("%lld\n", sizeof(short*));
	printf("%lld\n", sizeof(int*));
	printf("%lld\n", sizeof(long*));
	printf("%lld\n", sizeof(long long*));
	printf("%lld\n", sizeof(float*));
	printf("%lld\n", sizeof(double*));
	
	return 0;
}

// 结构体 - 可以让c语言创建新的类型出来

// 创建一个学生

struct Stu {

	char name[20];  // 成员变量
	int age;
	double score;
};

// 创建一个书的类型

struct Book {

	char name[20];
	float price;
	char id[30];
};

int structure() {

	struct Stu s = { "张三", 20, 85.5 };  //结构体的创建和初始化
	printf("1：%s %d %lf\n", s.name, s.age, s.score);  // 结构体变量.成员变量

	struct Stu* ps = &s;
	printf("2：%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
	
	                     // 结构体的指针 -> 成员变量名
	printf("3：%s %d %lf\n", ps->name, ps->age, ps->score);

	return 0;
}
