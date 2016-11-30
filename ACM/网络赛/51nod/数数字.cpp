#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000000000
char num[M];
int main()
{
    int t,a,b,d,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&d,&n);
        if(a*b<10)
        {
            if(a*b==d)
                printf("%d\n",n);
            else
                printf("0\n");
        }
        else
        {
            if((a*b)%10==0)
            {
                if(d==0)
                    printf("0\n");
                else
                {
                    if((a*b)/10==d)
                        printf("%d\n",n-1);
                    else
                        printf("0\n");
                }
            }
            else
            {
                if()
            }
        }
    }
return 0;
}
