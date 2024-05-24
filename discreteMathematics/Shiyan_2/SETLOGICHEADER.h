#ifndef _SETLOGICHEADER_H_
#define _SETLOGICHEADER_H_

#define MAX_NUM 200
#define MAX_SIZE 100

typedef struct
{
	int size;
	char ele[MAX_NUM][MAX_SIZE];
} ArraySet;

typedef struct LinkSet
{
	char ele[MAX_SIZE];
	struct LinkSet *next;
} LinkSet;

/*Private function prototypes*/

static void arrayset_union_oper(ArraySet set1, ArraySet set2, ArraySet *resu);
static void arrayset_inter_oper(ArraySet set1, ArraySet set2, ArraySet *resu);
static void arrayset_differ_oper(ArraySet set1, ArraySet set2, ArraySet *resu);
static void arrayset_symdiffer_oper(ArraySet set1, ArraySet set2, ArraySet *resu);
static void arrayset_comple_oper(ArraySet e, ArraySet set1, ArraySet *resu);

static void linkset_union_oper(LinkSet *set1, LinkSet *set2, LinkSet *resu);
static void linkset_inter_oper(LinkSet *set1, LinkSet *set2, LinkSet *resu);
static void linkset_differ_oper(LinkSet *set1, LinkSet *set2, LinkSet *resu);
static void linkset_symdiffer_oper(LinkSet *set1, LinkSet *set2, LinkSet *resu);
static void linkset_comple_oper(LinkSet *e, LinkSet *set, LinkSet *resu);

static int str_cmp(const char *s1, const char *s2);
static int fun(const void *a, const void *b);
static void arrayset_init(ArraySet *set);
static int arrayset_push(ArraySet *set, const char *data);
static int arrayset_pop(ArraySet *set, const char *data);
static void arrayset_modify(ArraySet *set, char *olddata, char *newdata);
static void arrayset_destroy(ArraySet *set);
static void arrayset_print(const ArraySet set);

static int linkset_init(LinkSet **head);
static void linkset_destroy(LinkSet **set);
static void linkset_print(const LinkSet *set);
static void linkset_print(const LinkSet *set);
static int linkset_pop(LinkSet *set, char *data);
static int linkset_push(LinkSet *set, const char *data);
static int linkset_modify(LinkSet *set, char *olddata, char *newdata);

/*Public function prototypes*/
void sample_arrayset_test();
void sample_linkset_test();

#endif // end of _SETLOGICHEADER_H_
