#include <stdio.h> //22401330125 高学骏
int main()
{

	int i; // 定义循环控制变量i
	for (i = 50; i <= 100; i++)
		if (i % 3 != 0) // 循环体
			printf("%5d", i);
}
