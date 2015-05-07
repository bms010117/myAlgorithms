#include <stdio.h>
int times[2];
int fibonacci(int n)
{
    if (n==0)
    {
        times[0]=times[0]+1;
        return 0;
    }
    else if (n==1)
    {
        times[1]=times[1]+1;
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(void)
{
    int i, time, num;
    scanf("%d", &time);
    for(i=0;i<time;i++)
    {
        scanf("%d", &num);
        fibonacci(num);
        printf("%d %d", times[0], times[1]);
        times[0]=times[1]=0;
        
    }
}