#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxLen 100
typedef struct {
    char name[20];
    char phoneNumber[15];
    char Address[70];
} Account;
typedef struct {
    Account list[maxLen];
    int Length;
} Accounts;

void InitList(Accounts *L) {
    L->Length = 0;
}

void CreateList(Accounts *L) {
    char name[20];
    char phoneNumber[15];
    char Address[30];
    while (1) {
        if (L->Length == 99) {
            printf("已达到联系人上限，无法添加");
            system("pause");
            return;
        }
        printf("你正在创建第%d个联系人：(输入0退出)\n", L->Length + 1);
        printf("姓名:");
        scanf("%s", name);
        if (strcmp(name, "0") == 0)
            return;
        strcpy(L->list[L->Length].name, name);
        printf("电话号码:");
        scanf("%s", phoneNumber);
        strcpy(L->list[L->Length].phoneNumber, phoneNumber);
        printf("家庭住址:");
        scanf("%s", Address);
        strcpy(L->list[L->Length].Address, Address);
        L->Length++;
    }
}

void searchAccountByPhoneNumber(Accounts *L) {
    int count = 0;
    printf("Enter PhoneNumber to search: ");
    char searchNumber[15];
    scanf("%s", searchNumber);
    for (int i = 0; i < L->Length; i++) {
        if (strcmp(L->list[i].name, searchNumber) == 0) {
            printf("序号:%d\n", i + 1);
            printf("姓名:%s\n", L->list[i].name);
            printf("电话号码:%s\n", L->list[i].phoneNumber);
            printf("家庭住址:%s\n", L->list[i].Address);
            printf("**********分隔线**********\n");
            count++;
        }
    }
    printf("查找完毕，您共有%d个电话号码为%s的联系人\n", count, searchNumber);
}

void searchAccountByName(Accounts *L) {
    int count = 0;
    printf("Enter name to search: ");
    char searchName[20];
    scanf("%s", searchName);
    for (int i = 0; i < L->Length; i++) {
        if (strcmp(L->list[i].name, searchName) == 0) {
            printf("序号:%d\n", i);
            printf("姓名:%s\n", L->list[i].name);
            printf("电话号码:%s\n", L->list[i].phoneNumber);
            printf("家庭住址:%s\n", L->list[i].Address);
            printf("**********分隔线**********\n");
            count++;
        }
    }
    printf("查找完毕，您共有%d个名为%s的联系人\n", count, searchName);
}

int InsAccount(Accounts *L) {
    int i;
    printf("请输入要插入的位置：");
    scanf("%d", &i);
    int j;
    char name[20];
    char phoneNumber[15];
    char Address[30];
    if (L->Length >= maxLen) {
        printf("顺序表已满！");
        return -1;
    }
    if (i < 1 || i > L->Length + 1) {
        printf("插入位置出错！");
        return 0;
    }
    printf("姓名:");
    scanf("%s", name);
    printf("电话号码:");
    scanf("%s", phoneNumber);
    printf("家庭住址:");
    scanf("%s", Address);
    if (i == L->Length + 1) {
        strcpy(L->list[i - 1].name, name);
        strcpy(L->list[i - 1].phoneNumber, phoneNumber);
        strcpy(L->list[i - 1].Address, Address);
        L->Length++;
        return 1;
    }
    for (j = L->Length - 1; j >= i - 1; j--)
        L->list[j + 1] = L->list[j];
    strcpy(L->list[i - 1].name, name);
    strcpy(L->list[i - 1].phoneNumber, phoneNumber);
    strcpy(L->list[i - 1].Address, Address);
    L->Length++;
    return 1;
}

void editAccount(Accounts *L) {
    int flag = 1;
    int choice;
    char name[20];
    char phoneNumber[15];
    char Address[30];
    printf("输入你要编辑的联系人的姓名: ");
    char deleteName[20];
    scanf("%s", deleteName);
    for (int i = 0; i < L->Length; i++) {
        flag = 1;
        if (strcmp(L->list[i].name, deleteName) == 0) {
            printf("您正在编辑%s(%s)\n扣0取消，或查找下一个。", L->list[i].name, L->list[i].phoneNumber);
            scanf("%d", &flag);
            if (flag == 0)
                continue;
            while (1) {
                printf("1.序号:%d\n", i);
                printf("2.姓名:%s\n", L->list[i].name);
                printf("3.电话号码:%s\n", L->list[i].phoneNumber);
                printf("4.家庭住址:%s\n", L->list[i].Address);
                printf("0.退出\n");
                scanf("输入要修改信息的序号");
                scanf("%d", &choice);
                if (choice == 0)break;
                if (choice == 1)printf("无法修改序号\n");
                if (choice == 2) {
                    scanf("%s", name);
                    strcpy(L->list[i].name, name);
                }
                if (choice == 3) {
                    scanf("%s", phoneNumber);
                    strcpy(L->list[i].phoneNumber, phoneNumber);
                }
                if (choice == 4) {
                    scanf("%s", Address);
                    strcpy(L->list[i].Address, Address);
                }
            }
        }
    }
}

void deleteAccount(Accounts *L) { // 还要加个判断，询问用户是不是
    int flag = 1;
    printf("Enter name to delete: ");
    char deleteName[20];
    scanf("%s", deleteName);
    for (int i = 0; i < L->Length; i++) {
        flag = 1;
        if (strcmp(L->list[i].name, deleteName) == 0) {
            printf("您正在试图删除%s(%s)\n扣0取消，或查找下一个。", L->list[i].name, L->list[i].phoneNumber);
            scanf("%d", &flag);
            if (flag == 0)
                continue;
            for (int j = i; j < L->Length - 1; j++) {
                L->list[j] = L->list[j + 1];
            }
            L->Length--;
            printf("Account deleted.\n");
            return;
        }
    }
    printf("No one will be deleted.\n");
}

void printAllAccounts(Accounts *L) {
    for (int i = 0; i < L->Length; i++) {
        printf("序号:%d\n", i + 1);
        printf("姓名:%s\n", L->list[i].name);
        printf("电话号码:%s\n", L->list[i].phoneNumber);
        printf("家庭住址:%s\n", L->list[i].Address);
        printf("**********分隔线**********\n");
    }
}

void printMenu() {
    printf("电子通讯录系统\n");
    printf("1. 搜索联系人\n");
    printf("2. 编辑联系人\n");
    printf("3. 删除联系人\n");
    printf("4. 插入联系人\n");
    printf("5. 打印所有联系人\n");
    printf("0. 退出\n");
}

int main() {
    int choice;
    Accounts L;
    InitList(&L);
    CreateList(&L);
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                return 0;
            case 1:
                printf("选择搜索方式:\n1. 通过名字搜索\n2. 通过号码搜索");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        searchAccountByName(&L);
                        break;
                    case 2:
                        searchAccountByPhoneNumber(&L);
                        break;
                    default:
                        printf("非法输入");
                        break;
                }
                break;
            case 2:
                editAccount(&L);
                break;
            case 3:
                deleteAccount(&L);
                break;
            case 4:
                InsAccount(&L);
                break;
            case 5:
                printAllAccounts(&L);
                break;
            default:
                printf("非法输入");
                break;
        }
    }
}
