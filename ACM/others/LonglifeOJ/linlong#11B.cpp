#include <bits/stdc++.h>
using namespace std;
int len,ans[1000050];
int T,a[1000050];
int bin(int i,int tl)
{
    int l,r,mid;
    l=1,r= tl;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(ans[mid]>=a[i])
            r = mid-1;
        else
            l = mid +1;
    }
    return l;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d",&T))
    {
        int k=1;
        memset(a,0,sizeof(a));
        while(T--)
        {
            int n0=-1,nn[10],n1=-1;
            for(int i=0; i<6; i++)
            {
                scanf("%d",&nn[i]);
            }
            sort(nn,nn+6,cmp);
            for(int i=0; i<6; i++)
            {
                a[k++] = nn[i];
            }
        }
        k = k-1;
    //...........
//    for(int i=1; i<=k; i++)
//    {
//        cout<<a[i]<<" ";
//    }cout<<endl;
    //.............
        ans[1] = a[1];
        len = 1;int j=0;
        for(int i=2; i<=k; i++)
        {
            if(a[i]<=ans[1])
                j=1;
            else if(a[i]>ans[len])
                j = ++len;
            else
                j = bin(i,len);
            ans[j] = a[i];
        }
        printf("%d\n",len);
    }

    return 0;
}
