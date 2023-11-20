#include <stdio.h> //22401330125 高学骏
int main(void)
{
  int pwd = 7, gs; // pwd:谜底
  printf("\tGames Begin\n");
  do
  {
    printf("Please guess (0~10):");
    scanf("%d", &gs);
  } while (gs != pwd);
  printf("\tSucceed!\n");
  printf("\tGames over\n");
  return 0;
}
