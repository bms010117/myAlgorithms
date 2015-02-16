#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int x[4]={0, 0, -1, 1}, y[4]={-1, 1, 0, 0}, map[103][103], px[10003], py[10003];
int main(void)
{
    int sx, sy, tx, ty, i, j;
    int f, s, n;
    fscanf(in, "%d", &n);
    fscanf(in, "%d %d", &sx, &sy);
    map[sx][sy]=1;
    px[f]=sx;
    py[f]=sy;
    f=s=0;
    while(f<=s)
    {
        for(i=0;i<4;i++)
        {
            tx=px[f]+x[i];
            ty=py[f]+y[i];
            if(tx>0&&tx<=n&&ty>0&&ty<=n)
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
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
    
            fprintf(out, "%d ", map[i][j]);
        }
        fprintf(out, "\n");
    }
    return 0;
}
