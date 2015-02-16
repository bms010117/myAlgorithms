#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int x[8]={-2, -2, -1, 1, 2, 2, 1, -1}, y[8]={-1, 1, 2, 2, 1, -1, -2, -2}, map[1003][1003], px[100003], py[100003];
int main(void)
{
    int sx, sy, tx, ty, i, ax, ay;
    //    int x[8]={sx-j, sx, sx+j, sx, sx-j, sx+j, sx+j, sx-j};
   // int y[8]={sy, sy+j, sy, sy-j, sy+j, sy+j, sy-j, sy-j};
    int f, s, n;
    n=101;
    fscanf(in, "%d %d", &sx, &sy);
    //sx=sx-1, sy=sy-1;
    fscanf(in, "%d %d", &ax, &ay);
    //1ax=ax-1, ay=ay-1;
    map[sx][sy]=1;
    px[f]=sx;
    py[f]=sy;
    f=s=0;
    while(f<=s)
    {
        for(i=0;i<8;i++)
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
    fprintf(out, "%d", map[ax][ay]-1);
    return 0;
}




