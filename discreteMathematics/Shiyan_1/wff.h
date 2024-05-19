#ifndef _WFF_H_
#define _WFF_H_

#define SEPARATE_DEBUG

/* 自定义bool类型 */
typedef enum BOOL_TYPE
{
	false = 0,
	true
} bool;

/* 自定义左右括号类型 */
typedef enum BRACKET_TYPE
{
	left_type = 0,
	right_type
} bracket_type;

/* 自定义运算符位置和类型 */
typedef struct SAVE_TYPE
{
	int position; // 存放begin-end中的字符串最后一个运算符的物理位置
	int type;	  // 存放这个运算符的种类
} save_type;

/* 运算符标识 */
#define SINGLE 1
#define DOUBLE 2

/* 双目运算符，按优先级排序 */
#define DOUBLE_TYPE_1 '*'
#define DOUBLE_TYPE_2 '+'
#define DOUBLE_TYPE_3 '-'
#define DOUBLE_TYPE_4 '='

/* 单目运算符 */
#define SINGLE_TYPE_1 '!'

bool separate(char *str, int begin, int end);

bool is_atom(char *str, int begin, int end);
bool find(char *str, int begin, int end);
int delete_bracket(char *str, int begin, int end, bracket_type bra);
bool is_operator(char c);
bool find_operator(char *str, int begin, int end);
#endif
