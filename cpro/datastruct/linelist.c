/*顺序表的各种操作程序*/
#include <stdio.h>
#define MAXLEN 100    /*定义常量MAXLEN为100表示存储空间总量*/
typedef int DataType; /*定义ElemType为int类型*/
typedef struct        /*顺序表存储类型*/
{
    DataType data[MAXLEN]; /*存放线性表的数组*/
    int Length;            /*Length是顺序表的长度*/
} SeqList;

void InitList(SeqList *L)
{                  /*初始化顺序表L函数*/
    L->Length = 0; /*初始化顺序表为空*/
}

void CreateList(SeqList *L, int n)
{ /*建立顺序表并输入多个元素函数*/
    int i;
    printf("请输入%d个整数：", n);
    for (i = 0; i < n; i++)
        scanf("%d", &L->data[i]);
    L->Length = i; /*设线性表的长度为i*/
}

int GetElem(SeqList *L, int i, DataType *x)
{ /*获取顺序表中第i位中元素函数*/
    if (i < 1 || i > L->Length)
        return 0;
    else
    {
        *x = L->data[i - 1];
        return 1;
    }
}

int Locate(SeqList *L, DataType x)
{ /*在顺序表L中定位元素x函数*/
    int i = 0;
    while (i < L->Length && L->data[i] != x)
        i++;
    if (i >= L->Length)
        return 0;
    else
        return i + 1; /*返回的是元素位置*/
}

int InsElem(SeqList *L, int i, DataType x)
{ /*在顺序表L中在第i位中插入新元素x函数*/
    int j;
    if (L->Length >= MAXLEN)
    {
        printf("顺序表已满！");
        return -1; /*表满，不能插入*/
    }
    if (i < 1 || i > L->Length + 1) /*检查给定的插入位置的正确性*/
    {
        printf("插入位置出错！");
        return 0;
    }
    if (i == L->Length + 1)
    {
        L->data[i - 1] = x;
        L->Length++;
        return 1; /*插入的位置为表尾，则不需移动直接插入即可*/
    }
    for (j = L->Length - 1; j >= i - 1; j--) /*结点移动*/
        L->data[j + 1] = L->data[j];
    L->data[i - 1] = x; /*新元素插入*/
    L->Length++;        /*顺序表长度增1 */
    return 1;           /*插入成功，返回*/
}

int DelElem(SeqList *L, int i, DataType *x)
{ /*在顺序表L中删除第i位元素函数*/
    int j;
    if (L->Length == 0)
    {
        printf("顺序表为空！");
        return 0; /*表空，不能删除*/
    }
    if (i < 1 || i > L->Length) /*检查是否空表及删除位置的合法性*/
    {
        printf("不存在第i个元素");
        return 0;
    }
    *x = L->data[i - 1];            /*用指针变量*x返回删除的元素值*/
    for (j = i; j < L->Length; j++) /*结点移动*/
        L->data[j - 1] = L->data[j];
    L->Length--; /*顺序表长度减1*/
    return 1;    /*删除成功，返回*/
}

void DispList(SeqList *L)
{ /*显示输出顺序表L的每个元素函数*/
    int i;
    for (i = 0; i < L->Length; i++)
        printf("%5d ", L->data[i]);
}

void Menu()
{ /*显示菜单子函数*/
    printf("\n                  顺序表的各种操作");
    printf("\n==================================================");
    printf("\n|              1——建立顺序表                   |");
    printf("\n|              2——插入元素                     |");
    printf("\n|              3——删除元素                     |");
    printf("\n|              4——按位置查找元素               |");
    printf("\n|              5——按元素值查找其在表中位置     |");
    printf("\n|              6——求顺序表的长度               |");
    printf("\n|              0——返回                         |");
    printf("\n==================================================");
    printf("\n请输入菜单号（0-6）:");
}

main()
{
    SeqList L;
    DataType x;
    int n, i, loc;
    char ch1, ch2, a;
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y')
    {
        Menu();
        scanf("%c", &ch2);
        getchar();
        switch (ch2)
        {
        case '1':
            InitList(&L);
            printf("请输入建立线性表的个数：");
            scanf("%d", &n);
            CreateList(&L, n);
            printf("建立的线性表为:");
            DispList(&L);
            break;
        case '2':
            printf("请输入要插入的位置：");
            scanf("%d", &i);
            printf("请输入要插入的元素值：");
            scanf("%d", &x);
            if (InsElem(&L, i, x))
            {
                printf("已成功在第%d的位置上插入%d，插入后的线性表为：\n", i, x);
                DispList(&L);
            }
            else
                printf("输入插入的参数错误!");
            break;
        case '3':
            printf("请输入要删除元素的位置：");
            scanf("%d", &i);
            if (DelElem(&L, i, &x))
            {
                printf("已成功在第%d的位置上删除%d，删除后的线性表为：\n", i, x);
                DispList(&L);
            }
            else
                printf("\n输入删除的参数错误!");
            break;
        case '4':
            printf("请输入要查看表中元素位置(从1开始)：");
            scanf("%d", &i);
            if (GetElem(&L, i, &x))
                printf("当前线性表第%d个元素的值为：%d", i, x);
            else
                printf("输入的位置错误!");
            break;
        case '5':
            printf("请输入要查找的元素值为：");
            scanf("%d", &x);
            loc = Locate(&L, x);
            if (loc)
                printf("查找元素值为%d的位置为：%d", x, loc);
            else
                printf("该表中无此元素!");
            break;
        case '6':
            printf("当前线性表的长度为：%d", L.Length);
            break;
        case '0':
            ch1 = 'n';
            break;
        default:
            printf("输入有误，请输入0-4进行选择！");
        }
        if (ch2 != '0')
        {
            printf("\n按回车键继续，按任意键返回主菜单！\n");
            a = getchar();
            if (a != '\xA')
            {
                getchar();
                ch1 = 'n';
            }
        }
    }
}
