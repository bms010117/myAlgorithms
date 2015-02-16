/**
    장기-변민서
    세로 10 가로 9인 장기판에 시작위치 sx, sy 에 마의 위치가 주어지고 n개의 장애물을 피해 도착위치 ex, ey 에 도착할 때 가장 빠른 이동횟수를 구하는 문제.
    첫 번째 줄에 시작위치 sx, sy 두 번째 줄에 도착위치 ex, ey 세 번째 줄에 장애물의 개수, 네 번째 줄부터 장애물의 위치가 세로, 가로 로 주어진다.
**/
/*
    Sample Input : 
1 3
9 5
6
2 5
3 2
4 4
4 5
7 3
7 5

    Sample Output:
    6
*/
/*
 장애물: 1
 빈 공간: 0
 시작점: 2
 맨 마지막에 2를 뺀다.
 */

#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int x[8]={-2, -2, -1, 1, 2, 2, 1, -1};
int y[8]={-1, 1, 2, 2, 1, -1, -2, -2}, map[1003][1003], px[100003], py[100003];
int xc[8]={-1, -1, 0, 0, 1, 1, 0, 0}, yc[8]={0, 0, 1, 1, 0, 0, -1, -1};
int obx[10000], oby[10000];
int main(void)
{
    int sx, sy, tx, ty, i, ax, ay;
    int f, s, n, m, j;
    int mpx, mpy;
    int num;
    n=10, m=9;
    fscanf(in, "%d %d", &sx, &sy);
    map[sx][sy]=2;
    fscanf(in, "%d %d", &ax, &ay);
    fscanf(in, "%d", &num);
    for(i=0;i<num;i++)
    {
        fscanf(in, "%d %d", &obx[i], &oby[i]);
        map[obx[i]][oby[i]]=1;
    }
    f=s=0;
    px[f]=sx;
    py[f]=sy;
    while(f<=s)
    {
        for(i=0;i<8;i++)
        {
            tx=px[f]+x[i];
            ty=py[f]+y[i];
            //mpx=xc[i], mpy=yc[i];
            if(x[i]==-2)
                mpx=-1, mpy=0;
            else if(x[i]==-1&&y[i]==2)
                mpx=0, mpy=1;
            else if(x[i]==1&&y[i]==2)
                mpx=0, mpy=1;
            else if(x[i]==2)
                mpx=1, mpy=0;
            else if(x[i]==1&&y[i]==-2)
                mpx=0, mpy=-1;
            else if(x[i]==-1&&y[i]==-2)
                mpx=0, mpy=-1;
            
            if(tx>0&&tx<=n&&ty>0&&ty<=m)
            {
                if(map[tx][ty]==0&&map[px[f]+mpx][py[f]+mpy]!=1)
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
    if(map[ax][ay]==0||map[ax][ay]==1)
    {
        fprintf(out, "-1");
        return 0;
    }
    fprintf(out, "%d", map[ax][ay]-2);
    return 0;
}




