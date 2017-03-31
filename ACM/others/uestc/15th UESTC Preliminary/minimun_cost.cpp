#include <bits/stdc++.h>
using namespace std;
const int N=1005;
struct node
{
    int a,c,l,r;
} cost[N];
bool cmp(node a,node b)
{
    return a.c<b.c;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    int T;
//    scanf("%d",&T);
//    while(T--)
//    {
        int n,s;
        scanf("%d%d",&n,&s);
        int sum=0,maxx=0,minn=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&cost[i].a,&cost[i].c,&cost[i].l,&cost[i].r);;
            sum+=cost[i].a;
            maxx += cost[i].r;
            minn += cost[i].l;
        }
        //cout<<"sum = "<<sum<<endl;
        sort(cost,cost+n,cmp);
        int ans=0;
        if(sum<s)
        {
            if(maxx<s)
            {
                printf("impossible\n");
                return 0;
            }
            for(int i=0; i<n; i++)
            {
                if(cost[i].r-cost[i].a<s-sum)
                {
                    sum+=cost[i].r-cost[i].a;
                    ans+=(cost[i].r-cost[i].a)*cost[i].c;
                }
                else
                {
                    ans+=(s-sum)*cost[i].c;
                    sum = s;
                    break;
                }
            }
        }
        else
        {
            if(minn>s)
            {
                printf("impossible\n");
                return 0;
            }
            for(int i=0; i<n; i++)
            {
                if(cost[i].a-cost[i].l<sum-s)
                {
                    sum-=cost[i].a-cost[i].l;
                    ans+=(cost[i].a-cost[i].l)*cost[i].c;
                }
                else
                {
                    ans+=(sum-s)*cost[i].c;
                    sum = s;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    //}
    return 0;
}
