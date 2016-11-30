#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int tmp;
        tmp = a;
        a = c;
        c = tmp;
        b += d;
        d = b;
        printf("%d %d\n",a,b);
        printf("%d %d\n",c,d);

    }


    return 0;
}
