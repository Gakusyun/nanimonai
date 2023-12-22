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
            printf("�Ѵﵽ��ϵ�����ޣ��޷����");
            system("pause");
            return;
        }
        printf("�����ڴ�����%d����ϵ�ˣ�(����0�˳�)\n", L->Length + 1);
        printf("����:");
        scanf("%s", name);
        if (strcmp(name, "0") == 0)
            return;
        strcpy(L->list[L->Length].name, name);
        printf("�绰����:");
        scanf("%s", phoneNumber);
        strcpy(L->list[L->Length].phoneNumber, phoneNumber);
        printf("��ͥסַ:");
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
            printf("���:%d\n", i + 1);
            printf("����:%s\n", L->list[i].name);
            printf("�绰����:%s\n", L->list[i].phoneNumber);
            printf("��ͥסַ:%s\n", L->list[i].Address);
            printf("**********�ָ���**********\n");
            count++;
        }
    }
    printf("������ϣ�������%d���绰����Ϊ%s����ϵ��\n", count, searchNumber);
}

void searchAccountByName(Accounts *L) {
    int count = 0;
    printf("Enter name to search: ");
    char searchName[20];
    scanf("%s", searchName);
    for (int i = 0; i < L->Length; i++) {
        if (strcmp(L->list[i].name, searchName) == 0) {
            printf("���:%d\n", i);
            printf("����:%s\n", L->list[i].name);
            printf("�绰����:%s\n", L->list[i].phoneNumber);
            printf("��ͥסַ:%s\n", L->list[i].Address);
            printf("**********�ָ���**********\n");
            count++;
        }
    }
    printf("������ϣ�������%d����Ϊ%s����ϵ��\n", count, searchName);
}

int InsAccount(Accounts *L) {
    int i;
    printf("������Ҫ�����λ�ã�");
    scanf("%d", &i);
    int j;
    char name[20];
    char phoneNumber[15];
    char Address[30];
    if (L->Length >= maxLen) {
        printf("˳���������");
        return -1;
    }
    if (i < 1 || i > L->Length + 1) {
        printf("����λ�ó���");
        return 0;
    }
    printf("����:");
    scanf("%s", name);
    printf("�绰����:");
    scanf("%s", phoneNumber);
    printf("��ͥסַ:");
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
    printf("������Ҫ�༭����ϵ�˵�����: ");
    char deleteName[20];
    scanf("%s", deleteName);
    for (int i = 0; i < L->Length; i++) {
        flag = 1;
        if (strcmp(L->list[i].name, deleteName) == 0) {
            printf("�����ڱ༭%s(%s)\n��0ȡ�����������һ����", L->list[i].name, L->list[i].phoneNumber);
            scanf("%d", &flag);
            if (flag == 0)
                continue;
            while (1) {
                printf("1.���:%d\n", i);
                printf("2.����:%s\n", L->list[i].name);
                printf("3.�绰����:%s\n", L->list[i].phoneNumber);
                printf("4.��ͥסַ:%s\n", L->list[i].Address);
                printf("0.�˳�\n");
                scanf("����Ҫ�޸���Ϣ�����");
                scanf("%d", &choice);
                if (choice == 0)break;
                if (choice == 1)printf("�޷��޸����\n");
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

void deleteAccount(Accounts *L) { // ��Ҫ�Ӹ��жϣ�ѯ���û��ǲ���
    int flag = 1;
    printf("Enter name to delete: ");
    char deleteName[20];
    scanf("%s", deleteName);
    for (int i = 0; i < L->Length; i++) {
        flag = 1;
        if (strcmp(L->list[i].name, deleteName) == 0) {
            printf("��������ͼɾ��%s(%s)\n��0ȡ�����������һ����", L->list[i].name, L->list[i].phoneNumber);
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
        printf("���:%d\n", i + 1);
        printf("����:%s\n", L->list[i].name);
        printf("�绰����:%s\n", L->list[i].phoneNumber);
        printf("��ͥסַ:%s\n", L->list[i].Address);
        printf("**********�ָ���**********\n");
    }
}

void printMenu() {
    printf("����ͨѶ¼ϵͳ\n");
    printf("1. ������ϵ��\n");
    printf("2. �༭��ϵ��\n");
    printf("3. ɾ����ϵ��\n");
    printf("4. ������ϵ��\n");
    printf("5. ��ӡ������ϵ��\n");
    printf("0. �˳�\n");
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
                printf("ѡ��������ʽ:\n1. ͨ����������\n2. ͨ����������");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        searchAccountByName(&L);
                        break;
                    case 2:
                        searchAccountByPhoneNumber(&L);
                        break;
                    default:
                        printf("�Ƿ�����");
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
                printf("�Ƿ�����");
                break;
        }
    }
}
