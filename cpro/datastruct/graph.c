/*���ڽӱ�洢��ͼ��ϵͳ*/
#include "stdio.h"
#include "malloc.h"
#define MAX 100 /*��󶥵���*/
typedef char VertexType;
int visited[MAX]; /*ȫ�ֱ�������������*/

typedef struct node
{
   int adjvex;        /*�ڽӵ���*/
   struct node *next; /*ָ����һ�ڽӵ��ָ����*/
} EdgeNode;           /*����߱���*/

typedef struct vexnode
{
   VertexType data;     /*������*/
   EdgeNode *firstedge; /*ָ���һ���߽��*/
} VHeadNode;            /*���嶥�����*/

typedef struct
{
   VHeadNode adjlist[MAX]; /*�ڽӱ�ͷ�������*/
   int n, e;               /*������������*/
} AdjList;                 /*ͼ���ڽӱ�����*/

void CreateAGraph(AdjList *g, int flag)
{ /*��������ͼ���ڽӱ���*/
   int i, j, k;
   EdgeNode *p;
   if (flag == 0)
      printf("\n===========������һ������ͼ===========\n");
   else
      printf("\n===========������һ������ͼ===========\n");
   printf("������ͼ�Ķ�������");
   scanf("%d", &g->n);
   printf("������ͼ�ı�����");
   scanf("%d", &g->e);
   printf("\n������ͼ�ĸ�������Ϣ��\n");
   for (i = 0; i < g->n; i++) /*������n������Ķ����*/
   {                          // getchar();                        /*�����ϴ�����Ļ��з�*/
      printf("��%d��������Ϣ��", i + 1);
      scanf("\n%c", &(g->adjlist[i].data)); /*���붥����Ϣ*/
      g->adjlist[i].firstedge = NULL;       /*��ı߱�ͷָ����Ϊ��*/
   }
   printf("\n������ߵ���Ϣ�������ʽΪ:���1�����2���������Ϊ0��1��2...����\n");
   for (k = 0; k < g->e; k++)
   {
      printf("�������%d���ߣ�", k);
      scanf("\n%d,%d", &i, &j);
      /*�����Ϊi�Ľ����ӵ��ڽӱ���*/
      p = (EdgeNode *)malloc(sizeof(EdgeNode));
      p->adjvex = j;
      p->next = g->adjlist[i].firstedge;
      g->adjlist[i].firstedge = p;
      /*�����Ϊj�Ľ����ӵ��ڽӱ��У�����ͼ������Ӹý�㣬ȥ������if���*/
      if (flag == 0)
      {
         p = (EdgeNode *)malloc(sizeof(EdgeNode));
         p->adjvex = i;                     /*�ڽӵ����Ϊi*/
         p->next = g->adjlist[j].firstedge; /*���½��p�嵽����vi�߱�ͷ*/
         g->adjlist[j].firstedge = p;
      }
   }
}

void DispAGraph(AdjList *g)
{ /*���ͼ���ڽӱ���*/
   int i;
   EdgeNode *p;
   printf("\nͼ���ڽӱ��ʾ���£�\n");
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
{ /*���ڽӱ�洢��ͼ�Զ���vi��ʼ������ȱ�������*/
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
{ /*���ڽӱ�洢��ͼ�Զ���vi��ʼ������ȱ�������*/
   int i, v, visited[MAX];
   int qu[MAX], front = 0, rear = 0; /*����ѭ������*/
   EdgeNode *p;
   for (i = 0; i < g->n; i++) /*�����ķ������鸳��ֵ*/
      visited[i] = 0;
   printf("(%d,", vi); /*�����ʼ���ʶ���*/
   printf("%c)", g->adjlist[vi].data);
   visited[vi] = 1;
   rear = (rear + 1) % MAX; /*��βָ�����*/
   qu[rear] = vi;           /*��vi���*/
   while (front != rear)    /*���Ӳ���ʱ*/
   {
      front = (front + 1) % MAX;
      v = qu[front];               /*����ͷԪ�س��ӣ���������v*/
      p = g->adjlist[v].firstedge; /*������v����һ���ڽӱ߶���ָ�븳��p*/
      while (p != NULL)
      {
         if (visited[p->adjvex] == 0) /*��δ���ʹ�*/
         {
            visited[p->adjvex] = 1;                    /*���������Ԫ����1���ѷ���*/
            printf("(%d,", p->adjvex);                 /*����ö�����*/
            printf("%c)", g->adjlist[p->adjvex].data); /*����ö�����Ϣ*/

            rear = (rear + 1) % MAX; /*��βָ�����*/
            qu[rear] = p->adjvex;    /*��p��ָ�Ķ������*/
         }
         p = p->next; /*pָ�����*/
      }
   }
}

void MenuGraph() /*��ʾ�˵��Ӻ���*/
{
   printf("\n                    ͼ��ϵͳ");
   printf("\n==================================================");
   printf("\n|               1���������ڽӱ�                  |");
   printf("\n|               2����������ȱ���                |");
   printf("\n|               3����������ȱ���                |");
   printf("\n|               0��������                        |");
   printf("\n==================================================");
   printf("\n������˵��ţ�0-3��:");
}

main() /*������*/
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
         printf("Ҫ������������ͼ��1����������ͼ��0������ѡ������1��0����");
         scanf("%d", &f);
         CreateAGraph(&g, f);
         DispAGraph(&g);
         break;
      case '2':
         printf("�����뿪ʼ������ȱ����Ķ�����ţ���Ŵ�0��ʼ��ţ���");
         scanf("%d", &f);
         printf("\n�Ӷ���%d��ʼ��������ȱ�������Ϊ��", f);
         for (i = 0; i < g.n; i++)
            visited[i] = 0;
         DFS(&g, f);
         break;
      case '3':
         printf("�����뿪ʼ���й�ȱ����Ķ�����ţ���Ŵ�0��ʼ����");
         scanf("%d", &i);
         printf("\n�Ӷ���%d��ʼ�Ĺ�����ȱ�������Ϊ��", i);
         BFS(&g, i);
         break;
      case '0':
         ch1 = 'n';
         break;
      default:
         printf("��������������0-3����ѡ��");
      }
      if (ch2 != '0')
      {
         printf("\n���س�����������������������˵���\n");
         a = getchar();
         if (a != '\xA')
         {
            getchar();
            ch1 = 'n';
         }
      }
   }
}
