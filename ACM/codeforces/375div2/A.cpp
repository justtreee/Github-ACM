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
    int a[3];
    for(int i=0; i<3; i++)
    {
        cin>>a[i];
    }
    //sort(a,a+3);
    int dis = 0,ans=INF;
    //int m = (a[0]+a[2])/2;
    for(int m=1; m<=100; m++)
    {
        dis = 0;
        for(int i=0; i<3; i++)
        {
            dis+=abs(m-a[i]);
        }
        ans = min(dis,ans);
    }
    cout<<ans<<endl;
    return 0;
}

