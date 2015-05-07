#include <stdio.h>
int main(void)
{
    int a, i, j;
    scanf("%d", &a);
    for(i=a;i>=1;i--)
    {
        for(j=1;j<=a;j++)
        {
            if(j==a-i||j<a-i) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
}
//actually it's 2441