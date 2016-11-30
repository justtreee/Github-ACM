#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct seed
{
    LL Q,P,N,M;
}s[1005];
int main()
{
    int T,w,h,A,D;
    LL Y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%lld",&w,&h,&A,&D,&Y);
        for(int i=1; i<=A; i++)
        {
            cin>>s[i].Q>>s[i].P>>s[i].N>>s[i].M;
        }

//        for(int i=0; i<A; i++)
//        {
//            printf("%f %f %f %f\n",s[i].Q,s[i].P,s[i].N,s[i].M);
//        }

    }

    return 0;
}
