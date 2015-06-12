//깊이우선탐색과너비우선탐색 - 변민서
#include <stdio.h>
FILE *in=fopen("input.txt", "r");
FILE *out=fopen("output.txt","w");
int map[1003][1003], visit[1000], n, e, queue[1000], visit2[1000];
int f, s;
void DFS(int d)
{
    int i;
    visit[d]=1;
    for(i=1;i<=n;i++)
    {
        if(map[d][i]==1&&visit[i]==0)
        {
            printf("%c", i+'A'-1);
            DFS(i);
        }
    }
}
void BFS(int v)
{
    int i;
    visit2[v]=1;
    queue[s++]=v;
    while(f<s)
    {
        v=queue[f++];
        for(i=1;i<=n;i++)
        {
            if(map[v][i]==1 && visit2[i]==0)
            {
                visit2[i]=1;
                queue{s++]=i;
            }
        }
    }
    
}
int main(void)
{
    char c1, c2, c3;
    int i;
    int x, y;
    int start;
    char t1, t2, t3;
    scanf("%d %d", &n, &e);
    for(i=0;i<e;i++)
    {
        scanf("%c%c%c%c", &t1, &c1, &t2, &c2);
        x=c1-'A'+1;
        y=c2-'A'+1;
        map[x][y]=map[y][x]=1;
    }
    scanf("%c%c", &t3, &c3);
    start=c3-'A'+1;
    printf("start @ %d\n", start);
    printf("%c", c3);
    DFS(start);
    printf("\n%c", c3);
    BFS(start);
    return 0;
}
/**
 INPUT
7 9
A B
B E
A E
B C
B F
C F
C D
D G
G F
A
 
 OUTPUT
 ABCDGFE //깊이우선탐색 결과
 ABECFDG //너비우선탐색 결과
 **/