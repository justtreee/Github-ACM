#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,n1,n2,a[100005];
    cin>>n>>n1>>n2;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int maxn = max(n1,n2);
    int minn = min(n1,n2);
    double cnt=0,tmp1=0,tmp2=0,pos;
    for(int i=n-1; i>=0; i--)
    {
        cnt++;  tmp1+=a[i];
        if(cnt==minn)
        {
            pos = i-1;  break;
        }

    }
    cnt=0;
    for(int i=pos; i>=0; i--)
    {
        cnt++;  tmp2 +=a[i];
        if(cnt==maxn)
        {
            break;
        }
    }
    //cout<<tmp1<<endl<<tmp2<<endl;
    double ans=tmp1/minn+tmp2/maxn;
    printf("%lf\n",ans);
return 0;
}
