#include <stdio.h> //22401330125高学骏

void main()
{
    float faHeight, moHeight;
    double height;
    char sex, sports, diet;
    printf("");
    scanf("%d,%d,%c,%c,%c", &faHeight, &moHeight, &sex, &sports, &diet);
    if (sex == 'M')
        height = (faHeight + moHeight) * 0.54;
    else
        height = (moHeight + faHeight * 0.923) / 2;
    if (sports == 'Y')
        height *= 1.02;
    if (diet == 'Y')
        height *= 1.015;
    printf("height=%.2f", height);
}