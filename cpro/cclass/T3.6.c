#include <stdio.h> //22401330125高学骏

void main()
{
    int a, b, c;

    printf("请输入三角形的三条边长：\n");
    scanf("%d%d%d", &a, &b, &c);

    // if (a + b > c && a + c > b && b + c > a) {
    if (a == b && b == c)
    {
        printf("这是一个等边三角形\n");
    }
    else if (a == b || b == c || a == c)
    {
        printf("这是一个等腰三角形\n");
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    {
        printf("这是一个直角三角形\n");
    }
    else
    {
        printf("这是一个普通三角形\n");
    }
    //}
    /*else {
        printf("这无法构成一个三角形\n");
    }*/
}