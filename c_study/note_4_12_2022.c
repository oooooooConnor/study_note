#include <stdio.h>
// 什么是语句？
// c语言中由一个分号;隔开的就是一条语句。
// 比如： printf("Giao"); 、 1+2； 、 ;(空语句)

// 分支语句和循环语句

// 分支语句 - if 、 switch
// c语言是如何表示真假的 - 非0就是真 - 例：-1为真
 
int ifbranch() {
	
	int age = 60;

	if (age <= 18) {
		printf("少年\n");
	}
	else if (age >= 18 && age < 26) {
		printf("青年");
	}
	// else if (18 <= age < 26)  // 错误写法 - 先判断18 <= age为真
	//	printf("青年\n");
	
	else if (age >= 26 && age < 40) {
		printf("壮年\n");
	}
	else if (age >= 40 && age < 60) {
		printf("中年\n");
	}
	else if (age >= 60 && age < 100) {
		printf("老年\n");
	}
	else
		printf("Giao\n");
	
	// 例子 - {}
	if (age >= 18) {
		printf("成年\n");
	}
	else
		printf("未成年\n");
		printf("不能谈恋爱\n");  // 没实现需求 - 用{}啊靓仔

		int a = 0;
		int b = 2;

		// 悬空else
		if (a == 1)
			if (b == 2)
				printf("Giao!\n");
		else  // 这是陷阱 - else跟最近的if匹配 - 所以不打印
				printf("Giao?\n");
		
		// 一种代码风格
		int num = 0;
		// if (num = 5) - war
		// if (5 = num) - err
		if(5 == num)
			printf("Giao--\n");

		// 输出1-100之间的奇数
		// c++/c99支持在for里这样创建i
		for (int i = 1; i <= 100; i++) {

			if (0 != i % 2)
				printf("%d\n", i);
		}

		for (int i = 1; i <= 100; i += 2) {
			printf("%d\n", i);
		}
	
		return 0;
}


int main() {

	ifbranch();

	return 0;
}