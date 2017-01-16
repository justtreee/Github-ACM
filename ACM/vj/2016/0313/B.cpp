#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int lamp[M];
int main()
{
    int n,m,t,b;
    int flag = 1;
    scanf("%d%d",&n,&m);
    for(int i=0; i<=m; i++)
    {
        lamp[i] = 0;
    }
    while(n--)
    {
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&b);
            lamp[b] = 1;
        }
    }

    for(int i=1; i<=m; i++)
    {
        if(lamp[i]==0)
        {
            flag = 0;
            break;
        }
    }
    if(!flag)
        printf("NO\n");
    else
        printf("YES\n");
return 0;
}
