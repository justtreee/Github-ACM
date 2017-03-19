#include <stdio.h>
//const int M=1000005;
int next[10010];    int T,n,m;
int a[1000005],b[10010];
void getnext()
{
    int j=0,k=-1;
    next[0] = -1;
    while(j<m)
    {
        if(k==-1 || b[j]==b[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}
int kmp()
{
    int i=0,j=0;
    getnext();
    while(i<n && j<m)
    {
        if(j==-1 || a[i]==b[j])
        {
            i++;j++;
        }
        else
            j=next[j];
    }
    if(j==m)
        return i-m+1;
    else
        return -1;

}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d",&b[i]);
        }
        printf("%d\n",kmp());
    }

    return 0;
}
