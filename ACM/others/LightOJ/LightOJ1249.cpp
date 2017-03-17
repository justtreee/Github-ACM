#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int M=105;
struct node{
    int a,b,c,v;
    string s;
}A[M];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int main()
{
    int T,n;
    cin>>T;
    for(int cas=1; cas<=T;cas++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>A[i].s>>A[i].a>>A[i].b>>A[i].c;
            A[i].v = A[i].a*A[i].b*A[i].c;
        }
        sort(A,A+n,cmp);
        if(A[0].v==A[n-1].v)
            cout<<"Case "<<cas<<": no thief"<<endl;
        else
            cout<<"Case "<<cas<<": "<<A[n-1].s<<" took chocolate from "<<A[0].s<<endl;

    }

    return 0;
}
