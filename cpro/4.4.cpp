#include <stdio.h> //22401330125 ��ѧ��
int main()
{
    int n, t;
    n = 1;
    t = 1;
    while (t <= 5)
    {
        n = n * t;
        t = t + 1;
    }
    printf("%d", n);
}
