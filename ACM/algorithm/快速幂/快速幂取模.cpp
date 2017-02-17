#include <stdio.h>
#include <algorithm>
using namespace std;

int mod(int a,int b,int p)
{
    int r = 1;
    while(b--)
    {
        r = (a * r)%p;

    }
    return r;
}

int main()
{
    int a,b,p;
    while(~scanf("%d %d %d",&a,&b,&p))
    {
        printf("%d\n",mod(a,b,p));
    }

return 0;
}
