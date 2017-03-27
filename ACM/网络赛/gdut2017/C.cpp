#include <stdio.h>
int Tryit(int &l,int n=0)
{
    if(l==n) return 1;
    if(n>l) return 0;
    return Tryit(l,n+1)+Tryit(l,n+2)+Tryit(l,n+3);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=1;
        for(int i=1; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            ans*=Tryit(a);
            ans%=10007;//...
        }
        printf("%d\n",ans%10007);
    }

    return 0;
}
