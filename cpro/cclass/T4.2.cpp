#include <iostream> //22401330125 高学骏
int main()
{
	int a = 3, b = 0;
	a += a * 10;
	a = a * 10 + a / 10;
	b += a;
	b += a / 10;
	b += a / 100;
	std::cout << "s=" << b;
	return 0;
}
