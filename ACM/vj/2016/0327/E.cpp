#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 10005

struct Node{
    double t,x;
}c[M];

bool cmp(Node a, Node b)
{
    return a.t < b.t;
}
int main()
{
    int T,N;
    double ans;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        ans = 0;
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d %d",&c[i].t,&c[i].x);
        }
        sort(c,c+N,cmp);
        for(int i=1; i<N; i++)
        {
            ans = max(ans,abs(c[i].x-c[i-1].x)/(c[i].t-c[i-1].t));
        }
        printf("Case #%d: %.2lf\n",k,ans);
    }
return 0;
}
