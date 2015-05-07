#include <stdio.h>
#include <math.h>
#define M 999
#define MAX 5

struct EDGE {
    int pair1;
    int pair2;
};
EDGE edge[MAX-1];
int G[MAX][MAX] = {{ 0, 1, 3, M, M },
    { 1, 0, 3, 6, M },
    { 3, 3, 0, 4, 2 },
    { M, 6, 4, 0, 5 },
    { M, M, 2, 5, 0 }};


void prim(int start);
int IsVertex(int vertex[], int a);

int main(void)
{
    
    printf("\n\n>> Minimum Spanning Tree (using Prim Algorithm)\n");
    prim(0);
    for(int i=0; i<MAX-1 ; i++)
        printf("\n\tv%d - v%d", edge[i].pair1+1, edge[i].pair2+1);
}

void prim(int start)
{
    int vertex[MAX] = {0,}, index1 = 0;
    int v, k, nearst, index2 = 0;
    
    vertex[index1++] = start;
    
    while(index1 < MAX)
    {
        nearst = M;
        for(int i=0; i<index1; i++)
        {
            v = vertex[i];
            for(int j=0; j<MAX; j++)
            {
                k = G[j][v];
                if(k>0 && k<M && !IsVertex(vertex,j))
                {
                    if(k < nearst) {
                        nearst = k;
                        edge[index2].pair1 = v;
                        edge[index2].pair2 = j;
                    }
                }
            }
        }
        vertex[index1++] = edge[index2].pair2;
        index2++;
    }
}

int IsVertex(int vertex[], int a)
{
    for(int i=0; i<MAX; i++)
        if(vertex[i] == a) return 1;
    return 0;
}