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
    string s;
    int ud=0,lr=0;
    int u=0,d=0,l=0,r=0;
    cin>>s;
    if(s.size()%2)
        cout<<"-1"<<endl;
    else
    {
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='U')
                {ud++; u++;}
            else if(s[i]=='D')
                {ud--; d++;}
            else if(s[i]=='L')
                {lr--; l++;}
            else if(s[i]=='R')
                {lr++; r++;}
        }

        cout<<(abs(u-d)+abs(l-r))/2<<endl;
    }

return 0;
}
