#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n,p[105];
    string s[105];
    cin>>n;

    for(int i=0; i<n;i++)
    {
        cin>>p[i];
    }
    getchar();
    for(int i=0; i<n; i++)
    {
        //cin>>s[i];
        getline(cin,s[i]);
        //cout<<":::"<<s[i]<<endl;
    }
    for(int i=0;i <n; i++)
    {
        int pp=0;
        for(int j=0; j<s[i].length(); j++)
        {
            if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='i'||s[i][j]=='o'||s[i][j]=='u'||s[i][j]=='y')
                pp++;
        }
        if(pp!=p[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;
return 0;
}
