# 初识C语言
###### 基本了解C语言的基础知识，对C语言有一个大概的认识。
- [[初识C语言#什么是C语言|什么是c语言]]
- [[初识C语言#第一个C语言程序|第一个C语言程序]]
- [[初识C语言#数据类型|数据类型]]
- [[初识C语言#变量|变量]]、[[初识C语言#常量|常量]]
- [[初识C语言#字符串|字符串]]+[[初识C语言#转义字符|转义字符]]+[[初识C语言#注释|注释]]
- [[初识C语言#选择语句|选择语句]]
- [[初识C语言#循环语句|循环语句]]
- [[初识C语言#函数|函数]]
- [[初识C语言#数组|数组]]
- [[初识C语言#操作符|操作符]]
- [[初识C语言#常见关键字|常见关键字]]
- [[初识C语言#define定义常量和宏|define定义常量和宏]]
- [[初识C语言#指针|指针]]
- [[初识C语言#结构体|结构体]]

---
## 什么是C语言
> C语言是一门通用计算机编程语言，广泛应用于**底层开发**。C语言的设计目标是提供一种能以简易的方式编译、处理低级存储器、产生少量的机器码以及不需要任何运行环境支持便能运行的编程语言。
> 
> 尽管C语言提供了许多低级处理的功能，但仍然保持着良好跨平台的特性，以一个标准规格写出的C语言程序可在许多电脑平台上进行编译，甚至包含一些嵌入式处理器（单片机或称MCU）以及超级电脑等作业平台。
> 
> 二十世纪八十年代，为了避免各开发商用的C语言语法产生差异，由美国国家标准局为C语言制定了一条完整的美国国家标准语法，成为ANSIC，作为C语言最初的标准。【1】目前2011年12月8日，国际标准化组织（ISO）和国际电工委员会（IEC）发布的C111标准是C语言的第三个官方标准，也是C语言的最新标准，该标准更好的支持了汉字函数名和汉字标识符，一定程度上实现了汉字编程。
> 
> C语言是一门**面向过程**的计算机编程语言，与C++、Java等面向对象的编程语言有所不同。

---
## 第一个C语言程序
```c
//打印 - 引用stdio头文件
#include <stdio.h>

//解释：
//main函数是程序的入口
//一个工程可以有多个.c文件
//多个.c文件只能有一个main函数（一个工程只能有一个main函数）
//main函数是程序的入口
int main(){

printf("hello,word\n");
return 0;
}

//编译+链接+运行代码
//快捷键：1.ctrl+f5
//        2.菜单中：【调试】→【开始执行不调试】
```

---
## 数据类型
why：为什么要有不同数据类型？
answer：必须有能力来描述生活中的问题
- 姓名 - 字符（串）
- 年龄 - 整数
- 价格 - 小数

```c
char       //字符数据类型
short      //短整型
int        //整形
long       //长整型
long long  //更长整型
float      //单精度浮点数
double     //双精度浮点数
```
```c
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
```

why：每种类型的大小是多少？
###### ps：计算机中的单位 
	- bit - 比特位
	- byte - 字节 = 8bit
	- kb - 1024byte
	- mb - 1024kb
	- gb - 1024mb
	- tb - 1024gb
	- pb - 1024tb


```c
#include <stdio.h>

int size() {

	//打印一个整数 - %d
	printf("%d\n", 100);

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
```

---
## 变量
- 生活中的有些值是不变的（比如：圆周率，性别，身份证号码，血型等等），有些值是可变的（比如：年龄，体重，薪资）。
- 不变的值，C语言中用常量的概念来表示，变得值C语言中用变量来表示。

### 定义变量的方法
```c
int age = 150;
float weight = 45.5f;
char ch = 'w';
```
### 变量的分类
	- 局部变量
	- 全局变量

```c
#include <stdio.h>
// 全局变量 - {}外部定义
int global = 2022;  // 全局变量
int main(){

	// 局部变量 - {}内部定义
	// 当局部变量和全局变量名字冲突的情况下，局部优先
	// 不建议：把全局变量和局部变量的名字写出一样的
	int lical = 2021;  // 局部变量
	// 下面定义的global会不会有问题？
	pringtf("global = %d\n", global);
	return 0;
}
```
	总结：
	- 上面的局部变量global变量的定义其实没有什么问题
	- 当局部变量和全局变量同名时，局部变量优先使用

### 变量的使用
```c
//求两个整数的和
//scanf函数是输入函数
//第一行加上：#define _CRT_SECURE_NO_WARNINGS 1
//想创建新.c文件时自动输入这句话，以记事本打开newc++file.cpp，复制粘贴即可
//不要用scanf_s - vs编译提供，不是c语言标准规定
#include <stdio.h>

int main(){

	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	printf("输入两个整数")；
	scanf("%d %d",&num1, &num2);
	sum = num1 + num2;
	printf("sum = %d\n", sum);
	return 0;
}
```
### 变量的作用域和生命周期
```c
#include <stdio.h>

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
```
```c
//生命周期
//变量的生命周期：变量的创建和销毁之间的时间段
//
//局部变量的生命周期：进入局部范围生命开始，出局部范围生命结束
//全局变量的生命周期：程序的生命周期

#include <stdio.h>

int lifeCycle() {

	//局部变量的生命周期
	{  //开始
		int a = 10;
		printf("%d\n", a);
	}  //结束
	return 0;
}
```
## 常量
C语言中的常量和变量的定义的形式有所差异。
C语言中的常量分为以下几种：
- 字面常量
- `const`修饰的常变量
- /#define 定义的标识符常量
- 枚举常量
```c
#include <stdio.h>

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
```
	注：上面例子上的n2被称为const修饰的常变量， const修饰的常变量在C语言中只是在语法层面限制了变量n2不能直接被改变，但是n2本质上还是一个变量的，所以叫常变量。
---

## 字符串
`"hello word\n"`
这种由双引号引起来的一串字符称为字符串字面值，或者简称字符串。
注：字符串的结束标志是一个`\0`的转义字符。在计算字符串长度的时候`\0`是结束标志，不算作字符串内容。
```c
#include <stdio.h>
#include <string.h>

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
```
---

## 转义字符
在屏幕上打印一个目录：`c:\code\test.c`
```c
#include <stdio.h>

int main(){
	printf("c:\code\test.c\n");
	return 0;
}
```
结果：`c:code    est.c`

|  转义字符     | 释义         |
|--------------|--------------|
| `\?` | 在书写连续多个问号时使用，防止他们被解析成三字母词 |
| `\'` | 用于表示字符常量' |
| `\"` | 用于表示一个字符串内部的双引号 |
| `\\` | 用于表示一个反斜杠，防止它被解释为一个转义序列符 |
| `\a` | 警告字符，蜂鸣 |
| `\b` | 退格符 |
| `\f` | 进纸符 |
| `\n` | 换行 |
| `\r` | 回车 |
| `\t` | 水平制表符 |
| `\v` | 垂直制表符 |
| `\ddd` | ddd表示1~3个八进制的数字。 如： \130 X |
| `\xdd` | dd表示2个十六进制数字。 如： \x30 0 |
```c
#include <stdio.h>

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
```

怎么打印单引号跟双引号
```c
#include <stdio.h>

int main(){

	//问题1：在屏幕上打印一个单引号'，怎么做？
	//问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
	printf("%c\n", '\'');
	printf("%s\n", "\"");
	return 0;
}
```
---

## 注释
```c
//注释 - 解释复杂代码

int notes() {

	//int a = 10;  //C++注释风格

	/*
	int b = 0;
	*/            //C注释风格
	//缺陷
	 /*
	 /*
	 */ - 在这就终止了 - 不支持嵌套注释
	 */
	
	return 0;
}
```
---
## 选择语句
```c
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int choose(){
	int input = 0;

	printf("发生什么事了？（0/1）：");
	int monitor = scanf("%d", &input);

	if (input == 1){
		
		printf("眼镜蛇（震声）！！！\n");
		printf("假面骑士贞德\n");

		return 1;
	}
		
	
	else {
		
		printf("果然还是太弱了");
		return 0;
	}
}
```
---

## 循环语句
C语言中如何实现循环
- while语句
- for语句
- do…while语句

```c
//循环语句
//小樱 - 300次变身 - 成功

#include <stdio.h>

int cycle() {
	
	int line = 0;
	
	//while循环语句
	while (line < 300) {
		
		printf("发生什么事了~%d\n",line);
		line++;
	}
	
	if (line == 300)
		printf("眼镜蛇（震声）！！！\n");
	
	return 0;
}
```

---
## 函数
```c
//函数
//数学 - f(x)=2*x+5
//c

#include <stdio.h>

int Add(int x, int y) {
	return (x + y);
}

int sum(){

	int num1 = 0;
	int num2 = 0;
	
	printf("输入两个整数");
	int monitor = scanf("%d %d", &num1, &num2);
	//int sum = num1 + num2;
	int sum = Add(num1, num2);
	printf("%d\n", sum);
	return 0;
}
```
函数的特点就是简化代码，代码复用

---
## 数组
存储1-10的数字，怎么储存
C语言中给了数组的定义：一组相同类型元素的集合

### 数组定义
`int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个整形数组，该数组最多放10个元素`
`char ch[5] = { 'a', 'b', 'c' };  //不完全初始化，剩余的默认为0`

### 数组下标
C语言规定：数组的每个元素都有一个下标，下标是从0开始的
数组可以通过**下标**来访问
```c
//数组是用下标来访问的，第一个下标为0 - 可以用监视窗口验证
	
	int arr[10] = {0};
```
![[数组下标.png]]

### 数组的使用
	arr[]
```c
#include <stdio.h>

int main(){

	int i = 0;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for(i=0; i<10; i++){
	printf("%d ", arr[i]);
	}
	
	printf("\n");
	return 0;
}
```

---
## 操作符
#### 算术操作符
	+ - * / %
```c
// 算术操作符 -- + - * / %

#include <stdio.h>

int arithmetic() {

	int a0 = 9 / 2;      // 4
	float a1 = 9 / 2;    // 4.000000
	float a2 = 9 / 2.0;  // 4.50000

	int a3 = 9 % 2;      // % - 取模（取余） - 1
	printf("%d\n", a3);
	return 0;
}
```

#### 位移操作符
	>> <<
```c
// 移位操作符 -- >> <<

#include <stdio.h>

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
```

#### 位操作符
	& ^ |
```c
// 位操作符 -- & ^ |
// & - 按位与
// | - 按位或
// ^ - 按位异或
```

#### 赋值操作符
	= += -= *= /= &= ^= |= >>= <<=
```c
// 赋值操作符 -- = += -= *= /= &= ^= |= >>= <<=

#include <stdio.h>

int assignment() {

	int a = 2;

	// a = a + 5;
	a += 5;
	printf("%d\n", a);
	return 0;
}
```

#### 单目操作符
|单目操作符|释义|
|-------------|-----|
|`!`|逻辑反操作|
|`-`|负值|
|`+`|正值|
|`&`|取地址|
|`sizeof`|操作数的类型长度（以字节为单位）|
|`~`|对一个数的二进制按位取反|
|`--`|前置、后置自减|
|`++`|前置、后置自增|
|`*`|间接访问操作符(解引用操作符)|
|`(类型)`|强制类型转换|

##### 逻辑反操作
	!
```c
#include <stdio.h>

int main(){

	// 在C语言中0表示假，非零就是真
	int a = 10;
	printf("%d\n", !a);  // 打印 0

	// 逻辑反操作
	if (!a) {
		// 如果a为假，执行
	}

	int b = 0;
	printf("%d\n", !b);  // 打印1

	return 0;
}
```

##### `sizeof`
```c
#include <stdio.h>

int main(){

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

	return 0;
}
```

##### 二进制取反
	~
```c
#include <stdio.h>

int main(){

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

	return 0;
}
```

##### 自增、自减
	++ --
```c
#include <stdio.h>

int main(){

	int j = 10;
	int jj = ++j;         // 前置++，先自增，后执行
	int jjj = j++;        // 后置++，先执行，后自增
	printf("%d\n", j);    // 打印 12
	printf("%d\n", jj);   // 打印 11
	printf("%d\n", jjj);  // 打印 11

	// int a = 1;
	// int b = (++a) + (++a) + (++a);  // 错误的代码
	// printf("%d\n", b);              // 不同编辑器得到的答案不同

	return 0;
}
```

##### 强制类型转换
	(类型)
```c
#include <stdio.h>

int main(){

	// 强制类型转换
	int q = (int)3.14;
	printf("%d\n", q);  // 打印 3

	return 0;
}
```

##### 取地址
	&
```c
int num = 10;
	
&num;  // 取出num的地址
```

##### 指针变量
	*
```c
int num = 10;
int* p = &num;

*p = 20;
```

#### 关系操作符
| 操作符 | 释义 |
| ------ | ---- |
| `>`      |      |
| `>=`     |      |
| `<`      |      |
| `<=`     |      |
| `!=`     | 用于测试“不相等”     |
| `==`     | 用于测试“相等”     |

#### 逻辑操作符
| 操作符 | 释义 |
| ------ | ---- |
| `&&`     | 逻辑与     |
| \|\|    | 逻辑或     |

#### 条件操作符
	exp1 ? exp2 : exp3
```c
#include <stdio.h>

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
	
	return 0;
}
```

#### 逗号表达式
	exp1, exp2, exp3, …expn
```c
#include <stdio.h>

int main(){

	int a = 0;
	int b = 3;
	int max = 0;

	// 逗号表达式 - 从左向右依次计算
	// 整个表达式的结果是最后一个表达式的结果

	      // a = 5   // max = 1   // b = 3
	int d = (a = b + 2, max = a - 4, b = max + 2);
	printf("%d\n", d);  // 打印 3

	return 0;
}
```

#### 下标引用、函数调用和结构成员
	[] () . ->

##### 下标引用操作符
	[]
```c
#include <stdio.h>

int main(){

	// 下标引用操作符
int subscript() {
	   
	     // [] - 此处是定义数组的语法
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	               // [] - 此处才是下标引用操作符
	printf("%d\n", arr[5]);  // 打印 6

	return 0;
}
```

##### 函数调用操作符
	()
```c
#include <stdio.h>

// 函数调用操作符
int function() {

	// 调用函数的时候，函数名后边的()就是函数调用操作符
	printf("眼镜蛇-震声\n");
	printf("%d\n", 100);
	
	return 0;
}
```

##### 结构体操作符
	. ->
```c
// .为结构成员访问操作符                // 结构体变量.成员变量
printf("name = %s age = %d sex = %s id = %s\n", s.name, s.age, s.sex, s.id);
```
```c
// ->操作符
struct Stu *ps = &s;               // 结构体的指针 -> 成员变量名
printf("name = %s age = %d sex = %s id = %s\n", ps->name, ps->age, ps->sex, ps->id);
```

---
## 常见关键字
![[Pasted image 20220428145444.png]]
**关键字：**
**1. C语言提供，不能自己创建关键字**
**2. 关键字不能作为变量名使用**

##### `auto`
自动的，每个局部变量都是`auto`修饰的
```c
	{
		int a = 10;  // 自动创建，自动销毁的 - 自动变量
		// auto 省略掉了
		// auto 新的c语言语法中有也有其他用法 - 暂时不考虑
	}
```

##### `extern`
申明外部符号
```c
// add.c文件


int g_val = 2022;

// add函数
int Add(int x, int y) {

    return x + y;
}

```
```c
// test.c文件


#include <stdio.h>

int main(){

	// 声明外部符号
	extern int g_val;
	printf("%d\n", g_val);

	// 声明外部函数
	int a = 10;
	int b = 20;
	extern int Add(int x, int y);
	int sum = Add(a, b);
	printf("%d\n", sum);

	return 0;
}
```

##### `register`
寄存器关键字
```c
	// 大量、频繁被使用的数据，放在寄存器中，提升效率
	// 即使不使用register关键字，编译器也会自动判断这种数据用register修饰
	
	register int num = 100;  // 建议num的值存放在寄存器中
	// 计算中数据的存储
	// 数据可以存储到哪里 - 寄存器、高速缓存、内存、硬盘、网盘
	// cpu - 先从寄存器读取，再从高速缓存，再从内存。
	//     - 原因：cpu的计算能力大于内存的读取速度
```

##### `unsigned`
无符号的
```c
unsigned int num0 = 100;
```

##### `static`
静态的 - 需要了解一下[[初识C语言#内存分区|内存分区]]

1. `static`修饰局部变量

`static`修饰局部变量改变了变量的生命周期
让**静态局部变量**出了作用域依然存在，到程序结束，生命周期才结束。
```c
//代码1
#include <stdio.h>

void test(){
	int i = 0;
	i++;
	printf("%d\n", i);  // 打印10个2 - 局部变量的生命周期
}

int main(){
	
	int i = 0;
	for(i=0; i<10; i++){
		test();
	}
	
	return 0;
}


//代码2
#include <stdio.h>

void test(){

	//static修饰局部变量
	static int i = 0;
	i++;
	printf("%d\n", i);  // 打印2~11 - 改变了生命周期
}                       // 本质上改变了变量的存储类型

int main(){
	
	int i = 0;
	for(i=0; i<10; i++){
		test();
	}
	
	return 0;
}

```

3. `static`修饰全局变量

一个全局变量被`static`修饰，使得这个全局变量只能在本源文件内使用，**不能在其他源文件内使用**。
```c
//代码1

//add.c
int g_val = 2018;

//test.c
int main(){
	printf("%d\n", g_val);
	return 0;
}


//代码2

//add.c
static int g_val = 2018;
// static int g_val = 2018; - err - static修饰全局变量使得
                                 // 这个全局变量只能在自己 
                                 // 所在的源文件（.c）内部使用
                                 // 其他源文件不用使用！
                                 
//test.c
int main(){
	printf("%d\n", g_val);
	return 0;
}

// 全局变量，在其他源文件内部可以被使用，是因为全局变量具有外部链接属性
// 但是被static修饰之后，就变成了内部链接属性，其他源文件就不能链接
// 到这个静态的全局变量了
```

5. `static`修饰函数

一个函数被`static`修饰，使得这个函数只能在本源文件内使用，**不能在其他源文件内使用**。
```c
//代码1

//add.c
int Add(int x, int y){
	return c+y;
}

//test.c
int main(){
	printf("%d\n", Add(2, 3));
	return 0;
}

//代码2

//add.c

// static修饰函数 - 与全局变量一样 - 变成内部链接属性
static int Add(int x, int y){
	return c+y;
}

//test.c
int main(){
	printf("%d\n", Add(2, 3));
	return 0;
}
```

##### `typedef`
类型重定义（类型**重命名**）
```c
#include <stdio.h>

// typedef - 类型重定义
typedef unsigned int u_int;  // 张三 - 小三

int main(){

	unsigned int num0 = 100;
	u_int num1 = 100;

	return 0;
}
```

---
## \#define定义常量和宏
`#define`定义常量和宏 - **预处理指令** - **不是关键字**
```c
#include <stdio.h>

// 1、define定义符号
#define MAX 10000


// 2、define定义宏
#define ADD(x, y) ((x)+(y))
// #define ADD(x, y) x + y - 则打印11 - 4*2+3

int macro() {

	printf("%d\n", ADD(2, 3));    // 打印 5
	printf("%d\n", 4*ADD(2, 3));  // 打印 20 - 4*((2)+(3))
	
	return 0;
}
```

---
## 指针
### 内存
- 内存是电脑上特别重要的存储器，计算机中程序的运行都是在内存中进行的 。
- 所以为了有效的使用内存，就把内存划分成一个个小的内存单元，每个内存单元的大小是**1个字节**。
- 为了能够有效的访问到内存的每个单元，就给内存单元进行了编号，这些编号被称为该**内存单元的地址**。
- 变量是创建内存中的（在内存中分配空间的），每个内存单元都有地址，所以**变量也是有地址的**。

###### 内存分区
内存 - 栈区、堆区、静态区
- 栈区 - 局部变量、函数的参数
- 堆区 - 动态内存分配
- 静态区 - 全局变量、static修饰的静态变量

###### 内存是怎么编号的
电信号转换成数字信息：1和0组成的二进制序列
32位 - 32根地址线 - 物理线 - 通电 - 1/0
00000000000000000000000000000000
...
01111111111111111111111111111111
11111111111111111111111111111111
一共有2^32个二进制序列，就有2^32个地址（内存单元）
64位就有2^64个地址

##### 打印变量地址
```c
#include <stdio.h>

int main(){

	int a = 10;  // a - int类型在内存中要分配4个字节
	
	     // %p - 用于打印地址
	printf("%p\n", &a);   // 取第一个地址即可
	                      // 因为地址都是依次排列
	                      // 例：第一个地址最后两位（58）
	                      // 剩下三个地址依次是（59）（5A）（5B） - 16进制
	
	return 0;
}
```

##### 取出变量地址
```c
#include <stdio.h>

int main(){
	int num = 10;
	
	&num;  // 取出num的地址
	// 注：这里num的4个字节，每个字节都有地址，取出的是第一个字节的地址（较小的地址）
	printf("%p\n", &num);  // 打印地址，%p是以地址的形式打印
	
	return 0;
}
```

##### 定义指针变量
```c
int num = 10;
int *p;//p为一个整形指针变量
	// *说明p是指针变量
	// int说明p执行的对象是int型
p = &num;
```

##### 指针的使用
```c
#include <stdio.h>

int main(){
	int num = 10;
	int *p = &num;
	*p = 20;  // * - 解引用操作 - *p就是通过p里面的地址，找到num

	printf("%d\n", num);  // 打印 20
	
	return 0;
}
```

以整形指针举例，可以推广到其他类型，如：
```c
#include <stdio.h>

int main(){
	char ch = 'w';
	char* pc = &ch;
	*pc = 'q';
	
	printf("%c\n", ch);  // 打印 q
	
	return 0;
}
```

##### 指针变量的大小
```c
// 指针变量的大小取决于地址的大小

// 代码1
#include <stdio.h>

int main() {

	int a = 10;          // a - int类型在内存中要分配4个字节
	long long b = 10;    // b - long long类型在内存中要分配8个字节

	int* aa = &a;
	long long* bb = &b;

	printf("%lld\n", sizeof(*aa));  // 打印 4
	printf("%lld\n", sizeof(*bb));  // 打印 8
	return 0;
}

// 代码2
#include <stdio.h>

int main(){

	// 指针变量的大小 - 大小是相同的
	// 32位平台下地址是32个bit位（即4个字节）
	// 64位平台下地址是64个bit位（即8个字节）
	printf("%lld\n", sizeof(char*));       // 打印 8
	printf("%lld\n", sizeof(short*));      // 打印 8
	printf("%lld\n", sizeof(int*));        // 打印 8
	printf("%lld\n", sizeof(long*));       // 打印 8
	printf("%lld\n", sizeof(long long*));  // 打印 8
	printf("%lld\n", sizeof(float*));      // 打印 8
	printf("%lld\n", sizeof(double*));     // 打印 8
	
	return 0;
}
```

---
## 结构体
结构体是C语言中特别重要的知识点，结构体使得C语言有能力描述**复杂类型**。
比如描述学生，学生包含： **名字+年龄+性别+学号**这几项信息。
这里只能使用结构体来描述了。

例如：
```c
struct Stu{

	char name[20];  // 名字
	int age;        // 年龄
	char sex[5];    // 性别
	char id[15]；   // 学号
};
```

结构体的**初始化**：
```c
//打印结构体信息
struct Stu s = {"张三"， 20， "男"， "20180101"};

//.为结构成员访问操作符                // 结构体变量.成员变量
printf("name = %s age = %d sex = %s id = %s\n", s.name, s.age, s.sex, s.id);

//->操作符
struct Stu *ps = &s;               // 结构体的指针 -> 成员变量名
printf("name = %s age = %d sex = %s id = %s\n", ps->name, ps->age, ps->sex, ps->id);

// 也可以用.结构成员访问操作符
printf("name = %s age = %d sex = %s id = %s\n"", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);
```
