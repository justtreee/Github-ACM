#include <bits/stdc++.h>
using namespace std;
const int M = 105;
const int INF = (0x3f3f3f3f);
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n;char t[5],a[10],b[5];
    map<string,int> m;
    cin>>n; scanf("%s",t);
    m[t] = 1;
    int cnt = 0;
    for(int cas=0; cas<n; cas++)
    {
        scanf("%s",a);
        int k=0;
        for(int i=5; i<8; i++)
        {
            b[k++] = a[i];
        }
        b[k] = '\0';
        if(m[b]==1)//string can't
            cnt++;
    }
    if(cnt==n/2&&n%2==0)    cout<<"home"<<endl;
    else    cout<<"contest"<<endl;
return 0;
}
