#include <stdio.h>
using namespace std;

struct times{
    int h,m,s;
};
times ans;

int sum(times a,times b)
{
    int fs,fm;
    int rs,rm;
    fs = (a.s + b.s)/60;
    rs = (a.s + b.s)%60;
    ans.s = rs;
    fm = (a.m + b.m)/60;
    rm = (a.m + b.m)%60;
    ans.m = (fs + rm) % 60;
    fm += (fs +rm) /60;
    ans.h = (a.h+b.h) + fm;

}
int main()
{
    times a,b;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&a.h,&a.m,&a.s,&b.h,&b.m,&b.s);
        sum(a,b);
        printf("%d %d %d\n",ans.h,ans.m,ans.s);
    }
return 0;
}
