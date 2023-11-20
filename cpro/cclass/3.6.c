#include <stdio.h> //22401330125高学骏
void main()
{
	float a, b;
	char c;
	printf("input expression:a(+、-、*、/)b\n");
	scanf("%f%c%f", &a, &c, &b);
	switch (c)
	{
	case '+':
		printf("%f\n", a + b);
		break;
	case '-':
		printf("%f\n", a - b);
		break;
	case '*':
		printf("%f\n", a * b);
		break;
	case '/':
		if (b == 0)
			printf("division by zero\n");
		else
			printf("%f\n", a / b);
		break;
	default:
		printf("input error\n");
	}
}
