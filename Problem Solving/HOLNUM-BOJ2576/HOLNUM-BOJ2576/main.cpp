#include <stdio.h>
#include <algorithm>
int main(void)
{
    int arr[7], i, sum=0, min=10000;
    for(i=0;i<7;i++){
        scanf("%d", &arr[i]);
        if(arr[i]%2) sum=sum+arr[i];
        if(arr[i]%2&&min>arr[i]) min=arr[i];
    }
    printf("%d\n%d\n", sum, min);
    return 0;
}