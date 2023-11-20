/* 线性循环队列的各种操作 */
#include "stdio.h"
#define MAXSIZE 100   /*顺序队列存储空间的总分配量*/
typedef int DataType; /*定义DataType为int类型*/
typedef struct        /*顺序队列存储类型*/
{
    DataType data[MAXSIZE]; /*存放顺序队列的数组*/
    int front;              /*记录队头元素位置的变量*/
    int rear;               /*记录队尾元素位置的变量*/
} SeqQueue;

void InitQueue(SeqQueue *Q)
{                           /*初始化队列函数*/
    Q->front = Q->rear = 0; /*指针初始化*/
}

int EmptyQueue(SeqQueue *Q)
{                            /*判断队空函数*/
    if (Q->front == Q->rear) /*队列为空*/
        return 1;
    else
        return 0;
}

int InQueue(SeqQueue *Q, DataType x)
{                                            /*入队函数*/
    if ((Q->rear + 1) % MAXSIZE == Q->front) /*队列为满*/
    {
        printf("队满，不能入队元素!");
        return 0; /*队满不能入队*/
    }
    else /*队不为满*/
    {
        Q->rear = (Q->rear + 1) % MAXSIZE; /*队尾指针增1*/
        Q->data[Q->rear] = x;
        return 1;
    }
}

int DeQueue(SeqQueue *Q, DataType *x)
{                      /*出队函数*/
    if (EmptyQueue(Q)) /*调用判空函数EmptyQueue(Q)，判断队列是否为空*/
    {
        printf("队空，不能出队元素!");
        return 0; /*队空不能出队*/
    }
    else /*队不为空*/
    {
        Q->front = (Q->front + 1) % MAXSIZE; /*队头指针增1*/
        *x = Q->data[Q->front];
        return 1;
    }
}

int GetFront(SeqQueue *Q, DataType *x)
{                      /*取队头函数*/
    if (EmptyQueue(Q)) /*调用判空函数EmptyQueue(Q)，判断队列是否为空*/
    {
        printf("队空，无队头元素!");
        return 0;
    }
    else /*队不为空*/
    {
        *x = Q->data[(Q->front + 1) % MAXSIZE];
        return 1;
    }
}

void ShowQueue(SeqQueue *Q)
{ /*显示队中元素函数*/
    int p = Q->front;
    if (p == Q->rear)
        printf("队列为空，无元素！\n");
    else
    {
        printf("从队头起队列中的各元素为：");
        while (p != Q->rear)
        {
            printf("%5d", Q->data[p + 1]);
            p++;
        }
    }
}

void Menu()
{ /*显示菜单子函数*/
    printf("\n                  顺序队列的各种操作");
    printf("\n =================================================");
    printf("\n|               1——初始化队列                  |");
    printf("\n|               2——入队操作                    |");
    printf("\n|               3——出队操作                    |");
    printf("\n|               4——求队头元素                  |");
    printf("\n|               5——显示队中所有元素            |");
    printf("\n|               0——返回                        |");
    printf("\n =================================================");
    printf("\n请输入菜单号（0-5）:");
}

main()
{
    int i, n, flag;
    SeqQueue Q;
    DataType x;
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
            InitQueue(&Q);
            printf("栈的初始化完成！");
            break;
        case '2':
            printf("请输入要入队的元素个数：");
            scanf("%d", &n);
            printf("请输入%d个入队的整数：", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                flag = InQueue(&Q, x);
            }
            if (flag == 1)
                printf("入队操作成功！");
            else
                printf("入队操作失败！");
            break;
        case '3':
            printf("请输入要出队的元素个数：");
            scanf("%d", &n);
            printf("出队的元素顺序依次为：");
            for (i = 0; i < n; i++)
            {
                flag = DeQueue(&Q, &x);
                printf("%5d", x);
            }
            if (flag == 1)
                printf("\n出队操作成功!");
            else
                printf("\n出队操作失败！");
            break;
        case '4':
            if (flag = GetFront(&Q, &x))
                printf("当前的队头元素值为：%d", x);
            break;
        case '5':
            ShowQueue(&Q);
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