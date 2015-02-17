#include <stdio.h>
#define M 99999
int max;
struct EDGE
{
    int n1;
    int n2;
};
int isVertex(int vertex[], int a);
int map[1003][1003];
struct EDGE edge[10003];
void prim(int start);
int scr=0;
int main(void)
{
    int cnt, i, z=1;
    max=1, cnt=3;
    int x, y;
    for(i=0;i<cnt;i++)
    {
        if(i==cnt-1)
        {
            scanf("%d %d", &x, &y);
            map[x][y]=z;
            map[y][x]=z;
        }
        else
        {
            scanf( "%d %d\n", &x, &y);
            map[x][y]=z;
            map[y][x]=z;
        }
    }
    for(i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(map[i][j]==0) map[i][j]=M;
        }
    }
    prim(0);
    for(i=0;i<max-1;i++)
        scr=scr+map[edge[i].n1][edge[i].n2];
    printf("%d\n", scr);
}

void prim(int start)
{
    int vertex[1000]={0,},i1=0;
    int v,k,nt,i2=0,i,j;
    vertex[i1++] = start;
    while(i1<max)
    {
        nt=M;
        for(i=0; i<i1; i++)
        {
            v=vertex[i];
            for(j=0;j<max;j++)
            {
                k=map[j][v];
                if(k>0&&k<M&&!isVertex(vertex,j))
                {
                    if(k<nt)
                    {
                        nt = k;
                        edge[i2].n1 = v;
                        edge[i2].n2 = j;
                    }
                }
            }
        }
        vertex[i1++]=edge[i2].n2;
        i2++;
    }
}

int isVertex(int vertex[], int a)
{
    for(int i=0; i<max; i++)
        if(vertex[i] == a) return 1;
    return 0;
}

/*
 7 10
 A B 2
 A E 5
 B E 6
 A F 9
 E G 2
 F G 1
 G D 4
 E D 7
 B C 3
 C D 5
 
 (17)
 */