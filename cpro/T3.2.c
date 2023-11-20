#include <stdio.h>
void main()
{
    int a, b, c, temp;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b)
    {
        a = temp;
        a = b;
        b = temp;
    }
    if (b < c)
    {
        b = temp;
        b = c;
        c = temp;
    }
    if (a < b)
    {
        a = temp;
        a = b;
        b = temp;
    }
    printf("%d,%d,%d", a, b, c);
}
