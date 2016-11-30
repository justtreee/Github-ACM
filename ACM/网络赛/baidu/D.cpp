#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000004
char a[45];

map<string,int>t;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        sort(a,a+strlen(a));
        printf("%d\n",t[a]++);
    }

return 0;
}

