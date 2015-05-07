#include <stdio.h>
int year;
int main(void)
{
    int a, b;
    int gan[10] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    char ji[12] = {'I', 'J', 'K', 'L', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    scanf("%d", &year);
    a=year%12;
    b=year%10;
    printf("%c%d\n", ji[a], gan[b]);
}
//solved