#include <stdio.h> //22401330125高学骏

void main()
{
    double p, w, s, d, f;

    printf("请输入运输路程（公里）和货物重量（吨）：");
    scanf("%lf,%lf", &s, &w);
    p = 5;
    switch ((int)s / 250)
    {
    case 0:
        d = 0.0;
        break;
    case 1:
        d = 0.02;
        break;
    case 2:
        d = 0.05;
        break;
    case 3:
        d = 0.08;
        break;
    case 4:
        d = 0.1;
        break;
    default:
        d = 0.15;
        break;
    }

    f = p * w * s * (1 - d);
    printf("货物基本运费：%.2f 元/吨公里\n", p);
    printf("货物重量：%.2f 吨\n", w);
    printf("运输路程：%.2f 公里\n", s);
    printf("折扣率：%.2f%%\n", d * 100);
    printf("总运费：%.2f 元\n", f);
}
