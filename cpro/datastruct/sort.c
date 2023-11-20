#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100  /*线性表中最大元素个数*/
typedef int KeyType; /*关键字类型*/
typedef struct
{
    KeyType Key; /*关键字域*/
} LineList;      /*线性表元素类型*/

void InsertSort(LineList r[], int n)
{ /*直接插入排序函数*/
    int i, j;
    for (i = 2; i <= n; i++) /*从第2个元素开始依次插到前面已排好序列中*/
    {
        r[0] = r[i]; /*r[0]设为监视哨*/
        j = i - 1;
        while (r[0].Key < r[j].Key)
        { /*若要插入元素小于j位置元素，则后移j位置元素*/
            r[j + 1] = r[j];
            j = j - 1;
        }
        r[j + 1] = r[0]; /*将原来r[i]中的记录放入第j+1个空出的位置*/
    }
}

void ShellSort(LineList r[], int n)
{ /*希尔排序算法函数*/
    int i, j, d;
    d = n / 2; /*初始步长为表长的一半*/
    while (d > 0)
    {
        for (i = d; i <= n; i++)
        {
            r[0] = r[i]; /*设监视哨*/
            j = i - d;
            while (j >= 0 && r[0].Key < r[j].Key)
            {
                r[j + d] = r[j];
                j = j - d;
            }
            r[j + d] = r[0];
            j = j - d;
        }
        d = d / 2;
    }
}

void BubbleSort(LineList r[], int n)
{ /*冒泡排序算法函数*/
    int i, j, exchange;
    LineList temp;
    for (i = 1; i < n; i++) /*进行每趟比较*/
    {
        exchange = 0;                    /*本趟比较是否有交换变量*/
        for (j = 1; j <= n - i; j++)     /*从第1个到第n-i个记录进行一趟比较*/
            if (r[j].Key > r[j + 1].Key) /*若前面记录大于后面记录则交换*/
            {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                exchange = 1;
            }
        if (exchange == 0)
            return; /*若本趟比较没有交换，则提前结束循环*/
    }
}

void QuickSort(LineList r[], int first, int end)
{ /*快速排序算法函数*/
    int i, j;
    LineList temp;
    i = first;
    j = end;
    temp = r[i]; /*初始化*/
    while (i < j)
    {
        while (i < j && temp.Key <= r[j].Key)
            j--;
        r[i] = r[j];
        while (i < j && r[i].Key <= temp.Key)
            i++;
        r[j] = r[i];
    }
    r[i] = temp;
    if (first < i - 1)
        QuickSort(r, first, i - 1); /*对左侧分区域进行快速排序*/
    if (i + 1 < end)
        QuickSort(r, i + 1, end); /*对右侧分区域进行快速排序*/
}

void SelectSort(LineList r[], int n)
{                /*直接选择排序算法*/
    int i, j, k; /*k存放每趟比较的最大值的下标值*/
    LineList x;
    for (i = 1; i <= n; i++)
    {
        k = i;
        for (j = i + 1; j <= n; ++j)
            if (r[j].Key < r[k].Key) /*选择本次比较的最大值*/
                k = j;
        if (k != i) /*若k不等于当前位置i，则交换i和k位置的记录*/
        {
            x = r[i];
            r[i] = r[k];
            r[k] = x;
        }
    }
}

void Sift(LineList r[], int low, int high)
{ /*堆排序的筛选函数*/
    int i = low, j = 2 * i;
    LineList tmp = r[i]; /* 暂存“根”记录r[k] */
    while (j <= high)
    {
        if (j < high && r[j].Key < r[j + 1].Key)
            j = j + 1; /* 若存在右子树,且右子树根的关键字大,则沿右分支“筛选” */
        if (tmp.Key < r[j].Key)
        {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        } /* 继续筛选 */
        else
            break;
    }
    r[i] = tmp; /* r[k]填入到恰当的位置 */
}

void HeapSort(LineList r[], int n)
{ /*建堆函数*/
    int i;
    LineList tmp;
    for (i = n / 2; i >= 1; i--)
        Sift(r, i, n);
    for (i = n; i >= 1; i--) /* 自第n个记录开始进行筛选建堆 */
    {
        tmp = r[1];
        r[1] = r[i];
        r[i] = tmp;
        Sift(r, 1, i - 1);
    }
}

void Merge(LineList r[], int low, int mid, int high)
{ /*归并排序的两个相领有序段的合并函数*/
    LineList *r1;
    int i = low, j = mid + 1, k = 1; /*k是r1的下标,i,j分别为第1,2段的下标*/
    r1 = (LineList *)malloc((high - low + 1) * sizeof(LineList));
    while (i <= mid && j <= high)
        if (r[i].Key <= r[j].Key)
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    while (i <= mid)
        r1[k++] = r[i++];
    while (j <= high)
        r1[k++] = r[j++];
    for (k = 1, i = low; i <= high; k++, i++)
        r[i] = r1[k];
}

void MergePass(LineList r[], int length, int n)
{ /*完成一趟完整的合并函数*/
    int i;
    for (i = 1; i + 2 * length - 1 <= n; i = i + 2 * length) /*归并length长的两相邻子表*/
        Merge(r, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 <= n)
        Merge(r, i, i + length - 1, n);
}

void MergeSort(LineList r[], int n)
{ /*归并排序算法*/
    int length;
    for (length = 1; length <= n; length = 2 * length)
        MergePass(r, length, n);
}

void OutList(LineList r[], int n)
{
    int i;
    printf("排序后的记录为：");
    for (i = 1; i <= n; i++)
        printf("%5d", r[i]);
}

void MenuSort()
{ /*显示菜单子函数*/
    printf("\n                    排序子系统");
    printf("\n==================================================");
    printf("\n|               1——更新排序数据                |");
    printf("\n|               2——直接插入排序                |");
    printf("\n|               3——希尔排序                    |");
    printf("\n|               4——冒泡排序                    |");
    printf("\n|               5——快速排序                    |");
    printf("\n|               6——直接选择排序                |");
    printf("\n|               7——堆排序                      |");
    printf("\n|               8——归并排序                    |");
    printf("\n|               0——返回                        |");
    printf("\n==================================================");
    printf("\n请输入菜单号（0-8）:");
}

main()
{
    int i, n;
    LineList r[MAXSIZE];
    char ch1, ch2, a;
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y')
    {
        MenuSort();
        scanf("%c", &ch2);
        getchar();
        switch (ch2)
        {
        case '1':
            printf("请输入待排序表的长度：");
            scanf("%d", &n);
            printf("请输入%d个整数：", n);
            for (i = 1; i <= n; i++)
                scanf("%d", &r[i]);
            OutList(r, n);
            break;
        case '2':
            InsertSort(r, n);
            printf("进行直接插入排序，");
            OutList(r, n);
            break;
        case '3':
            ShellSort(r, n);
            printf("进行希尔插入排序，");
            OutList(r, n);
            break;
        case '4':
            BubbleSort(r, n);
            printf("进行冒泡排序，");
            OutList(r, n);
            break;
        case '5':
            QuickSort(r, 1, n);
            printf("进行快速排序，");
            OutList(r, n);
            break;
        case '6':
            SelectSort(r, n);
            printf("进行直接选择排序，");
            OutList(r, n);
            break;
        case '7':
            HeapSort(r, n);
            printf("进行堆排序，");
            OutList(r, n);
            break;
        case '8':
            MergeSort(r, n);
            printf("进行归并排序，");
            OutList(r, n);
            break;
        case '0':
            ch1 = 'n';
            break;
        default:
            printf("输入有误，请输入0-9进行选择！");
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
