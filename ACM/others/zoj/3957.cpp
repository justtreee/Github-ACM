#include <bits/stdc++.h>
using namespace std;
void pre(char x[],int m,int kmpnext[])
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])
            j = kmpnext[j];
        if(x[++i] == x[++j])
            kmpnext[i] = kmpnext[j];
        else
            kmpnext[i]  =j;
    }
}
int next[10010];
int KMP(char x[],int m,char y[],int n)
{
    int i,j;
    int ans =0;
    pre(x,m,next);
    i=j=0;
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
    int T;char s[1005];
    cin>>T;
    while(T--)
    {
        scanf("%s",s);
        char dog[5] = "dog";
        char cat[5] = "cat";
        int len = strlen(s);
        int ans = KMP(dog,3,s,len)+KMP(cat,3,s,len);
        cout<<ans<<endl;
    }

    return 0;
}
