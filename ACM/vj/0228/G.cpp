#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1005
int a[M],b[M];
int main()
{
    int n,tslow,tfast,kslow,kfast,win;
    while(~scanf("%d",&n),n)
    {
        win=0;
        for(int i=0;i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        for(tslow=0, tfast=n-1,kslow=0,kfast=n-1;tslow<=tfast,kslow<=kfast;)
        {
            if(a[tslow]>b[kslow])
            {
                tslow++;
                kslow++;
                win++;
            }
            else if(a[tslow]<b[kslow])
            {
                tslow++;
                kfast--;
                win--;
            }
            else if(a[tfast]>b[kfast])
            {
                tfast--;
                kfast--;
                win++;
            }
            else if(a[tfast]<b[kfast])
            {
                tslow++;
                kfast--;
                win--;
            }
            else if(a[tslow]<b[kfast])
            {
                tslow++;
                kfast--;
                win--;
            }
            else
            {
                tslow++;
                kfast--;
            }

        }
        printf("%d\n",win*200);
    }
return 0;
}
