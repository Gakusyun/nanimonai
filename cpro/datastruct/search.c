#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100  /*顺序表的表长*/
typedef int KeyType; /*关键字类型为int型*/
typedef struct
{
    KeyType key; /*存放关键字，KeyType为关键字类型*/
} SearchL;

int SeqSearch(SearchL r[], int n, KeyType k)
{ /*顺序查找算法函数，表中元素下标为1到n*/
    int i = n;
    r[0].key = k;         /*设元素r[o]为要查找的关键字k（即监视哨）*/
    while (r[i].key != k) /*从后向前顺序比较*/
        i--;
    return (i); /*返回查找元素下标，当为0时表示查找失败*/
}

int BinSearch(SearchL r[], int n, KeyType k)
{ /*折半查找算法函数，表中元素下标为1到n*/
    int low, high, mid;
    low = 1;
    high = n;           /*置区间初值*/
    while (low <= high) /*查找区间不为空时*/
    {
        mid = (low + high) / 2;
        if (k == r[mid].key)
            return (mid); /*找到待查元素*/
        else if (k < r[mid].key)
            high = mid - 1; /*未找到，继续在前半区间进行查找*/
        else
            low = mid + 1; /*未找到，继续在后半区间进行查找*/
    }
    return (0);
}

typedef struct /*分块查找的索引表类型*/
{
    KeyType key;   /*关键字*/
    int low, high; /*每块的低、高地址*/
} IdxType;

void CreatIdx(SearchL r[], IdxType idx[], int m, int n)
{                    /*分块查找的建立索引表算法函数*/
    int i, j, k = 0; /*k为索引表下标*/
    KeyType max;
    for (i = 0; i < m; i += n) /*在顺序表中进行分块*/
    {
        max = r[i].key;                          /*将最大值设为第i个元素关键字*/
        for (j = i + 1; j < i + n && j < m; j++) /*在每块中确定该块的最大值*/
            if (r[j].key > max)
                max = r[j].key;
        idx[k].key = max;            /*将该块最大值赋给索引表第k个元素的关键字*/
        idx[k].low = i;              /*将该块起始下标i赋给索引表第k个元素的低地址*/
        if (i + n - 1 <= m - 1)      /*若该块长度为m时*/
            idx[k].high = i + n - 1; /*将该块终止下标值赋给索引表第k个元素的高地址*/
        else                         /*若该块长度为小于m值（最后一块）时*/
            idx[k].high = m - 1;     /*将顺序表最大元素下标值赋给索引表第k个元素的高地址*/
        k++;                         /*索引表下票值加1*/
    }
}

int BlkSearch(SearchL r[], IdxType idx[], int m, KeyType k)
{ /*分块查找算法函数*/
    int low, high, mid, i, j, find = 0;
    i = 0;
    while (idx[i].key < k) /*当索引表的关键字小于查找关键字k时，在索引表中定位*/
        i++;
    low = idx[i].low;
    high = idx[i].high;
    while (low <= high && !find) /*当在索引表中找到该元素所在块时*/
    {                            /*在该索引表内进行折半查找*/
        mid = (low + high) / 2;
        if (k < idx[mid].key)
            high = mid - 1;
        else if (k > idx[mid].key)
            low = mid + 1;
        else
        {
            high = mid - 1;
            find = 1;
        }
    }
    if (low < m) /*当在索引表中有该元素所在块时*/
    {
        i = idx[low].low;  /*i赋为索引表该块的低地址*/
        j = idx[low].high; /*j赋为索引表该块的高地址*/
    }
    while (i < j && r[i].key != k) /*在顺序表的这个块内进行顺序查找*/
        i++;
    if (i >= j)
        return (-1); /*当没找到时返回-1*/

    else
        return (i); /*当找到时返回下标值i*/
}

typedef struct treenode /*二叉排序树的结点类型*/
{
    KeyType key;                      /*关键字*/
    struct treenode *lchild, *rchild; /*左、右孩子指针*/
} BTNode;

BTNode *BSTInsert(BTNode *bt, KeyType k)
{                       /*二叉排序树的元素插入函数*/
    BTNode *f, *p = bt; /*p指针指向二叉排序树的根结点*/
    while (p != NULL)   /*当p指针不为空时，由指针f确定插入位置的双亲结点*/
    {
        f = p;             /*指针f指向指针p所指结点*/
        if (p->key > k)    /*当p所指结点的关键字大于插入值时*/
            p = p->lchild; /*p移到它的左孩子结点上*/
        else
            p = p->rchild; /*p移到它的右孩子结点上*/
    }
    p = (BTNode *)malloc(sizeof(BTNode)); /*建立新结点*/
    p->key = k;                           /*将关键字k存入新结点的数据域*/
    p->lchild = p->rchild = NULL;         /*左、右孩子指针设为空*/
    if (bt == NULL)                       /*二叉树为空树时*/
        bt = p;                           /*新建结点作为二叉排序树的根结点*/
    else if (k < f->key)                  /*若插入关键字k小于其双亲结点关键字*/
        f->lchild = p;                    /*则插入为双亲结点的左孩子*/
    else
        f->rchild = p; /*则插入为双亲结点的右孩子*/
    return (bt);
}

BTNode *CreateBST(KeyType str[], int n)
{ /*建立二叉排序树函数*/
    int i = 0;
    BTNode *bt = NULL; /*初始化根结点为空*/
    while (i < n)      /*当建立没结束时*/
    {
        bt = BSTInsert(bt, str[i]); /*将第i个元素插入到二叉排序树中*/
        i++;
    }
    return (bt); /*返回根结点指针*/
}

void DispBStree(BTNode *bt)
{ /*用广义表显示二叉排序树函数*/
    if (bt != NULL)
    {
        printf("%d", bt->key); /*输出根结点的关键字*/
        if (bt->lchild != NULL || bt->rchild != NULL)
        {                           /*当根结点的左、右孩子指针不为空时*/
            printf("(");            /*输出左括号*/
            DispBStree(bt->lchild); /*输出该结点的左孩子*/
            if (bt->rchild != NULL) /*若其右指针不为空时*/
                printf(",");        /*输出逗号*/
            DispBStree(bt->rchild); /*输出该结点的右孩子*/
            printf(")");            /*输出右括号*/
        }
    }
}

BTNode *BSTDelete(BTNode *bt, KeyType k)
{ /*在二叉排序树t中删除关键字为k的节点函数*/
    BTNode *p, *f, *s, *q;
    p = bt;
    f = NULL;
    while (p) /*查找关键字为k的待删结点p*/
    {
        if (p->key == k)
            break; /*找到，则跳出查找循环*/
        f = p;     /*f指向p结点的双亲结点*/
        if (p->key > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (p == NULL)
        return bt;         /*若找不到，返回原来的二叉排序树*/
    if (p->lchild == NULL) /*p无左子树*/
    {
        if (f == NULL) /*p是原二叉排序树的根*/
            bt = p->rchild;
        else if (f->lchild == p)   /*p是f的左孩子*/
            f->lchild = p->rchild; /*将p的右子树链到f的左链上*/
        else                       /*p是f的右孩子*/
            f->rchild = p->rchild; /*将p的右子树链到f的右链上*/
        free(p);                   /*释放被删除的节点p*/
    }
    else /*p有左子树*/
    {
        q = p;
        s = p->lchild;
        while (s->rchild) /*在p的左子树中查找最右下结点*/
        {
            q = s;
            s = s->rchild;
        }
        if (q == p)
            q->lchild = s->lchild; /*将s的左子树链到q左孩子指针*/
        else
            q->rchild = s->lchild;
        p->key = s->key; /*将s的值赋给p*/
        free(s);
    }
    return bt;
}

BTNode *BSTSearch(BTNode *bt, KeyType k)
{ /*二叉排序树的元素查找函数*/
    if (bt == NULL)
        return (NULL); /*空树则返回空指针*/
    else
    {
        if (k == bt->key)                      /*关键字k等于根结点关键字*/
            return (bt);                       /*返回根结点指针*/
        else if (k < bt->key)                  /*关键字k小于根结点关键字*/
            return (BSTSearch(bt->lchild, k)); /*到根结点的左子树查找*/
        else
            return (BSTSearch(bt->rchild, k)); /*到根结点的右子树查找*/
    }
}

void MenuBTree()
{ /*显示二叉排序树子菜单函数*/
    printf("\n                      二叉排序树       ");
    printf("\n==================================================");
    printf("\n|               1------建立二叉排序树            |");
    printf("\n|               2------插入一个元素              |");
    printf("\n|               3------删除一个元素              |");
    printf("\n|               4------查找一个元素              |");
    printf("\n|               0------返回                      |");
    printf("\n==================================================");
    printf("\n请输入序号（0-4）选择要进行的操作:");
}

void BTFun()
{ /*二叉排序树子函数*/
    KeyType str[100];
    BTNode *bt;
    int i, n, x, menux;
    MenuBTree();
    scanf("%d", &menux);
    do
    {
        switch (menux) /*判断进行何种操作*/
        {
        case 1: /*建立二叉排序树*/
            printf("请输入要生成二叉排序树的关键字的个数:");
            scanf("%d", &n);
            printf("请输入二叉排序树的各个关键字:");
            for (i = 0; i < n; i++)
                scanf("%d", &str[i]);
            bt = CreateBST(str, n);
            printf("建立的二叉排序树广义表表示法为:");
            DispBStree(bt);
            break;
        case 2: /*在二叉排序树中插入一个元素*/
            printf("请输入要插入的元素值: ");
            scanf("%d", &x);
            bt = BSTInsert(bt, x);
            printf("插入后的二叉排序树为: ");
            DispBStree(bt);
            break;
        case 3: /*在二叉排序树中删除一个元素*/
            printf("请输入要删除的元素:");
            scanf("%d", &x);
            bt = BSTDelete(bt, x);
            printf("删除元素%d后的二叉排序树为:", x);
            DispBStree(bt);
            break;
        case 4: /*在二叉排序树中查找某元素*/
            printf("请输入查找的元素值:");
            scanf("%d", &x);
            if ((BSTSearch(bt, x)) != NULL)
                printf("在二叉排序树中存在元素%d！", x);
            else
                printf("在二叉排序树中不存在元素%d！", x);
            break;
        case 0:
            return;
            break;
        default:
            printf("输入选项错误,请重新输入(0-4)!");
        }
        MenuBTree();
        scanf("%d", &menux);
    } while (1);
}

void Menu()
{ /*显示菜单子函数*/
    printf("\n                  查找子系统");
    printf("\n==================================================");
    printf("\n|               1——顺序查找                    |");
    printf("\n|               2——折半查找                    |");
    printf("\n|               3——分块查找                    |");
    printf("\n|               4——二叉树排序树查找            |");
    printf("\n|               0——返回                        |");
    printf("\n==================================================");
    printf("\n请输入菜单号（0-4）:");
}

main()
{
    SearchL r[MAXSIZE];
    IdxType idx[MAXSIZE];
    int i, m, n, x, k, address;
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
            printf("请输入表的元素个数(0-%d):", MAXSIZE - 1);
            scanf("%d", &n);
            printf("请输入%d个表中的关键字(整数):", n);
            for (i = 1; i <= n; i++)
                scanf("%d", &r[i].key);
            printf("请输入要查找的关键字:");
            scanf("%d", &x);
            if ((address = SeqSearch(r, n, x)) != 0)
                printf("该元素在表中的位置为:%d", address);
            else
                printf("该元素不在表中!");
            break;
        case '2':
            printf("请输入表的元素个数(0-%d):", MAXSIZE - 1);
            scanf("%d", &n);
            printf("请按照从小到大的顺序输入%d个关键字(为整数):", n);
            for (i = 1; i <= n; i++)
                scanf("%d", &r[i].key);
            printf("请输入要查找的关键字:");
            scanf("%d", &x);
            if ((address = BinSearch(r, n, x)) != 0)
                printf("该元素在表中的位置为:%d", address);
            else
                printf("该元素不在该有序表中!");
            break;
        case '3':
            printf("请输入表的元素个数(0-%d):", MAXSIZE - 1);
            scanf("%d", &m);
            printf("请输入表中的关键字(为整数)，要求块内无序，块间有序:\n");
            for (i = 0; i < m; i++)
                scanf("%d", &r[i].key);
            printf("表输入索引表每块的大小：");
            scanf("%d", &n);
            CreatIdx(r, idx, m, n);
            printf("\n建立的顺序表为:\n");
            for (i = 0; i < m; i++)
                printf("%6d", r[i].key);
            printf("\n索引表信息如下:");
            printf("\n低地址\t高地址\t最大关键字\n");
            if (m % n == 0)
                for (i = 0; i < m / n; i++)
                    printf("%5d\t%5d\t%5d\n", idx[i].low, idx[i].high, idx[i].key);
            else
                for (i = 0; i < m / n + 1; i++)
                    printf("%5d\t%5d\t%5d\n", idx[i].low, idx[i].high, idx[i].key);
            printf("请输入要查找的元素的关键字:");
            scanf("%d", &k);
            if ((address = BlkSearch(r, idx, 3, k)) != -1)
                printf("该元素在表中的位置为:%d", address + 1);
            else
                printf("该元素不在表中!");
            break;
        case '4':
            BTFun();
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