#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 1000
int main()
{
    int t;
    __int64 n;
    int a[10]={};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        n %= 10;
        if(n==1||n==4 || n==5 || n==6||n==9)
            printf("%d\n",n);
        else if(n==2)
            printf("8\n");
        else if(n==3)
            printf("7\n");
        else if(n==7)
            printf("3\n");
        else if(n==8)
            printf("2\n");
    }

return 0;
}
