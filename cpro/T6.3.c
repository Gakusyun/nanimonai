#include <stdio.h>
float cir(int a)
{
    return 2 * a * 3.14;
}
float area(int a)
{
    return 3.14 * a * a;
}
float sua(int a, int b)
{
    return 2 * 3.14 * a * a + 2 * a * 3.14 * b;
}
float v(int a, int b)
{
    return 3.14 * a * a * b;
}
int main()
{
    int r, h;
    printf("输入圆的半径和圆柱的高，用半角逗号隔开\n");
    scanf("%d,%d", &r, &h);
    printf("圆的周长是%f\n", cir(r));
    printf("圆的面积是%f\n", area(r));
    printf("圆柱的表面积是%f\n", sua(r, h));
    printf("圆柱的体积是%f\n", v(r, h));
    return 0;
}
