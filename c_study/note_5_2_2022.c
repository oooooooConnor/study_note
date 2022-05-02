// C语言是结构化的程序设计语言
// 顺序结构、选择结构、循环结构

// 分支语句和循环语句
// 分支语句 - if、 switch
// 循环语句 - while、 for、 do while
// goto语句

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	
	// 输出1-100中的奇数
	for (int i = 1; i <= 100; i += 2) {
		printf("%d\n", i);
	}

	extern int btanch();
	btanch();

	extern int loop();
	loop();

	extern int loop1();
	loop1();

	extern int passWord();
	passWord();

	extern int loop2();
	loop2();

	extern int factorial();
	factorial();

	extern int factorial1();
	factorial1();

	extern int binarySearch();
	binarySearch();
	
	return 0;
}

// switch分支语句
int btanch() {

	int sw1 = 0;

	printf("输入一个1-7中的整数\n");
	int judge = scanf("%d", &sw1);

	switch (sw1) {

	case 1:
		printf("星期一\n");
		break;

	case 2:
		printf("星期二\n");
		break;

	case 3:
		printf("星期三\n");
		break;

	case 4:
		printf("星期四\n");
		break;

	case 5:
		printf("星期五\n");
		break;

	case 6:
		printf("星期六\n");
		break;

	case 7:
		printf("星期天\n");
		break;

	default:
		printf("星期八？\n");
		break;

	}

	switch (sw1){

	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;

	case 6:
	case 7:
		printf("休息日\n");
		break;

	default:
		printf("星期八？\n");
		break;
	}

	return 0;
}


// while循环
//
// 在while循环中，continue的作用是跳过本次循环continue后边的代码
// 直接跳到判断部分，看是否进行下一次循环
// 
// 在while循环中，break用于该while的终止循环
//
int loop() {

	int i1 = 1;

	while (i1 <= 10) {

		if (i1 == 3) {
			i1++;
			continue;
			i1 = 10;
		}

		if (i1 == 9) {
			break;
		}

		printf("%d\n", i1);
		i1++;
	}

	return 0;
}


int loop1() {

	int ch = 0;

	// getchar - 键盘缓存区 - 键盘
	// 例：键盘输入“a回车”，键盘缓存区中会有“a\n”
	//     首先getchar读取字符'a'，while判读不是EOF，再读取字符'\n'
	// 为什么getchar用int类型来储存：1.字符本质上是ASCII码值，2.EOF是-1，需要整数类型储存
	// EOF - enf of file - 文件结束的标志 - （-1）
	// ctrl+z - getchar读取结束
	// '\n'对于getchar来说也算是字符，所以会输出俩空行
	// 在进入该函数之后没有任何输入的情况下，依旧先输出俩空行的原因
	// 上个btanch函数中scanf把（例：（输入）5（回车））5拿走，剩下\n（回车）
	while ((ch = getchar()) != EOF) {
		printf("%c", ch);
		putchar(ch);
	}

	return 0;
}

int passWord() {

	char passWord[20] = { 0 };
	printf("输入密码:>");
	int judge = scanf("%s", passWord);

	printf("确认密码:>");

	int tmp = 0;
	while ((tmp = getchar()) != '\n'); {
		;
	}

	int ch = getchar();
	if (ch == 'Y')
		printf("确认成功");
	else
		printf("确认有误");
	return 0;
}


// for循环语句

int loop2() {

	for (int i = 1; i <= 10; i++) {
		
		if (i == 5) {
			// break;  // 打印 1 2 3 4
			continue;  // 打印 1 2 3 4 6 7 8 9 10
		}

		printf("%d ", i);
	}


	// 判断部分省略则恒为真
	// for (int i = 0; ; i++)
	//  	printf("%d\n", i);

	return 0;
}


// do…while循环
int loop3() {

	int i = 0;
	do {

		printf("%d ", i);
		i++;

	} while (i <= 10);

	return 0;
}


// 练习
// 
// 1.计算n的阶乘
int factorial() {

	int sum = 1;
	int n = 0;
	printf("输入一个整数");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		sum *= i;
	}

	printf("%d\n", sum);  // 输入 5 ，打印 120
	
	return 0;
}

// 2.计算1!+2!+3!+…+10!
int factorial1() {
	// int sum1 = 1;
	int sum2 = 0;

	int sum01 = 1;
	int sum02 = 0;

	for (int n = 1; n <= 10; n++) {

		int sum1 = 1;  // 自我总结：把嵌套循环的的变量的初始化写在循环里更好
		               //           但要考虑局部变量的问题
		for (int i = 1; i <= n; i++) {
			sum1 *= i;
		}

		sum2 += sum1;
	}

	for (int i = 1; i <= 10; i++) {

		sum01 *= i;
		sum02 += sum01;
	}

	printf("%d\n", sum2);
	printf("%d\n", sum02);

	return 0;
}

// 二分查找（折半查找）
// 整体思路:如果目标数小于折中数，那么查找的范围在左。代码（right = mid - 1;）
//          如果目标数大于折中数，那么查找的范围在右。代码（left = mid + 1;）
int binarySearch() {
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 7;  // 要查找的数

	int sz = sizeof(arr) / sizeof(arr[0]);  // 数组的个数

	int left = 0;
	int right = sz;

	while (left <= right) {

		int mid = (left + right) / 2;
		
		if (arr[mid] < k)
			left = mid + 1;  // 这里
		
		else if (arr[mid] > k)
			right = mid - 1;  // 还有这里+-1的是一个判断循环的条件
		
		else {
			printf("已找到，下标为%d\n", mid);
			break;
		}
	}

	if (left > right)
		printf("已查询，无信息");

	return 0;
}