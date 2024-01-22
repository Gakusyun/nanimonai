#include <stdio.h>
#include <stdlib.h>
int main()
{
    char choice;
    printf("初始化已完成\n");
    printf("请选择是否安装组1(y/n)\n");
    scanf("%c", &choice);
    if (choice=='y')
    {
        system("./application.sh");
    }
    printf("请选择是否安装Java(y/n)\n");
    scanf("%c", &choice);
    if (choice == 'y')
    {
        system("./java_env.sh");
    }
    return 0;
}