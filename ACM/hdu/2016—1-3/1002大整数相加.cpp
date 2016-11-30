#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 1005

int main()
{
    int t,i,j,k;
    char i1[M],i2[M];
    int s1[M],s2[M];
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
       // s1[M] = {0};
       // s2[M] = {0};
        memset(s1,0,1002*sizeof(int));
		memset(s2,0,1002*sizeof(int));
        scanf("%s %s",i1,i2);
        printf("Case %d:\n",i);
        printf("%s + %s = ",i1,i2);

        int len1 = strlen(i1);
        int len2 = strlen(i2);

        k = 0;
        for(j=len1-1; j>=0; j--)
        {
            s1[k++] = i1[j] - '0';
        }
        k = 0;
        for(j=len2 -1; j>=0; j--)
        {
            s2[k++] = i2[j] -'0';
        }
        for(j=0; j<M; j++)
        {
            s1[j] += s2[j];
            if(s1[j]>9)
            {
                s1[j+1]++;
                s1[j]-=10;
            }
        }
        for(j=1001; j>=0; j--)
        {
            if(s1[j])
                break;
        }
        for(k=j; k>=0; k--)
        {
            printf("%d",s1[k]);
        }

        printf("\n");
        if(i!=t)
            printf("\n");
    }
return 0;
}
