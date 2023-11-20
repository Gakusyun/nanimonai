#include <stdio.h>
#include <math.h>
int main()
{
    int a, b = -1, c;
    scanf("%d", &a);
    if (a < 0)
    {
        printf("- ");
        a *= -1;
    }
    while (c)
    {
        b++;
        c = a / pow(10, b);
    }
    while (b)
    {
        b--;
        c = a / pow(10, b);
        printf("%d ", c);
        a -= c * pow(10, b);
    }
    return 0;
}