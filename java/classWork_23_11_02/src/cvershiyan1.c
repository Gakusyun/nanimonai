#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int f1, f2;
} Fraction;
Fraction plus(Fraction fr1, Fraction fr2)
{
    Fraction ans;
    ans.f1 = fr1.f1 * fr2.f2 + fr1.f2 * fr2.f1;
    ans.f2 = fr1.f2 * fr2.f2;
    return ans;
}
Fraction minus(Fraction fr1, Fraction fr2)
{
    Fraction ans;
    ans.f1 = fr1.f1 * fr2.f2 - fr1.f2 * fr2.f1;
    ans.f2 = fr1.f2 * fr2.f2;
    return ans;
}
Fraction multiply(Fraction fr1, Fraction fr2)
{
    Fraction ans;
    ans.f1 = fr1.f1 * fr2.f1;
    ans.f2 = fr1.f2 * fr2.f2;
    return ans;
}
Fraction division(Fraction fr1, Fraction fr2)
{
    Fraction ans;
    if (fr2.f1 == 0)
    {
        printf("除数不得为零\n");
        fr2.f1 = 1;
        fr2.f2 = 1;
    }
    ans.f1 = fr1.f1 * fr2.f2;
    ans.f2 = fr1.f2 * fr2.f1;
    return ans;
}
void prFrInt(Fraction fr)
{
    printf("%d/%d\n", fr.f1, fr.f2);
}
void prFrFlo(Fraction fr)
{
    printf("%f\n", (float)fr.f1 / (float)fr.f2);
}
Fraction Reduction(Fraction fr)
{
    for (int i = 2; i <= (fr.f1 > fr.f2 ? fr.f1 : fr.f2); i++)
    {
        if (fr.f1 % i == 0 && fr.f2 % i == 0)
        {
            fr.f1 /= 2;
            fr.f2 /= 2;
            i = 1;
        }
    }
    return fr;
}
void menu()
{
    printf("1.加\n");
    printf("2.减\n");
    printf("3.乘\n");
    printf("4.除\n");
    printf("5.打印（a/b）\n");
    printf("6.打印（浮点型）\n");
    printf("7.约分至最简\n");
    printf("0.退出\n");
    printf("输入要进行的操作（0~6)：");
}
Fraction defraction()
{
    Fraction fr;
    printf("输入分子（整形）：");
    scanf("%d", &fr.f1);
    printf("输入分母（整形）：");
    scanf("%d", &fr.f2);
    if (fr.f2 == 0)
    {
        printf("分母不得为0");
        fr.f1 = 1;
        fr.f2 = 1;
    }
    return fr;
}
int main()
{
    Fraction fr = defraction();
    int choise;
    while (1)
    {
        menu();
        scanf("%d", &choise);
        switch (choise)
        {
        case 0:
            return 0;
        case 1:
            fr = plus(fr, defraction());
            break;
        case 2:
            fr = minus(fr, defraction());
            break;
        case 3:
            fr = multiply(fr, defraction());
            break;
        case 4:
            fr = division(fr, defraction());
            break;
        case 5:
            prFrInt(fr);
            break;
        case 6:
            prFrFlo(fr);
            break;
        case 7:
            fr = Reduction(fr);
            break;
        default:
            printf("输入错误，请重新输入！\n");
            break;
        }
        system("pause");
        system("cls");
    }
}
