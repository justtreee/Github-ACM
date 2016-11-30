#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000

double q;
int n,len,t;
double val[50],dp[50],price,A,B,C;
char type;
int main()
{
    int i,j,k;
    while(scanf("%lf %d",&q,&n),n)
    {
        len = 0;
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; i++)
        {
            int flag = 1;
            A=0;B=0;C=0;
            scanf("%d",&t);
            for(j=0;j<t;j++)
            {
                scanf(" %c:%lf",&type,&price);
                if(type != 'A' &&type != 'B'&&type != 'C' || price > 600)
                {
                    flag = 0;
                    break;
                }
                if(type == 'A')
                    A+=price;
                else if(type == 'B')
                    B+=price;
                else if(type == 'C')
                    C+=price;
            }
            if(flag&&A+B+C<=1000 && A<=600 &&B<=600&&C<=600)
                val[len++] = A+B+C;

        }

        for(i=0; i<=len; i++)
        {
            for(j=len;j>=1; j--)
            {
                if(j==1 || dp[j-1]>0 && dp[j-1] + val[i]<= q)
                    dp[j] = max(dp[j],dp[j-1]+val[i]);
            }
        }

        int tmp = 0;
        for(i=0; i<=len ;i++)
        {
            if(dp[tmp]<dp[i])
                tmp = i;
        }

        printf("%.2lf\n",dp[tmp]);

    }
return 0;
}
