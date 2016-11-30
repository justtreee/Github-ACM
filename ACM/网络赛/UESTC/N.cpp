#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000000
char c,op;
long long ans;
inline long long  read()
{
    c = getchar();
    while(!isdigit(c)) c = getchar();

    long long x = 0;
    while(isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x;
}
int main()
{
    int t,i;
    long long ans,tmp;
    char cal[M];
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        char op;
        long long t1,t2;

        while(1)
        {
            t1 = read();
            if(c=='\n');
            {
                //printf("nnn\n");
                 break;
            }


            if(op=='+')
            {
                ans+= t1;
            }
            else if(op =='-')
            {
                ans -= t1;
            }
            else if(op == '*')
            {

            }
        }

        printf("%lld\n",ans);
    }

return 0;
}
