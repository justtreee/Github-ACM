#include <bits/stdc++.h>
using namespace std;
const int M=100005;
const int INF=0x3f3f3f3f;
//int a[M][M],r[M][M],d[M];
int main()
{
    int n,m,q;
    cin>>n>>m;
    vector <vector <int> > a(n,vector <int> (m,0));
    vector <vector <int> > r(n,vector <int> (m,0));
    vector <int> d(n,INF);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            r[i][j] = i;
        }
    }
    for(int j=0; j<m; j++)
    {
        for(int i=1; i<n; i++)
        {
            if(a[i][j]>=a[i-1][j])
                r[i][j] = min(r[i][j],r[i-1][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            d[i] = min(d[i],r[i][j]);
        }
        //cout<<d[i]<<" ";
    }
    //cout<<endl;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;l--;r--;
        if(d[r]<=l) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
