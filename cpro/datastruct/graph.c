/*用邻接表存储的图子系统*/
#include "stdio.h"
#include "malloc.h"
#define MAX 100 /*最大顶点数*/
typedef char VertexType;
int visited[MAX]; /*全局变量，访问数组*/

typedef struct node
{
   int adjvex;        /*邻接点域*/
   struct node *next; /*指向下一邻接点的指针域*/
} EdgeNode;           /*定义边表结点*/

typedef struct vexnode
{
   VertexType data;     /*顶点域*/
   EdgeNode *firstedge; /*指向第一条边结点*/
} VHeadNode;            /*定义顶点表结点*/

typedef struct
{
   VHeadNode adjlist[MAX]; /*邻接表头结点数组*/
   int n, e;               /*顶点数，边数*/
} AdjList;                 /*图的邻接表类型*/

void CreateAGraph(AdjList *g, int flag)
{ /*生成无向图的邻接表函数*/
   int i, j, k;
   EdgeNode *p;
   if (flag == 0)
      printf("\n===========将建立一个无向图===========\n");
   else
      printf("\n===========将建立一个有向图===========\n");
   printf("请输入图的顶点数：");
   scanf("%d", &g->n);
   printf("请输入图的边数：");
   scanf("%d", &g->e);
   printf("\n请输入图的各顶点信息：\n");
   for (i = 0; i < g->n; i++) /*生成有n个顶点的顶点表*/
   {                          // getchar();                        /*接受上次输入的换行符*/
      printf("第%d个顶点信息：", i + 1);
      scanf("\n%c", &(g->adjlist[i].data)); /*读入顶点信息*/
      g->adjlist[i].firstedge = NULL;       /*点的边表头指针设为空*/
   }
   printf("\n请输入边的信息，输入格式为:序号1，序号2（序号依次为0、1、2...）：\n");
   for (k = 0; k < g->e; k++)
   {
      printf("请输入第%d条边：", k);
      scanf("\n%d,%d", &i, &j);
      /*将编号为i的结点添加到邻接表中*/
      p = (EdgeNode *)malloc(sizeof(EdgeNode));
      p->adjvex = j;
      p->next = g->adjlist[i].firstedge;
      g->adjlist[i].firstedge = p;
      /*将编号为j的结点添加到邻接表中，有向图不用添加该结点，去掉下面if语句*/
      if (flag == 0)
      {
         p = (EdgeNode *)malloc(sizeof(EdgeNode));
         p->adjvex = i;                     /*邻接点序号为i*/
         p->next = g->adjlist[j].firstedge; /*将新结点p插到顶点vi边表头*/
         g->adjlist[j].firstedge = p;
      }
   }
}

void DispAGraph(AdjList *g)
{ /*输出图的邻接表函数*/
   int i;
   EdgeNode *p;
   printf("\n图的邻接表表示如下：\n");
   for (i = 0; i < g->n; i++)
   {
      printf("%2d [%c]", i, g->adjlist[i].data);
      p = g->adjlist[i].firstedge;
      while (p != NULL)
      {
         printf("-->[%d]", p->adjvex);
         p = p->next;
      }
      printf("\n");
   }
}

void DFS(AdjList *g, int vi)
{ /*用邻接表存储的图以顶点vi开始深度优先遍历函数*/
   EdgeNode *p;
   printf("(%d,", vi);
   printf("%c)", g->adjlist[vi].data);
   visited[vi] = 1;
   p = g->adjlist[vi].firstedge;
   while (p != NULL)
   {
      if (visited[p->adjvex] == 0)
         DFS(g, p->adjvex);
      p = p->next;
   }
}

void BFS(AdjList *g, int vi)
{ /*用邻接表存储的图以顶点vi开始广度优先遍历函数*/
   int i, v, visited[MAX];
   int qu[MAX], front = 0, rear = 0; /*定义循环队列*/
   EdgeNode *p;
   for (i = 0; i < g->n; i++) /*辅助的访问数组赋初值*/
      visited[i] = 0;
   printf("(%d,", vi); /*输出起始访问顶点*/
   printf("%c)", g->adjlist[vi].data);
   visited[vi] = 1;
   rear = (rear + 1) % MAX; /*队尾指针后移*/
   qu[rear] = vi;           /*将vi入队*/
   while (front != rear)    /*当队不空时*/
   {
      front = (front + 1) % MAX;
      v = qu[front];               /*将队头元素出队，赋给顶点v*/
      p = g->adjlist[v].firstedge; /*将顶点v的下一条邻接边顶点指针赋给p*/
      while (p != NULL)
      {
         if (visited[p->adjvex] == 0) /*若未访问过*/
         {
            visited[p->adjvex] = 1;                    /*访问数组该元素置1，已访问*/
            printf("(%d,", p->adjvex);                 /*输出该顶点编号*/
            printf("%c)", g->adjlist[p->adjvex].data); /*输出该顶点信息*/

            rear = (rear + 1) % MAX; /*队尾指针后移*/
            qu[rear] = p->adjvex;    /*将p所指的顶点入队*/
         }
         p = p->next; /*p指针后移*/
      }
   }
}

void MenuGraph() /*显示菜单子函数*/
{
   printf("\n                    图子系统");
   printf("\n==================================================");
   printf("\n|               1——更新邻接表                  |");
   printf("\n|               2——深度优先遍历                |");
   printf("\n|               3——广度优先遍历                |");
   printf("\n|               0——返回                        |");
   printf("\n==================================================");
   printf("\n请输入菜单号（0-3）:");
}

main() /*主函数*/
{
   int i, f;
   char ch1, ch2, a;
   AdjList g;
   ch1 = 'y';
   while (ch1 == 'y' || ch1 == 'Y')
   {
      MenuGraph();
      scanf("%c", &ch2);
      getchar();
      switch (ch2)
      {
      case '1':
         printf("要建立的是有向图（1）还是无向图（0），请选择（输入1或0）：");
         scanf("%d", &f);
         CreateAGraph(&g, f);
         DispAGraph(&g);
         break;
      case '2':
         printf("请输入开始进行深度遍历的顶点序号（序号从0开始编号）：");
         scanf("%d", &f);
         printf("\n从顶点%d开始的深度优先遍历序列为：", f);
         for (i = 0; i < g.n; i++)
            visited[i] = 0;
         DFS(&g, f);
         break;
      case '3':
         printf("请输入开始进行广度遍历的顶点序号（序号从0开始）：");
         scanf("%d", &i);
         printf("\n从顶点%d开始的广度优先遍历序列为：", i);
         BFS(&g, i);
         break;
      case '0':
         ch1 = 'n';
         break;
      default:
         printf("输入有误，请输入0-3进行选择！");
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
