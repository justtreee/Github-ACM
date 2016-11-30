#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int aa,index;
}a[100005];
//void test()
//{
//    for(int i=1; i<=m; i++)
//    {
//        cout<<a[i].aa<<" ";
//    }
//    cout<<endl;
//    for(int i=1; i<=m; i++)
//    {
//        cout<<a[i].index<<" ";
//    }
//}


bool cmp(node a,node b)
{
    return a.aa>b.aa;
}
int main()
{
    int n,m,d[100005],ans=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>a[i].aa;
        a[i].index = i;
    }
    sort(a+1,a+m+1,cmp);
    int k=1,day=0;
    for(int i=1; i<=n; i++)
    {
        if(d[i]!=a[k].index)
        {
            day++;
            if(day>=a[k].aa)
            {
                ans+=day+1;
                day = 0;
                k++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
