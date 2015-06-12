#include <stdio.h>
#include <algorithm>
void bisearch(int, int, int);
struct data
{
    int value, start, end;
};
struct data tree[1003];
int k=1, sj, ej, ans, n ,q;
int main(void)
{
    int i, j;
    scanf("%d %d", &n, &q);
    while(1)
    {
        if(n<=k) break;
        k=k*2;
    } //t=2
    printf("%d to %d\n", k, k+n);
    for(i=k;i<k+n;i++) //2, 3, ++
    {
        j=i/2;
        scanf("%d", &tree[i].value);
        tree[i].start=i-k+1, tree[i].end=i-k+1;
        while(j>0)
        {
            tree[j].value+=tree[i].value; //상위 tree의 value를 더하는 과정
            if(tree[j].start==0 || tree[j].start>tree[i].start) tree[j].start=tree[i].start;
            if(tree[j].end==0 || tree[j].end<tree[i].end) tree[j].end=tree[i].end;
            j=j/2;
        }
        for(j=1;j<10;j++) printf("%d ", tree[j].value);
        printf("\n");
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d", &sj, &ej);
        ans=0;
        bisearch(sj ,ej ,1);
        printf("%d\n",ans);
    }
    return 0;
}
void bisearch(int x, int y, int v) //a , b, c
{
    if(tree[v].start>y || tree[v].end<x || v>=k*2) return;
    else if(tree[v].start<x&&tree[v].end>=x) bisearch(x,y,v*2), bisearch(x,y,v*2+1);
    else if(tree[v].end>y&&tree[v].start<=y) bisearch(x,y,v*2), bisearch(x,y,v*2+1);
    else if(tree[v].start>=x&&tree[v].end<=y)
    {
        ans+=tree[v].value; //add sum
        return;
    }
}
//4 2 5 8 12 6 1 3 2 4

