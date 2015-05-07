//solved
#include <stdio.h>
int main(void)
{
    int a, b, num=0, chk=0, div=0, tmp, by;
    scanf("%d %d", &a, &b);
    if(a>b) by=b, div=a;
    else if(a<b) by=a, div=b;
    else if(a==b){
        printf("%d ", a);
        chk=1;
    }
    if(chk==0)
    {
        while(1)
        {
          //  printf("div %d arr[%d] %d", div, num, by);
            if(div%by==0)
            {
                printf("%d\n", by);
                break;
            }
            else if(div%by>0)
            {
                div=div%by;
                tmp=div;
                div=by;
                by=tmp;
            }
        }
    }
    printf("%d", a*b/by);
}