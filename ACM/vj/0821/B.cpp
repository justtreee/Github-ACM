#include <bits/stdc++.h>
using namespace std;
int num[20];
int ans;
int f1(int x)
{
    int k=0;
    while(x)
    {
        num[k++] = x%10;
        x/=10;
    }
    for(int i=0; i<k; i++)
    {
        if(num[i]>8)
            num[i]-=2;
        else if(num[i]>3)
            num[i] -=1;
    }
    return k;
}
void f2(int c)
{
    for(int i=c-1; i>=0; i--)
    {
        ans *= 8;
        ans+=num[i];
    }
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        ans = 0;
        int cnt = f1(n);
        f2(cnt);
        printf("%d: %d\n",n,ans);

    }
    return 0;
}
