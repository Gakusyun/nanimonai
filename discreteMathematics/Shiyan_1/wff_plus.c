#include <stdlib.h>
#include <string.h>

#include "wff_plus.h"
#include "wff.h"

/**
 * @brief	在str的left的位置上加上左括号，在right的位置上加上右括号
 *	@param	str、left、right：合式公式字符串、左括号位置、右括号位置
 *	@retval	NONE
 */
void run_add(char *str, int left, int right)
{
	int len = strlen(str); // 计算总长度
	int i = len + 1;	   // 新字符串的遍历
	int j = len - 1;	   // 旧字符串的遍历

	/* 修改字符串大小，长度加3，()和结束标志'\0'  */
	str = (char *)realloc(str, len + 3);
	for (; i >= 0; i--, j--)
	{
		/* 遇到存放括号的位置时，令j停留在原来的位置，i继续进行 */
		if (i == right || i == left)
		{
			j++;
			continue;
		}
		else
		{
			str[i] = str[j];
		}
	}

	/* 加括号和标识 */
	str[left] = '(';
	str[right] = ')';
	str[len + 2] = '\0';
}

/**
 * @brief	寻找联结词左边存放左括号的位置，例如a@b就是要找a左边的位置
 *	@param	str、position：合式公式字符串、联结词位置
 *	@retval	成功返回位置索引，否则返回-1
 */
int left_find(char *str, int position) // 寻找联结词左边存放左括号的位置
{
	int i = position - 1; // 开始位置
	int flag = 0;		  // 记录左右括号

	for (; i >= 0; i--)
	{
		if (str[i] == '(')
			flag++;
		if (str[i] == ')')
			flag--;
		if (flag == 0)
			return i;
	}

	return -1;
}

/**
 * @brief	寻找联结词左边存放右括号的位置，例如a@b就是要找b右边的位置
 *	@param	str、position：合式公式字符串、联结词位置
 *	@retval	成功返回位置索引，否则返回-1
 */
int right_find(char *str, int position) // 寻找联结词右边的公式的位置
{
	int i = position + 1; // 开始位置
	int flag = 0;		  // 记录左右括号
	for (; i < strlen(str); i++)
	{
		if (str[i] == '(')
			flag++;
		if (str[i] == ')')
			flag--;
		if (flag == 0)
			return i;
	}

	return -1;
}

/**
 * @brief	不管原来有没有括号，给所有的运算符以优先级加括号
 *	@param	str：合式公式字符串
 *	@retval	修改成功返回1，否则返回-1
 */
int revise(char *str)
{
	int i = strlen(str) - 1;
	int left;
	int right;

	/* 为联结词!的两边添加括号 */
	for (; i >= 0; i--)
	{
		if (str[i] == SINGLE_TYPE_1)
		{
			right = right_find(str, i);
			left = i;
			if ((right != -1) && (left != -1))
				run_add(str, left, right + 2);
			else
				return -1;
		}
	}

	/* 为联结词*的两边添加括号 */
	for (i = 0; i < strlen(str); i++)
		if (str[i] == DOUBLE_TYPE_1)
		{
			right = right_find(str, i);
			left = left_find(str, i);
			if ((right != -1) && (left != -1))
			{
				run_add(str, left, right + 2);
				i = right + 2;
			}
			else
				return -1;
		}

	/* 为联结词+的两边添加括号 */
	for (i = 0; i < strlen(str); i++)
		if (str[i] == DOUBLE_TYPE_2)
		{
			right = right_find(str, i);
			left = left_find(str, i);
			if ((right != -1) && (left != -1))
			{
				run_add(str, left, right + 2);
				i = right + 2;
			}
			else
				return -1;
		}

	/* 为联结词-的两边添加括号 */
	for (i = 0; i < strlen(str); i++)
		if (str[i] == DOUBLE_TYPE_3)
		{
			right = right_find(str, i);
			left = left_find(str, i);
			if ((right != -1) && (left != -1))
			{
				run_add(str, left, right + 2);
				i = right + 2;
			}
			else
				return -1;
		}

	/* 为联结词=的两边添加括号 */
	for (i = 0; i < strlen(str); i++)
		if (str[i] == DOUBLE_TYPE_4)
		{
			right = right_find(str, i);
			left = left_find(str, i);
			if ((right != -1) && (left != -1))
			{
				run_add(str, left, right + 2);
				i = right + 2;
			}
			else
				return -1;
		}

	return 1;
}
