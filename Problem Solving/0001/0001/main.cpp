#include <stdio.h>
int main(void)
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if(n1%2==0 || n1==0)
    {
        printf("1");
        return 0;
    }
    if(n2%2==1)
    {
        printf("1");
        return 0;
    }
    printf("0");
    return 0;
}