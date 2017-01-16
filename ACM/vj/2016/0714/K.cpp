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
int cal(int x)
{
    int sum = 0;
    x = x*2-1;
    while(x>=1)
    {
        sum += x;
        x -= 2;
    }
    return sum;
}
int main()
{
    int a[6];
    int n =0;
    for(int i=0; i<6; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<6; i+=2)
    {
        if(i==5)
        {
            a[0] += a[i];
            a[i-1] += a[i];
            //printf("cal = %d\n",cal(a[i]));
            n += cal(a[i]);
            //a[i] = 0;
        }
        else
        {
            a[i-1] += a[i];
            a[i+1] += a[i];
            //printf("cal = %d\n",cal(a[i]));
            n += cal(a[i]);
            //a[i] = 0;
        }
    }
//    for(int i=0; i<6; i++)
//    {
//        cout<<a[i]<<",";
//    }
    //cout<<endl;
    //cout<<n<<endl;
    int ans = cal(a[0]) - n;
    cout<<ans<<endl;
return 0;
}
