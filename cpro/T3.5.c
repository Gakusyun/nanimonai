#include <stdio.h> //22401330125��ѧ��

void main()
{
    double p, w, s, d, f;

    printf("����������·�̣�����ͻ����������֣���");
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
    printf("��������˷ѣ�%.2f Ԫ/�ֹ���\n", p);
    printf("����������%.2f ��\n", w);
    printf("����·�̣�%.2f ����\n", s);
    printf("�ۿ��ʣ�%.2f%%\n", d * 100);
    printf("���˷ѣ�%.2f Ԫ\n", f);
}
