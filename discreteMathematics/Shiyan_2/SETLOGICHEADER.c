
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#include "SETLOGICHEADER.h"
 
 
//union operating
static void arrayset_union_oper(ArraySet set1, ArraySet set2, ArraySet* resu)
{
	int i = 0;
	for(i = 0; i < set1.size; i++)
	{
		arrayset_push(resu, set1.ele[i]);
	}
	for(i = 0; i < set2.size; i++)
	{
		arrayset_push(resu, set2.ele[i]);
	}
}
//inter operating
static void arrayset_inter_oper(ArraySet set1, ArraySet set2, ArraySet* resu)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < set1.size; i++)
	{
		for(; j < set2.size;)
		{
			k = str_cmp(set2.ele[j], set1.ele[i]);
			if(k < 0)
				j++;
			else if(k == 0)
			{
				arrayset_push(resu, set1.ele[i]);
				j++;
				break;
			}
			else
				break;
		}
	}
}
//difference operating（有问题的实现）
 /*static void arrayset_differ_oper(ArraySet set1, ArraySet set2, ArraySet* resu)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < set1.size; i++)
	{
		if(j >= set2.size)
		{
			arrayset_push(resu, set1.ele[i]);
			continue;
		}
 
		for(; j < set2.size;)
		{
			k = str_cmp(set2.ele[j], set1.ele[i]);
			if(k < 0)
				j++;
			else if(k > 0)
			{
				arrayset_push(resu, set1.ele[i]);
				break;
			}
			else
			{
				j++;
				break;
			}
		}
	}
 
}*/

 static void arrayset_differ_oper(ArraySet set1, ArraySet set2, ArraySet* resu)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i <= set1.size; i++)
	{
		if(j >= set2.size)
		{
			arrayset_push(resu, set1.ele[i-1]);
			//continue;
		}
 
		for(j=0; j < set2.size;j++)
		{
			//k = str_cmp(set2.ele[j], set1.ele[i]);
			k = strcmp(set2.ele[j], set1.ele[i]);
			if(k < 0)
			
			{
				//j++;
			}
			else if(k > 0)
			{
				//arrayset_push(resu, set1.ele[i]);
				//j++;
				//break;
			}
			else
			{
				//j++;
				break;
			}
		}
	}
 
}
 
// symdifferecne operating
static void arrayset_symdiffer_oper(ArraySet set1, ArraySet set2, ArraySet* resu)
{
	ArraySet tmp1;
	ArraySet tmp2;
 
	arrayset_init(&tmp1);
	arrayset_init(&tmp2);
 
	arrayset_differ_oper(set1, set2, &tmp1);
	arrayset_differ_oper(set2, set1, &tmp2);
	arrayset_union_oper(tmp1, tmp2, resu);
 
	arrayset_destroy(&tmp1);
	arrayset_destroy(&tmp2);
}
 
// comple operating
static void arrayset_comple_oper(ArraySet e, ArraySet set1, ArraySet* resu)
{
	arrayset_differ_oper(e, set1, resu);
}
 
 
/*linkset operating*/
static void linkset_union_oper(LinkSet* set1, LinkSet* set2, LinkSet* resu)
{//|
	while(set1->next != NULL)
	{
		set1 = set1->next;
		linkset_push(resu, set1->ele);
	}
 
	while(set2->next != NULL)
	{
		set2 = set2->next;
		linkset_push(resu, set2->ele);
	}
 
}
 
static void linkset_inter_oper(LinkSet* set1, LinkSet* set2, LinkSet* resu)
{//^
	while(set1->next != NULL)
	{
		set1 = set1->next;
 
		while(set2 != NULL)
		{
			int k = str_cmp(set2->ele, set1->ele);
			if(k < 0)
			{
				set2 = set2->next;
			}
			else if(k == 0)
			{
				linkset_push(resu, set1->ele);
				set2 = set2->next;
				break;
			}
			else
				break;
		}
	}
}
 
static void linkset_differ_oper(LinkSet* set1, LinkSet* set2, LinkSet* resu)
{//-
	while(set1->next != NULL)
	{
		set1 = set1->next;
 
		if(set2 == NULL)
		{
			linkset_push(resu, set1->ele);
			continue;
		}
 
		while(set2 != NULL)
		{
			int k = str_cmp(set2->ele, set1->ele);
			if(k < 0)
			{
				set2 = set2->next;
			}
			else if(k > 0)
			{
				linkset_push(resu, set1->ele);
				break;
			}
			else
			{
				set2 = set2->next;
				break;
			}
		}
 
	}
}
 
static void linkset_symdiffer_oper(LinkSet* set1, LinkSet* set2, LinkSet* resu)
{//+
	LinkSet *tmp1, *tmp2;
	linkset_init(&tmp1);
	linkset_init(&tmp2);
 
	linkset_differ_oper(set1, set2, tmp1);
	linkset_differ_oper(set2, set1, tmp2);
	linkset_union_oper(tmp1, tmp2, resu);
 
	linkset_destroy(&tmp1);
	linkset_destroy(&tmp2);
}
 
static void linkset_comple_oper(LinkSet* e, LinkSet* set, LinkSet* resu)
{
	//~
	linkset_differ_oper(e, set, resu);
}
 
static int str_cmp(const char* s1, const char* s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
 
	if(l1 < l2)
		return -1;
	else if(l1 > l2)
		return 1;
	else
		return strcmp(s1, s2);
}
 
 
static int fun(const void* a, const void* b)
{
	return str_cmp((char*)a, (char*)b);
}
 
static void arrayset_init(ArraySet* set)
{
	set->size = 0;
	memset(set->ele, '\0', sizeof(char) * MAX_NUM * MAX_SIZE);
}
 
static int arrayset_push(ArraySet* set, const char* data)
{
	int i = 0;
	assert(set->size < MAX_SIZE);
	
	for(i = 0; i < MAX_NUM; i++)
	{
		if(strcmp(set->ele[i], data) == 0)
		{
			return 0;
		}
	}
	//strcpy_s(set->ele[set->size++], data);
	strcpy(set->ele[set->size++], data);
 
	qsort(set->ele, set->size, sizeof(set->ele[0]), fun);
	return 1;
}
 
 
static int arrayset_pop(ArraySet* set, const char* data)
{
	int i = 0;
	while(i < set->size && strcmp(set->ele[i], data) != 0){ i++; }
	if(i >= set->size)
		return 0;
 
	for(; i < set->size - 1; i++)
	{
//		strcpy_s(set->ele[i], set->ele[i + 1]);
		strcpy(set->ele[i], set->ele[i + 1]);

	}
//	strcpy_s(set->ele[set->size--], "\0");
	strcpy(set->ele[set->size--], "\0");
 
	return 1;
}
 
 
static void arrayset_modify(ArraySet* set, char* olddata, char* newdata)
{
	int i = 0;
	while(i < set->size && strcmp(set->ele[i], olddata) != 0)
	{ 
		i++;
	}
	
//	strcpy_s(set->ele[i], newdata);
	strcpy(set->ele[i], newdata);
}
 
 
static void arrayset_destroy(ArraySet* set)
{
	memset(set->ele, 0, sizeof(char) * set->size * MAX_SIZE);
	set->size = 0;
}
 
 
static void arrayset_print(const ArraySet set)
{
	int i = 0;
	printf("{");
	for(i = 0; i < set.size; i++)
	{
		printf("%s   ", set.ele[i]);
	}
	printf("}\n");
}

static int linkset_init(LinkSet** head)
{
	if((*head = (LinkSet*)malloc(sizeof(LinkSet))) == NULL)
	{
		return 0;
	}
	(*head)->next = NULL;
//	strcpy_s((*head)->ele, "\0");
	strcpy((*head)->ele, "\0");
 
	return 1;
}
 
static void linkset_print(const LinkSet* set)
{
	printf("{");
	while(set->next != NULL)
	{
		printf("%s   ", set->next->ele);
		set = set->next;
	}
	printf("}\n");
}
 
static int linkset_push(LinkSet* set, const char* data)
{
	assert(set != NULL);
 
	while(set != NULL)
	{
		if(strcmp(set->ele, data) == 0)
			return 0;
		else if(set->next == NULL)
		{
			LinkSet* node = (LinkSet*)malloc(sizeof(LinkSet));
			set->next = node;
			node->next = NULL;
//			strcpy_s(node->ele, data);
			strcpy(node->ele, data);

			return 1;
			
		}
		else
		{
			int l1 = strlen(data), l2 = strlen(set->next->ele);
			if(l1 < l2 || (l1 == l2 && strncmp(data, set->next->ele, l1) < 0))
			{	
				LinkSet* node = (LinkSet*)malloc(sizeof(LinkSet));
				node->next = set->next;
				set->next = node;
//				strcpy_s(node->ele, data);
				strcpy(node->ele, data);
				return 1;
			}
		}
		set = set->next;
	}
	return 0;
}
 
static int linkset_pop(LinkSet* set, char* data)
{
	assert(set != NULL);
 
	while(set->next != NULL)
	{
		if(strcmp(set->next->ele, data) == 0)
		{
			LinkSet* tmp = set->next;
			set->next = tmp->next;
			free(tmp);
			return 1;
		}
		set = set->next;
	}
	return 0;
}
 
static int linkset_modify(LinkSet* set, char* olddata, char* newdata)
{
	while(set != NULL)
	{
		if(strcmp(set->ele, olddata) == 0)
		{
//			strcpy_s(set->ele, newdata);
			strcpy(set->ele, newdata);
			return 1;
		}
		set = set->next;
	}
	return 0;
}
 
static void linkset_destroy(LinkSet** set)
{
	while((*set)->next != NULL)
	{
		LinkSet* tmp = *set;
		(*set) = (*set)->next;
		free(tmp);
	}
}
 

//集合的链表表示测试
void sample_linkset_test()
{	
	char s[100];

 	LinkSet *e;   //  Universal Set
	LinkSet *set1; 
	LinkSet *set2;
 
	LinkSet *resu_u;
	LinkSet *resu_i;
	LinkSet *resu_d;
	LinkSet *resu_s;
	LinkSet *resu_c;
 
	linkset_init(&e);
	linkset_init(&set1);
	linkset_init(&set2);
 
	linkset_init(&resu_u);
	linkset_init(&resu_i);
	linkset_init(&resu_d);
	linkset_init(&resu_s);
	linkset_init(&resu_c);

	printf("\nlink set test:\n");
	
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)// input Universal Set
	{
		printf("Please Enter Universal Set:\n");
		linkset_push(e, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)
	{
		printf("Please Enter Set1:\n");
		linkset_push(set1, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)
	{
		printf("Please Enter Set2:\n");
		linkset_push(set2, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	printf("Univrsal Set(E) is:    "); linkset_print(e);
	printf("Set1 is: "); linkset_print(set1);
	printf("Set2 is: "); linkset_print(set2);
 
	linkset_union_oper(set1, set2, resu_u);
	linkset_inter_oper(set1, set2, resu_i);
	linkset_differ_oper(set1, set2, resu_d);
 
	linkset_symdiffer_oper(set1, set2, resu_s);
	linkset_comple_oper(e, set2, resu_c);
 
	printf("union set1 and set2: "); linkset_print(resu_u);
	printf("inter set1 and set2: "); linkset_print(resu_i);
	printf("differ set1 and set2: "); linkset_print(resu_d);
	printf("symdiffer set1 and set2: "); linkset_print(resu_s);
	printf("comple e and set2: "); linkset_print(resu_c);
 
	linkset_destroy(&resu_u);
	linkset_destroy(&resu_i);
	linkset_destroy(&resu_d);
	linkset_destroy(&resu_s);
	linkset_destroy(&resu_c);
	linkset_destroy(&e);
	linkset_destroy(&set1);
	linkset_destroy(&set2);
}
 
 
//集合的数组表示测试
void sample_arrayset_test()
{
	char s[100];
	//
 	
	ArraySet e, set1, set2;//全集，集合1，集合2
	ArraySet resu_u, resu_i, resu_d, resu_s, resu_c;//并，交，差，相对差，补运算的结果
	arrayset_init(&e);//集合数组初始化
	arrayset_init(&set1);
	arrayset_init(&set2);
	arrayset_init(&resu_u);
	arrayset_init(&resu_i);
	arrayset_init(&resu_d);
	arrayset_init(&resu_s);
	arrayset_init(&resu_c);

	printf("\narray set test:\n");
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)//输入全集
	{
		printf("Please Enter Universal Set:\n");
		arrayset_push(&e, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)//输入集合
	{
		printf("Please Enter Set1:\n");
		arrayset_push(&set1, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	while(scanf("%s", s) && strcmp(s, "#") != 0)//输入集合
	{
		printf("Please Enter Set2:\n");
		arrayset_push(&set2, s);
		memset(s, '\0', sizeof(char) * 100);
	}
 
	printf("e is:    "); arrayset_print(e);
	printf("set1 is: "); arrayset_print(set1);
	printf("set2 is: "); arrayset_print(set2);
 
	arrayset_union_oper(set1, set2, &resu_u);//并
	arrayset_inter_oper(set1, set2, &resu_i);//交
	arrayset_differ_oper(set1, set2, &resu_d);//差
	arrayset_symdiffer_oper(set1, set2, &resu_s);//相对差
	arrayset_comple_oper(e, set2, &resu_c);//补
 
	printf("union set1 and set2: "); arrayset_print(resu_u);
	printf("inter set1 and set2: "); arrayset_print(resu_i);
	printf("differ set1 and set2: "); arrayset_print(resu_d);
	printf("symdiffer set1 and set2: "); arrayset_print(resu_s);
	printf("comple e and set2: "); arrayset_print(resu_c);
 
	arrayset_destroy(&resu_u);//销毁数组
	arrayset_destroy(&resu_i);
	arrayset_destroy(&resu_d);
	arrayset_destroy(&resu_s);
	arrayset_destroy(&resu_c);
	arrayset_destroy(&e);
	arrayset_destroy(&set1);
	arrayset_destroy(&set2);
}
