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
    int k,r,ans=0;
    cin>>k>>r;
    int tmp = k%10;
    k%=10;
    while(1)
    {
        tmp%=10;
        if((tmp/r==1&&tmp%r==0)||tmp==0)
            break;
        else
        {//cout<<tmp<<endl;
            tmp+=k;
            ans++;
        }

    }
    cout<<ans+1<<endl;
return 0;
}
