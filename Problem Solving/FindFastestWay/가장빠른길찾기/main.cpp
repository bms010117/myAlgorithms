#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int x[4]={0, 0, -1, 1}, y[4]={-1, 1, 0, 0}, map[103][103], px[10003], py[10003];
int main(void)
{
    int sx, sy, tx, ty, i, j;
    int f, s, n, m;
    fscanf(in, "%d %d", &n, &m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            fscanf(in, "%1d", &map[i][j]);
        }
       // scanf("\n");
    }
    sx=n, sy=1;
    map[sx][sy]=1;
    f=s=0;
    px[f]=sx;
    py[f]=sy;
    while(f<=s)
    {
        for(i=0;i<4;i++)
        {
            tx=px[f]+x[i];
            ty=py[f]+y[i];
            if(tx>0&&tx<=n&&ty>0&&ty<=m)
            {
                if(map[tx][ty]==0)
                {
                    s++;
                    px[s]=tx;
                    py[s]=ty;
                    map[tx][ty]=map[px[f]][py[f]]+1;
                }
            }
        }
        f++;
    }
    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    */
    if(map[1][m]==1||map[1][m]==0)
    {
        fprintf(out, "-1");
        return 0;
    }
    fprintf(out, "%d", map[1][m]);
    return 0;
}
