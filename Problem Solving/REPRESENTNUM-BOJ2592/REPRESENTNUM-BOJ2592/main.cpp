//solved
#include <stdio.h>
int arr[1003];
int main(void)
{
    int i, getAvr=0, n, getMax=0, getArr=0;
    for(i=0;i<10;i++)
    {
        scanf("%d", &n);
        getAvr=getAvr+n;
        arr[n/10]=arr[n/10]+1;
    }
    for(i=1;i<=103;i++)
    {
        if(getMax<arr[i]) getMax=arr[i], getArr=i;
    }
    printf("%d\n%d", getAvr/10, getArr*10);
}