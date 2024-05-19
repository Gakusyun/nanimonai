#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wff.h"
#include "wff_plus.h"
#include "wff.c"
#include "wff_plus.c"

#define MAX_LEN 100

int main()
{
	char *str = NULL;
	str = (char *)malloc(MAX_LEN * sizeof(char));
	memset(str, 0, MAX_LEN * sizeof(char));
	while (1)
	{
		scanf("%s", str);

		/* 给所有的运算符以优先级加括号  */
		revise(str);
		if (separate(str, 0, strlen(str) - 1))
			printf("yes\n");
		else
			printf("no\n");

		// printf("hello!");
	}
	return 0;
}
