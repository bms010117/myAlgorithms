#include <stdio.h>
#include <algorithm>
int main(void)
{
    int arr[1000003];
    int n, i, j, tmp;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    std::sort(arr, arr+n);
    for(i=0;i<n;i++)
    {
        printf("%d\n", arr[i]);
    }
}