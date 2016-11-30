#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 14

struct{
    int a;
    int isused;
}init[15];

int isallused = 0;
int s[15];
int t,n,s;

void allused()
{
    for(int i=0; i<n; i++)
    {
        if(init[i].isused != 0 || init[i].isused != -1)
            isallused = 1;
        else
        {
            isallused = 0;
            break;
        }
    }
}

int main()
{

    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;

        memset(s,-1,sizeof(s));
        for(int i=0; i<15; i++)
        {
            init[i].a = -1;
            init[i].isused = -1;
        }

        scanf("%d%d",&n,&s);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&init[i].a);
            init[i].isused = 0;
        }
        while(isallused == 0)
        {

        }

    }

return 0;
}

