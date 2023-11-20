#include <stdio.h>
void main()
{
    int i, j, k;
    i = j = 0;
    k = 1;
    if (i > j ? (j--) : (i--))
        k++;
    printf("%d,%d,%d", i, j, k);
}