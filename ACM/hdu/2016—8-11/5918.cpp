#include <cstdio>
#include <iostream>
using namespace std;
int a[1000005],b[1000005];
int next[1000005];
int ans;
int t,n,m,p,q;
void getnext(int *b,int m)
{
    int i=0,j=-1;
    next[0] = -1;
    while(i<m)
    {
        if(b[i] == b[j]|| j==-1)
        {
            i++;
            j++;
            next[i]= j;
        }
        else
            j = next[j];
    }

}
int kmp(int *a,int n,int *b,int m,int *next,int q,int p)
{
    int i=q,j=0;
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i+=p;
            j++;
            if(j==m)
            {
                j = next[j];
                ans++;
            }
        }
        else
            j = next[j];
    }
}
void test()
{
    for(int i=0; i<n; i++)
    {
        cout<<i<<"."<<next[i]<<" ";

    }
    cout<<endl;
}
int main()
{

    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        ans = 0;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d",&b[i]);
        }
        getnext(b,m);
        for(int i=0;i<p; i++)
        {
            if(i>=n-(m-1)*p)
                break;
            kmp(a,n,b,m,next,i,p);
        }
        //test();
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}
