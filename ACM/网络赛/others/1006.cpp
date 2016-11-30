#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int main()
{
    int c,r,ans;
    while(~scanf("%d%d",&c,&r))
    {
        ans = c+r-2;
        printf("%d\n",ans);
    }

return 0;
}
