#include <stdio.h>
#include <malloc.h>
#define MAX 100
int count = 0;
typedef struct tnode
{
    char data;
    struct tnode *lchild, *rchild;
} BT;
BT *CreateBTree()
{
    BT *t;
    char ch;
    scanf("%c", &ch);
    getchar();
    if (ch == '0')
        t = NULL;
    else
    {
        t = (BT *)malloc(sizeof(BT));
        t->data = ch;
        printf("请输入%c结点的左孩子结点：", t->data);
        t->lchild = CreateBTree();
        printf("请输入%c结点的右孩子结点：", t->data);
        t->rchild = CreateBTree();
    }
    return t;
}

int CmpTree(BT *p, BT *q)
{
    if (p == NULL && q == NULL)
        return 1;
    if (p == NULL || q == NULL)
        return 0;
    if (p->data != q->data)
        return 0;
    return CmpTree(p->lchild, q->lchild) && CmpTree(p->rchild, q->rchild);
}
void ChangeLR(BT *T)
{
    struct BinaryTree *temp;
    if (T == NULL)
        return;
    T->lchild = T->lchild ^ T->rchild;
    T->rchild = T->lchild ^ T->rchild;
    T->lchild = T->lchild ^ T->rchild;
    ChangeLR(T->lchild);
    ChangeLR(T->rchild);
}
int main()
{
    BT *p, *q;
    printf("请输入第一棵二叉树的结点：\n");
    p = CreateBTree();
    printf("请输入第二棵二叉树的结点：\n");
    q = CreateBTree();
    if (CmpTree(p, q))
        printf("两棵二叉树相等\n");
    else
        printf("两棵二叉树不相等\n");
    return 0;
}
