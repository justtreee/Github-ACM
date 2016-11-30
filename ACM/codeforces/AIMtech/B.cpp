#include <bits/stdc++.h>
using namespace std;
int x[100000];
int bin(int n,int a)
{
    int l=0,r=n-1,mid=(l+r)/2;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(x[l]<a&&x[r]>a)
        {
            if(x[mid]<a)
            {
                l=mid;
            }
            else if(x[mid]>a)
            {
                r = mid;
            }
            else
                return mid;
        }

    }
}
int main()
{
    int n,a,ans = 0;
    scanf("%d%d",&n,&a);
    for(int i=0; i<n; i++)
    {
        int t;
        scanf("%d",&x[i]);
        //x[i] = t-a;
    }

    sort(x,x+n);
    if(x[0]==0||x[n-1]==0)
    {
        cout<<"t1"<<endl;
        for(int i=0; i<n; i++)
        {
            x[i] -= a;
            //cout<<x[i]<<" ";
        }
        //cout<<endl;
        if(x[0]==0)
            printf("%d\n",x[n-2]);
        else
            printf("%d\n",abs(x[1]));
    }
    else
    {
        cout<<"t2"<<endl;
        int next = a;
        for(int i=0; i<n-1; i++)
        {
            int init = bin(n,next);
            cout<<"looped"<<endl;
            next = min(abs(x[init+1]-x[init]),abs(x[init-1]-x[init]));
            ans+=next;
        }
        printf("%d\n",ans);
    }


    return 0;
}
