#include <stdio.h>
int main()
{
    int i;
    double a, b, sum = 0.0, n;
    a = 2.0;
    b = 1.0;
    sum += a / b;
    for (i = 1; i <= 10; i++)
    {
        b = a;
        a += i;
        sum += a / b;
    }
    printf("%lf", sum);
}