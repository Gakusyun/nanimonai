/* 克鲁斯卡尔算法 */
#include "stdio.h"
#define MAX 100
typedef struct
{
	int u;	 /*边的起始顶点*/
	int v;	 /*边的终止顶点*/
	int w;	 /*边的权值*/
} Edge;		 /*边的类型定义*/
Edge E[MAX]; /*定义全局数组E，用于存储图的各条边*/

int CreateEdge()
{ /*建立边表算法*/
	int anum, i;
	printf("\n输入无向网的边数：");
	scanf("%d", &anum);
	for (i = 0; i < anum; i++)
	{
		printf("v1  v2  w=");
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
	}
	return anum;
}

void sort(int n)
{ /*为边表进行从小到大排序算法*/
	int i, j;
	Edge t;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (E[i].w > E[j].w)
			{
				t = E[i];
				E[i] = E[j];
				E[j] = t;
			}
}

int seeks(int set[], int v)
{ /*在边表中查看顶点v在哪个连通集合中*/
	int i = v;
	while (set[i] > 0)
		i = set[i];
	return (i);
}

void Kruskal(Edge E[], int n)

{				  /*E所表示的图是按权值从小到大排列的*/
	int set[MAX]; /*辅助标志数组*/
	int v1, v2, i;
	for (i = 0; i < MAX; i++)
		set[i] = 0; /*给set中的每个元素赋初值*/
	i = 0;			/*i表示待获取的生成树中的边数,初值为1*/
	while (i < n)	/*按边权递增顺序,逐边检查该边是否应加入到生成树中*/
	{
		v1 = seeks(set, E[i].u); /*确定顶点v所在的连通集*/
		v2 = seeks(set, E[i].v);
		if (v1 != v2) /*当v1,v2不在同一顶点集合,确定该边应当选入生成树*/
		{
			printf("(%d,%d)  %d\n", E[i].u, E[i].v, E[i].w);
			set[v1] = v2;
		}
		i++;
	}
}

main()
{
	int n;
	n = CreateEdge();
	sort(n);
	printf("\n最小生成树为:\n");
	Kruskal(E, n);
}
