#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long LL;
int cnt,n,flag;
void DFS(int n,LL m,int cnt)
{
    if(flag)
        return ;
    if(m%n==0)
    {
        flag=1;
        cout<<m<<endl;
        //printf("%lld\n",m);
    }
    if(cnt==19)
        return ;
    DFS(n,m*10,cnt+1);
    DFS(n,m*10+1,cnt+1);
}
int main()
{
    //freopen("T.txt","w",stdout);
    while(~scanf("%d",&n)&&n)
    {
        cnt=0,flag=0;
        DFS(n,1,0);
    }

    return 0;
}
