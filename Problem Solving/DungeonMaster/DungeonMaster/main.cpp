#include <stdio.h>
#include <string.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int xm[6]={-1, 1, 0, 0, 0, 0}, ym[6]={0, 0, -1, 1, 0, 0}, zm[6]={0, 0, 0, 0, -1, 1}, px[100003], py[100003], map[103][103][103], pz[100003];
int arr[100][100][100];
char str[1000000];
int main(void)
{
	int i=0, j=0, k=0;
	int x=0, y=0, z=0;
	int mkx=0, mky=0, mkz=0;
	int tx=0, ty=0, tz=0, sx=0, sy=0, sz=0;
	int f=0, s=0;
	f=s=0;
	fscanf(in, "%d %d %d", &x, &y, &z);
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			fscanf(in, "%s", &str);
			for(k=0;k<=z-1;k++)
			{
				if(str[k]==46)
				{
					arr[i][j][k]=0;
				}
				else if(str[k]==35)
				{
					arr[i][j][k]=1;
				}
				else if(str[k]==83)
				{
					sx=i, sy=j, sz=k;
					arr[i][j][k]=2;
				}
				else if(str[k]==69)
				{
					mkx=i, mky=j, mkz=k;
					arr[i][j][k]=0;
				}
			}
		}
	}
	px[f]=sx;
	py[f]=sy;
	pz[f]=sz;
	while(f<=s)
	{
		for(i=0;i<6;i++)
		{
			tx=px[f]+xm[i];
			ty=py[f]+ym[i];
			tz=pz[f]+zm[i];
			if(tx>0&&tx<=x&&ty>0&&ty<=y&&tz>0&&tz<=z)
			{
				if(arr[tx][ty][tz]==0)
				{
					s++;
					px[s]=tx;
					py[s]=ty;
					pz[s]=tz;
					arr[tx][ty][tz]=arr[px[f]][py[f]][pz[f]]+1;
				}
			}
		}
		f++;
	}
	if(arr[mkx][mky][mkz]==0)
	{
		fprintf(out, "0\n");
		return 0;
	}
	fprintf(out, "%d", arr[mkx][mky][mkz]-2);
	return 0;
}


