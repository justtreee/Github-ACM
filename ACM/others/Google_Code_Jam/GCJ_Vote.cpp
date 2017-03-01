#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    int T,n,m;
    scanf("%d",&T);
    for(int cas=1; cas<=T;cas++)
    {
        double n,m;
        scanf("%lf%lf",&n,&m);
        printf("Case #%d: %.8f\n",cas,(n-m)/(n+m));
    }

    return 0;
}
