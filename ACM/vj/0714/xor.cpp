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
int main()
{
    int a1,a2,a3,a4,a5,a6;
    int x;
    while(cin>>a1>>a2>>a3>>a4>>a4>>a5>>a6>>x)
    {

        int ans1,ans2;
        ans1 = (a1+a2+a3+a4+a5+a6)^x;
        ans2 = a1^x+a2^x+a3^x+a4^x+a5^x+a6^x;
        cout<<ans1<<endl;
        cout<<ans2<<endl;
    }
return 0;
}
