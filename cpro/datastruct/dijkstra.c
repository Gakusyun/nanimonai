/* 迪杰斯特拉算法求单源最短路径 */
#include "stdio.h"
#define MAX 100
#define M 32767 /*图的邻接矩阵中的极大值*/

int Creatcost(int cost[][MAX])
{
   int vnum, anum, i, j, k, v1, v2, w;
   printf("\n请输入顶点数和边数:");
   scanf("%d%d", &vnum, &anum); /*读入顶点数和边数*/
   for (i = 0; i < vnum; i++)
      for (j = 0; j < vnum; j++)
         cost[i][j] = M; /*预设矩阵中各值为最大值M*/
   printf("请输入各边及权值（顶点序号从0开始）：\n");
   for (k = 0; k < anum; k++)
   {
      printf("起点 终点 权值:");
      scanf("%d%d%d", &v1, &v2, &w); /*读入各顶点及极值*/
      cost[v1][v2] = w;              /*将(v1,v2)设权值为w*/
   }
   return vnum; /*返回顶点数*/
}

void Dijkstra(int cost[][MAX], int n, int v)
{
   int dist[MAX], path[MAX], s[MAX]; /*数组s用于记录顶点v是否已经确定了最短路径，s[v]=1，顶点v已经确定了最短路径，s[i]=0，顶点v尚未确定最短路径。数组dist表示当前求出的从v0到vi的最短路径。数组path是路径数组，其中path[i]表示从源点到顶点vi之间的最短路径上vi的前驱顶点*/
   int mindis, i, j, u, pre;
   for (i = 0; i < n; i++)
   {
      dist[i] = cost[v][i]; /*初始化距离*/
      s[i] = 0;             /*辅助数组s[]置初值为0*/
      if (cost[v][i] < M)
         path[i] = v;
      else
         path[i] = -1;
   }
   s[v] = 1;
   path[v] = 0;
   for (i = 0; i < n; i++)
   {
      mindis = M;
      u = -1;
      for (j = 0; j < n; j++)
         if (s[j] == 0 && dist[j] < mindis)
         {
            u = j;
            mindis = dist[j];
         }
      if (u != -1)
      {
         s[u] = 1;
         for (j = 0; j < n; j++)
            if (s[j] == 0)
               if (cost[u][j] < M && dist[u] + cost[u][j] < dist[j])
               {
                  dist[j] = dist[u] + cost[u][j];
                  path[j] = u;
               }
      }
   }
   printf("\nDijkstra算法求解如下：");
   for (i = 0; i < n; i++)
   {
      if (i != v)
      {
         printf("\n%d->%d:", v, i);
         if (s[i] == 1)
         {
            printf("路径长度为%2d,", dist[i]);
            pre = i;
            printf("路径逆序为：");
            while (pre != v)
            {
               printf("%d,", pre);
               pre = path[pre];
            }
            printf("%d", pre);
         }
         else
            printf("不存在路径\n");
      }
   }
}

void main()
{
   int n;
   int cost[MAX][MAX];
   n = Creatcost(cost);
   Dijkstra(cost, n, 0);
   printf("\n");
}
