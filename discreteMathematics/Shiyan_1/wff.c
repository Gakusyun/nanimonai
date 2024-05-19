#include <ctype.h>
#include <stdio.h>
#include "wff.h"

static save_type save;

/**
 * @brief	分离函数，检查str是否为合式公式
 *	@param	str、begin、end：合式公式字符串、公式开始位置、公式结束位置
 *	@retval	若是合适公式，返回true，否则返回false
 */
bool separate(char *str, int begin, int end)
{

/* 调试，可以在.h中注释宏关闭 */
#ifdef SEPARATE_DEBUG
	int j;
	for (j = begin; j <= end; j++)
	{
		printf("%c", str[j]);
	}
	printf("\n");
#endif

	if (is_atom(str, begin, end)) // A
		return true;
	else //(!A)  (A@B)
	{
		/* 去括号 */
		int ibegin = delete_bracket(str, begin, end, left_type);
		int iend = delete_bracket(str, begin, end, right_type);

		/* 寻找运算符 */
		if ((ibegin >= iend) || !find_operator(str, ibegin, iend))
			return false;

		/* 递归调用 */
		if (save.type == SINGLE) //! A
			return separate(str, save.position + 1, iend);
		if (save.type == DOUBLE) // A@B
		{
			int po = save.position;
			return separate(str, ibegin, po - 1) && separate(str, po + 1, iend);
		}
	}
}

/**
 * @brief	递归过滤给定起始位置的合式公式的外层括号，直到没有外层括号
 *	@param	str、begin、end：合式公式字符串、公式开始位置、公式结束位置
 * @param	bra：标示要过滤左括号还是右括号
 *	@retval	成功则返回过滤掉外层括号的下一个位置，失败返回-1
 */
int delete_bracket(char *str, int begin, int end, bracket_type bra)
{
	int i = begin;
	int flag = 0;
	for (; i <= end; i++)
	{
		if (str[i] == '(')
			flag++;
		if (str[i] == ')')
			flag--;
		if (flag == 0)
		{
			if (i == end)
			{
				return delete_bracket(str, begin + 1, end - 1, bra);
			}
			else
			{
				if (bra == left_type)
					return begin;
				return end;
			}
		}
	}
	return -1;
}

/**
 * @brief	判断str是否为原子公式
 *	@param	str、begin、end：合式公式字符串、公式开始位置、公式结束位置
 *	@retval	若是原子公式，返回true，否则返回false
 */
bool is_atom(char *str, int begin, int end)
{
	int str_len = end - begin + 1;
	if ((begin > end) || (str_len != 1))
		return false;

	if (isalpha(str[begin])) // 原子公式
		return true;
	return false; // 非原子公式
}

/**
 * @brief	判断c是否为联结词
 *	@param	str、begin、end：合式公式字符串、公式开始位置、公式结束位置
 *	@retval	若是原子公式，返回true，否则返回false
 */
bool is_operator(char c)
{

	/* 双目运算符 */
	if (c == DOUBLE_TYPE_1 ||
		c == DOUBLE_TYPE_2 ||
		c == DOUBLE_TYPE_3 ||
		c == DOUBLE_TYPE_4)
	{
		save.type = DOUBLE;
	}
	/* 单目运算符 */
	else if (c == SINGLE_TYPE_1)
	{
		save.type = SINGLE;
	}

	/* 非联结词 */
	else
		save.type = -1;

	if (save.type == -1)
		return false;
	return true;
}

/**
 * @brief	寻找联结词，并记录类型
 *	@param	str、begin、end：合式公式字符串、公式开始位置、公式结束位置
 *	@retval	若存在，返回true，否则返回false
 */
bool find_operator(char *str, int begin, int end)
{
	int flag = 0;
	int i = begin;

	/* 入口判断 */
	if (begin > end)
		return false;

	// int flag = 0;
	// int i = begin;
	for (; i <= end; i++)
	{
		if (str[i] == '(')
			flag++;
		if (str[i] == ')')
			flag--;
		if (flag == 0)
		{
			if (is_operator(str[i + 1])) // A@B
			{
				save.position = i + 1;
				return true;
			}
			else if (is_operator(str[i])) //! A
			{
				save.position = i;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
