#include <stdio.h>
#define MAXLEN 100
typedef struct /*定义结构体*/
{
	int weight;					/*定义一个整型权值变量*/
	int lchild, rchild, parent; /*定义左、右孩子及双亲指针*/
} HTNode;
typedef HTNode HT[MAXLEN]; /*向量类型*/
int n;
void InitHFMT(HT T) /*初始化子函数*/
{
	int i;
	printf("\n请输入共有多少个权值(小于100)：");
	scanf("%d", &n);
	for (i = 0; i < 2 * n - 1; i++)
	{
		T[i].weight = 0;
		T[i].lchild = -1;
		T[i].rchild = -1;
		T[i].parent = -1;
	}
}
void InputWeight(HT T) /*输入权值子函数*/
{
	int w, i;
	for (i = 0; i < n; i++)
	{
		printf("输入第%d个权值:", i + 1);
		scanf("%d", &w);
		getchar();
		T[i].weight = w;
	}
}
void SelectMin(HT T, int i, int *p1, int *p2) /*选择两个结点中小的结点*/
{
	long min1 = 888888, min2 = 888888; /*预设两个值，并使它大于可能出现的最大权值*/
	int j;
	for (j = 0; j <= i; j++)
	{
		if (T[j].parent == -1)
		{
			if (min1 > T[j].weight)
			{
				min1 = T[j].weight; /*找出最小的权值*/
				*p1 = j;			/*/通过*p1带回序号*/
			}
		}
	}
	for (j = 0; j <= i; j++)
	{
		if (T[j].parent == -1)
		{
			if (min2 > T[j].weight && j != (*p1))
			{
				min2 = T[j].weight; /*找出次最小的权值*/
				*p2 = j;			/*通过*p2带回序号*/
			}
		}
	}
}

void CreatHFMT(HT T) /*构造哈夫曼树，T[2*n-1]为其根结点*/
{
	int i, p1, p2;
	InitHFMT(T);
	InputWeight(T);
	for (i = n; i < 2 * n - 1; i++)
	{
		SelectMin(T, i - 1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].lchild = T[p1].weight;
		T[i].rchild = T[p2].weight;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void PrintHFMT(HT T) /*输出向量状态表*/
{

	int i, k = 0;
	printf("\n哈夫曼树的各边显示：\n");
	for (i = 0; i < 2 * n - 1; i++)
		while (T[i].lchild != -1)
		{
			printf("(%d,%d),(%d,%d)\n", T[i].weight, T[i].lchild, T[i].weight, T[i].rchild);
			break;
		}
}

void hfnode(HT T, int i, int j)
{
	j = T[i].parent;
	if (T[j].rchild == T[i].weight)
		printf("1");
	else
		printf("0");
	if (T[j].parent != -1)
		i = j, hfnode(T, i, j);
}
void huffmannode(HT T) /*求哈夫曼编码*/
{
	int i, j, a;
	printf("\n输入的权值的对应哈夫曼编码：");
	for (i = 0; i < n; i++)
	{
		j = 0;
		a = i;
		printf("\n%i的编码为：", T[i].weight);
		hfnode(T, i, j);
		i = a;
	}
}

void main() /*主函数*/
{
	HT HT;
	CreatHFMT(HT);
	PrintHFMT(HT);
	huffmannode(HT);
	printf("\n	");
}
