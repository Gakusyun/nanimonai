/*普里姆算法*/
#include <stdio.h>
#define MAX 100 /*图中最大顶点个数*/
#define M 32767 /*32767代表无穷大*/

int Creatcost(int cost[][MAX])
{ /*生成无向网的邻接矩阵算法*/
   int vnum, anum, i, j, k, v1, v2, w;
   printf("\n请输入顶点数和边数:");
   scanf("%d%d", &vnum, &anum); /*读入顶点数和边数*/
   for (i = 0; i < vnum; i++)
      for (j = 0; j < vnum; j++)
         cost[i][j] = M; /*预设矩阵中各值为最大值M*/
   printf("请输入各边及权值（顶点序号从1开始）：\n");
   for (k = 0; k < anum; k++)
   {
      printf("v1 v2 w :");
      scanf("%d%d%d", &v1, &v2, &w); /*读入各顶点及极值*/
      cost[v1][v2] = w;              /*将(v1,v2)设权值为w*/
      cost[v2][v1] = w;              /*无向图中将(v2,v1)设权值为w*/
   }
   return vnum; /*返回顶点数*/
}

void Prim(int c[MAX][MAX], int n)
{ /*己知图的顶点为{0,1,...,n-1},c[i][j]和c[j][i]为边(i,j)的权,打印最小生成树的每条边*/
   int i, j, k, min, lowcost[MAX], closest[MAX];
   for (i = 1; i < n; i++) /*从顶点0开始*/
   {
      lowcost[i] = c[0][i]; /*将lowcost数组中各元素设为从顶点0到各顶点的权值*/
      closest[i] = 0;       /*依附于该边的顶点为0*/
      printf("lowcost[%d]=%d,closest[%d]=%d\n", i, lowcost[i], i, closest[i]);
   }
   closest[0] = -1;        /*置初值为-1*/
   for (i = 1; i < n; i++) /*从U之外求离U中某一顶点最近的顶点*/
   {
      min = M;
      k = i;
      for (j = 0; j < n; j++) /*从顶点1开始找各权值中最小值及依附顶点k*/
      {
         if (lowcost[j] < min && closest[j] != -1)
         {
            min = lowcost[j]; /*最小值设为当前边的权值*/
            k = j;            /*此这依附顶点为j*/
         }
      }
      printf("(%d,%d) 权值%d\n", closest[k], k, lowcost[k]); /*打印生成树该边及其权值*/
      printf("lowcost[%d]=%d,closest[%d]=%d\n", j, lowcost[j], j, closest[j]);
      closest[k] = -1;        /*k加入到U中*/
      for (j = 1; j < n; j++) /*设顶点k为下次查找的起始点*/
         if (closest[j] != -1 && c[k][j] < lowcost[j])
         {
            lowcost[j] = c[k][j];
            closest[j] = k;
         }
   }
}

main()
{
   int n; /*图中顶点个数*/
   int cost[MAX][MAX];
   n = Creatcost(cost);
   printf("\n最小生成树为:\n");
   Prim(cost, n); /*调用普里姆算法*/
}
