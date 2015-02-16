#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int n;
int map[1003][1003], visit[10003];
int v1, v2;
void DFS(int v)
{
    int i;
    visit[v]=1;
    for(i=1;i<=n;i++)
    {
        if(map[v][i]==1&&visit[i]==0)
        {
           // printf("%c", i+'A'-1);
            printf("%d to %d ", v, i);
            DFS(i);
        }
    }
}
int main(void)
{
    int start;
    int e, i;
    char t1, t2, t3;
    char c1, c2, c3;
    scanf("%d %d", &n, &e);
    for(i=0;i<e;i++)
    {
        scanf("%c%c%c%c", &t1, &c1, &t2, &c2);
        v1=c1-'A'+1, v2=c2-'A'+1;
        map[v1][v2] = map[v2][v1] = 1; //인접행렬
    }
    scanf("%c%c",&t3, &c3);
    start=c3-'A'+1;
    printf("%c", c3);
    DFS(start);
    return 0;
}
/*
 7 9
 1 2
 2 5
 1 5
 2 3
 2 6
 3 6
 3 4
 4 7
 7 6
 1
 
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
 */