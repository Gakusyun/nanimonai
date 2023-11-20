#include <stdio.h>
float avg(int a, int b)
{
    return 0.5 * (a + b);
}
void main()
{
    int a, b;
    printf("输入两个数，用半角逗号隔开\n");
    scanf("%d,%d", &a, &b);
    printf("平均数是%f", avg(a, b));
}