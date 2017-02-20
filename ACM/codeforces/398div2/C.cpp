#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+10;
vector <int> mp[M];
int n,a[M],t[M];
int rt=0,alval=0;
int sum[M];int tg;
int ans1=-1,ans2=-1;
void dfs(int s,int from)
{
    sum[s] = t[s];
    for(int v=0; v<mp[s].size();v++)
    {
        int vv = mp[s][v];
        if(vv==from) continue;
        dfs(vv,s);
        sum[s] +=sum[vv];
    }
    if(sum[s]==tg)
    {
        if(from == -1)  return;//WA
        if(ans1==-1)
        {
            ans1 = s;
            sum[s] = 0;
        }
        else if(ans2==-1)
        {
            ans2 = s;
            sum[s] = 0;
        }

    }
}
int main()
{
    int flag=1;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&a[i],&t[i]);
        alval+=t[i];
        if(a[i]==0)
        {
            rt = i;
        }
        else
        {
            mp[i].push_back(a[i]);
            mp[a[i]].push_back(i);
        }
    }
//    for(int i=1; i<=n; i++)
//    {
//        cout<<i<<": ";
//        for(int j=0;j<mp[i].size();j++)
//        {
//            cout<<mp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    for(int i=0; i<=n; i++)
//    {
//        cout<<sum[i]<<" ";
//    }cout<<endl;
    if(alval%3)   flag = 0;
    else
    {
        tg = alval/3;
        dfs(rt,-1);
        if(ans1==-1||ans2==-1)
        {
            flag = 0;//cout<<"==-1-1=="<<endl;
        }
    }
    if(flag)    cout<<ans1<<" "<<ans2<<endl;
    else        cout<<-1<<endl;
    return 0;
}
