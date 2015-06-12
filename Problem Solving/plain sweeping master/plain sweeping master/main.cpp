#include <stdio.h>
#include <algorithm>
int X[9], Y[9];
struct arr{
    int x1, x2, y1, y2;
};
int main(void)
{
    int i, j, k, sum=0;
    struct arr D[4];
    for(i=0;i<4;i++)
    {
        scanf("%d %d %d %d", &D[i].x1, &D[i].y1, &D[i].x2, &D[i].y2);
        X[i*2]=D[i].x1, X[i*2+1]=D[i].x2;
        Y[1*2]=D[i].y1, Y[i*2+1]=D[i].y2;
    }
    for(i=0;i<9;i++)
    {
        printf("X %d Y %d", X[i], Y[i]);
        printf("\n");
    }
    std::sort(X, X+9);
    std::sort(Y, Y+9);
    printf("----------\n");
    for(i=0;i<9;i++)
    {
        printf("X %d Y %d", X[i], Y[i]);
        printf("\n");
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            for(k=0;k<4;k++)
            {
                if(D[k].x1<=X[i] && D[k].x2>=X[i+1] && D[k].y1<=Y[j] && D[k].y2>=Y[j+1]) break;
            }
            if(k!=4)
            {
                sum+=(X[i+1]-X[i])*(Y[j+1]-Y[j]);
            }
        }
    }
    printf("%d\n", sum);
}