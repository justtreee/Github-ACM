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
    int a,n;
    while(~scanf("%d",&n))
    {
        int flag = 1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            if(a==1)
                flag = 0;
        }
        if(flag)
            printf("1\n");
        else
            printf("-1\n");

    }

return 0;
}
