#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 50005
int a[M];
int sum=0;
void add(int &i,int &j)
{
    a[i] += j;
}

void sub(int &i,int &j)
{
    a[i] -= j;
}

void query(int &i,int &j)
{
    for(int k=i;k<=j; k++)
    {
        sum += a[k];
    }
}
int main()
{
    char str[10];
    int t,n,i,j;
    int cas = 1;
    while(~scanf("%d",&t))
    {

        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",cas++);
        while(scanf("%s",&str) && str[0]!='E')
        {
            scanf("%d %d",&i,&j);
            if(!strcmp(str,"Add"))
                add(i,j);
            else if(!strcmp(str,"Sub"))
                sub(i,j);
            else if(!strcmp(str,"Query"))
            {
                sum = 0;
                query(i,j);
                printf("%d\n",sum);
            }

        }
    }

return 0;
}
