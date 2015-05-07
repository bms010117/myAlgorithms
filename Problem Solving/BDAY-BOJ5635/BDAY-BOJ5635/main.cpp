//
//  main.cpp
//  BDAY-BOJ5635
//
//  Created by 변민서 on 2015. 5. 7..
//  Copyright (c) 2015년 변민서. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
int day[1003], month[1003], year[1003], namenum[1003];
int main(void)
{
    int n, i;
    char s[103][100];
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d %d", &s[i], &day[i], &month[i], &year[i]);
        namenum[i]=i;
    }
    //sort as year
    int j, tmp, tmp2;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(year[i]>year[j])
            {
                tmp=year[i];
                tmp2=namenum[i];
                year[j]=year[i];
                namenum[j]=namenum[i];
                year[i]=tmp;
                namenum[i]=tmp2;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d\n", s[namenum[i]], year[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d %d %d\n", s[i], day[i], month[i], year[i]);
    }
}
