#include <stdio.h>

int main(void)
{
    int arr[2147483647]={0};
    int t, i, n, m, j, tmp, tmp2, k;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%d", &n);
        for(j=0;j<n;j++)
        {
            scanf("%d", &tmp);
            arr[tmp]=1;
        }
        scanf("%d", &m);
        for(k=0;k<m;k++)
        {
            scanf("%d", &tmp2);
            if(arr[tmp2]==1) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}