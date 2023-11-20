#include <stdio.h>
int main()
{
    int n, s = 0, t = 1;
    for (n = 1; n <= 3; n++)
    {
        t = t * n;
        s = s + t;
        printf("%d", s);
    }
}
