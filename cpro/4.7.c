#include <stdio.h>
int main()
{
  int count, sum, x;
  count = sum = 0;
  do
  {
    scanf("%d", &x);
    if (x % 2 != 0)
      continue;
    count++;
    sum += x;
  } while (count < 5);
  printf("sum=%d", sum);
}
