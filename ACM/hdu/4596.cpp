#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int cmp(int g,int minn,int maxx)
{
    if((minn%g==0||maxx%g==0)||(minn<0&&maxx>0)||(minn/g-maxx/g>0))
        return 1;
    else
        return 0;
}
int main()
{
    int n,x[1005],y[1005],z[1005];
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        int flag = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                int g=gcd(x[i],x[j]);
                if(cmp(g,y[i]-z[j],z[i]-y[j]))
                {
                    flag = 0;
                    break;
                }
            }
            if(!flag)   break;
        }
        if(flag)    cout<<"Can Take off"<<endl;
        else        cout<<"Cannot Take off"<<endl;
    }

    return 0;
}
