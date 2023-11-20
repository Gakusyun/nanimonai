#include <stdio.h>
#include <math.h>
void main()
{
    int i, j;
    scanf("%d", &i);
    if (i <= 1000)
    {
        j = sqrt(i);
        printf("%d", j);
    }
    else
        printf("over1000");
}
