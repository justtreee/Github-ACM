#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,a;int n,k;
    int cnt[105];
    memset(cnt,0,sizeof(cnt));
    cin>>n>>k;
    for(int i=0;i<n; i++)
    {
        cin>>s;
        cnt[s.length()]++;
    }
    cin>>a;
    int len = a.length();
    int minn=0,maxx=0;
    for(int i=1; i<=len; i++)
    {
        if(i==len)
        {
            minn+=1;    maxx+=cnt[i];
        }
        else
        {
            minn+=cnt[i];
            maxx+=cnt[i];
        }
    }
    minn+=(minn-1)/k*5;
    maxx+=(maxx-1)/k*5;
    cout<<minn<<" "<<maxx<<endl;
    return 0;
}
