#include <stdio.h>
#include <math.h>

int main()
{
    double pop2010 = 133972;
    double pop2021 = 141178;
    double growth_rate = pow((pop2021 / pop2010), (1.0 / 11.0)) - 1;
    printf("��ƽ��������Ϊ��%.2f%%\n", growth_rate * 100);
    double pop2030 = pop2021 * pow((1 + growth_rate), (2030 - 2021));
    printf("2030���˿�����Ϊ��%.2f����\n", pop2030 / 10000);
    double max_growth_rate = log(1600.0 / pop2021) / 30.0;
    printf("�˿����������Ϊ��%.2f%%\n", max_growth_rate * 100);
    return 0;
}