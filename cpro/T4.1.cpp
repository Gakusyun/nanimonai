#include <stdio.h> //22401330125 高学骏
int fac(int a)
{
	int b;
	if (a == 0 || a == 1)
		return 1;
	b = a;
	b--;
	while (b)
	{
		a *= b;
		b--;
	}
	return a;
}
int main()
{
	int s, a = 1, b = 3, c = 5;
	s = fac(a) + fac(b) + fac(c);
	printf("s=%d\n", s);
	return 0;
}
