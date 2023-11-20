#include <stdio.h>
#include <math.h>
#define pi 3.14
int main()
{
    int r = 3, h = 5;
    float s, v;
    s = 2 * pi * r;
    v = pi * pow(r, 2) * h;
    printf("s=%f\nv=%f", s, v);
    return 0;
}
