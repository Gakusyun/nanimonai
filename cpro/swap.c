#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 1, b = 2;
    swap(&a, &b);
    printf("%d %d", a, b);
}
