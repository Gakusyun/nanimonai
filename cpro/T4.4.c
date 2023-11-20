#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, n;
    n = 100;
    while (1)
    {
        a = n / 100;
        b = n - a * 100;
        b /= 10;
        c = n % 10;
        if (n == pow(a, 3) + pow(b, 3) + pow(c, 3))
            printf("%d ", n);
        if (n >= 500)
            break;
        n++;
    }
}