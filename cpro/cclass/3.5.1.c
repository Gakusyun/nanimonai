#include <stdio.h> //22401330125高学骏
void main()
{
    int score;
    char grade;
    printf("");
    scanf("%d", &score);
    if (score > 100 || score < 0)
        printf("error");
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'E';
    printf("%c", grade);
}