#include <bits/stdc++.h>
using namespace std;
map<string ,int > mmap;
int main()
{
    int n,m;
    cin>>n>>m;
    string a[1000],b[1000];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mmap[a[i]]=1;
    }
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
        if(mmap[b[i]])
            cnt++;
    }
    if(cnt%2)
    {
        n-=cnt; m-=cnt;
        n++;
    }
    else
    {
        n-=cnt; m-=cnt;
    }

    if(n>m)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
