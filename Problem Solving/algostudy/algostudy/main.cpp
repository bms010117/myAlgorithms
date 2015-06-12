#include <stdio.h>
int main(void)
{
    int i;
    int arr[5]; //배열은 0번방부터 넣어서 크기는 6이지만 꽉 채우는걸 권장하지 않습니다.
    arr[0]=1; //이런식으로 각각의 방에 수를 넣을 수 있습니다.
    printf("arr[0]=%d\n", arr[0]);
    for(i=0;i<5;i++)
    {
        arr[i/*i+1을 넣을 주소를 지정*/]=i+1; //이런식으로 포문에서 하는것도 가능
    }
    for(i=0;i<5;i++)
    {
        printf("arr[%d]=%d ", i, arr[i]);
        ++a;
    }
    return 0;
}