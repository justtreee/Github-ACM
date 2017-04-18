#include <bits/stdc++.h>
using namespace std;
#define next nnn
//void pre_kmp(char x[],int m,int next[])
void pre_kmp(char *x,int m,int *next)
{
    int i,j;
    j = next[0] = -1;
    i = 0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])
            j = next[j];
        if(x[++i] == x[++j])
            next[i] = next[j];
        else
            next[i] =j;
    }
}
int next[100010];
//int kmpcnt(char x[],int m,char y[],int n)
int kmpcnt(char *x,int m,char *y,int n)
{
    int i=0,j=0,ans=0;
    pre_kmp(x,m,next);
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])
            j = next[j];
        i++;j++;
        if(j>=m)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char sa[10005];
        char sb[1000005];
        scanf("%s",sa);
        scanf("%s",sb);
        int ans = kmpcnt(sa,strlen(sa),sb,strlen(sb));
        cout<<ans<<endl;
    }

    return 0;
}
