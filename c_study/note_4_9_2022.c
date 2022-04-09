#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {

	extern int choose();
	//choose();
	
	if (choose() == 1) {
		
		extern int cycle();
		cycle();
	}

	extern int sum();
	sum();

	extern int array();
	array();

	return 0;
}

//选择语句

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

//循环语句
//小樱 - 300次变身 - 成功

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

//函数
//数学 - f(x)=2*x+5
//c
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

//数组

int array() {

	//int a = 1;
	//int b = 2;
	//int c = 3;
	//int d = 4;
	//……

	//数组 - 一组相同类型的元素的集合
	//10个整型1-10存起来
	//数组是用下标来访问的，第一个下标为0 - 可以用监视窗口验证
	//arr[0]=1, arr[1]=2, arr[2]=3……
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0;
	while (i < 10) {

		printf("%d\n", arr[i]);
		i++;
	}
	
	char ch[5] = { 'a', 'b', 'c' };  //不完全初始化，剩余的默认为0
	return 0;
}