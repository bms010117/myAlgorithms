//flood fill
#include <stdio.h>
#define m 110
int f, s, n, sx, sy, px[m*m], py[m*m], map[m][m], tx, ty, x[4]={1, -1, 0, 0}, y[4]={0, 0, 1, -1};

int main()
{
    int i, j;
    scanf("%d %d%d", &n, &sx, &sy);
    f=s=1;
    px[f]=sx, py[f]=sy, map[sx][sy]=1;
    while(f<=s)
    {
        for(i=0; i<4; i++)
        {
            tx=px[f]+x[i];
            ty=py[f]+y[i];
            if(tx>0 && tx<=n && ty>0 && ty<=n && map[tx][ty]==0)
            {
                s++;
                px[s]=tx, py[s]=ty, map[tx][ty]=map[px[f]][py[f]]+1;
            }
        }
        f++;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}