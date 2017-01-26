#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int M = 300005;
struct node{
    ll v,t;
}val[M];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int main()
{
    int a,b,c,m;int v1=0,v2=0;
    string s;
    cin>>a>>b>>c>>m;
    for(int i=0; i<m; i++)
    {
        cin>>val[i].v>>s;
        if(s[0]=='U')   {val[i].t = 1;}
        else    {val[i].t = 2;}

    }
    sort(val,val+m,cmp);
    ll cnt = 0,sum = 0;
    for(int i=0; i<m; i++)
    {
        if(val[i].t==1)
        {
            if(a>0)
            {
                a--;    cnt++;  sum+=val[i].v;
            }
            else if(a==0&&c>0)
            {
                c--;    cnt++;  sum+=val[i].v;
            }
        }
        else
        {
            if(b>0)
            {
                b--;    cnt++;  sum+=val[i].v;
            }
            else if(b==0&&c>0)
            {
                c--;    cnt++;  sum+=val[i].v;
            }
        }
    }
    cout<<cnt<<" "<<sum<<endl;
return 0;
}

