#include <bits/stdc++.h>
using namespace std;
int x,y,z,k,maxn;
int l,r,mid;
int ans;
long long f(int a,int b,int c)
{
    return pow(a,c)+pow(b,c)+a*b*c;
}
void bin()
{



}
int main()
{
    while(~scanf("%d",&k),k)
    {
        ans = 0;

        for(z=2; z<31; z++)
        {
            maxn = pow((double)k,1.0/(double)z);
            //cout<<maxn<<",";
            for(x=1; x<=maxn; x++)
            {

                l = x+1;
                r = maxn;
                if(f(x,l,z)>k||f(x,r,z)<k)
                    continue;

                while(l<=r)
                {
                    //cout<<"l=:"<<l<<"r=:"<<r<<endl;
                    mid = (l+r)/2;
                    long long tmp = f(x,mid,z);
                    if(tmp == k)
                    {
                        ans++;
                        break;
                    }
                    else if(tmp<k)
                        l = mid+1;
                    else
                        r = mid-1;
                }
                //cout<<"x="<<x<<endl;
            }
            //cout<<"z="<<z<<endl;
        }
        printf("%d\n",ans);

    }

    return 0;
}
