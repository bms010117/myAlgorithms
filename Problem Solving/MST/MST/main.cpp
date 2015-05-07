#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
double dist[101][101];
int pa[101][3], n;
double prim()
{
    double min, mst, minedge[101], minep[101];
    int i, j, minp, intree[101];
    for(i=1;i<=n;i++)
    {
        intree[i]=0;
        minedge[i]=99999;
    }
    mst=0;
    intree[1]=1;
    minp=1;
    for(i=1;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(intree[j]!=1)
            {
                if(minedge[j]>dist[minp][j])
                {
                    minedge[j]=dist[minp][j];
                    minep[j]=minp;
                }
            }
        }
        min=99999;
        for(j=1;j<=n;j++)
        {
            if(intree[j]!=1)
            {
                if(min>minedge[j])
                {
                    min=minedge[j];
                    minp=j;
                }
            }
        }
        mst+=minedge[minp];
        intree[minp]=1;
        pa[i][1]=minep[minp];
        pa[i][2]=minp;
    }
    return mst;
}
int main(void)
{
    int i, j, x[101], y[101];
    double xt, yt;
    ifstream inf;
    inf.open("input2.txt");
    ofstream outf;
    outf.open("output.txt");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                xt=pow(x[i]-x[j],2);
                yt=pow(y[i]-y[j],2);
                if(xt<0)xt*=-1;
                if(yt<0)yt*=-1;
                dist[i][j]=sqrt(xt+yt);
            }
            else dist[i][j]=99999;
        }
    }
    outf << setiosflags(ios::fixed) << setprecision(2) << prim() << endl;
    for(i=1;i<n;i++)
    {
        printf("%d %d", pa[i][1], pa[i][2]);
    }
    
}
