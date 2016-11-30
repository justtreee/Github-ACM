#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 100005
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int x[M],t;

void bin(int a)
{
    int l=0,r=t-1;
    while(l!=r)
    {
        int mid = l/2+r/2;
        if(a>=x[mid])
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    if(x[l]>a)
        l--;
    printf("%d\n",l+1);
}
int main()
{
    int q,m[M];
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+t);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d",&m[i]);
        bin(m[i]);
    }



return 0;
}
