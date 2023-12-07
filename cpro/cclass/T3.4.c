#include <stdio.h>
void main()
{
    int num;
    scanf("%d", &num);
    if (num % 2 == 0)
        if (num % 3 == 0)
            printf("是");
        else
            printf("否");
}