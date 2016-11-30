#include <bits/stdc++.h>
using namespace std;
struct St{
    int mmin,mmid,mmax,index;
}s[100005];
bool cmp(St a,St b)
{
    if(a.mmax==b.mmax&&a.mmid==b.mmid)
        return a.mmin<b.mmin;
    if(a.mmax==b.mmax)
        return a.mmid<b.mmid;
    else
        return a.mmax<b.mmax;

}

bool p(int a,int b)
{
    if(s[a].mmax==s[b].mmax&&s[a].mmid==s[b].mmid)
        return 1;
    else
        return 0;
}
int main()
{
    int n,ans=0,flag=0,ans0,ans1,ans2;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int tmin = min(x,min(y,z));
        int tmax = max(x,max(y,z));
        if(tmin>ans)
        {
            ans = tmin;
            ans0 = i;
            flag = 1;
        }
        s[i].mmin = tmin;
        s[i].mmax = tmax;
        s[i].mmid = x+y+z-tmin-tmax;
        s[i].index = i;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=n; i>=2; i--)
    {
        if(p(i,i-1))
        {
            int tmp = min(s[i].mmin+s[i-1].mmin,min(s[i].mmax,s[i].mmid));
            if(tmp>ans)
            {
                flag = 2;
                ans = tmp;
                ans1 = s[i-1].index;
                ans2 = s[i].index;
            }
        }
    }
    cout<<flag<<endl;
    if(flag==1) cout<<ans0<<endl;
    else    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}
