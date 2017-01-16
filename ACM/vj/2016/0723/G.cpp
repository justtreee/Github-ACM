#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1502
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n[M] = {1};
    int n2=0,n3=0,n5=0;
    for(int i=1; i<1500; i++)
    {
        for(; n2<i; n2++)
        {
            if(n[n2]*2>n[i-1])
                break;
        }
        for(; n3<i; n3++)
        {
            if(n[n3]*3>n[i-1])
                break;
        }
        for(; n5<i; n5++)
        {
            if(n[n5]*5>n[i-1])
                break;
        }
        n[i] = min(n[n2]*2,n[n3]*3);
        n[i] = min(n[i],n[n5]*5);

    }
    printf("The 1500'th ugly number is %d.\n",n[1499]);
return 0;
}
