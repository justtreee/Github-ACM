#include<iostream>
#include<cmath>
using namespace std;
long long n,k;
int main()
{
    while(cin>>n>>k)
    {
        long long blag=0,s=sqrt(n),q;
        long long i,t=0,ans=-1,p=0;
        if(s*s==n) blag=1;
        for(i=1;i*i<n;i++)
        {
            if(n%i==0)
            {
                t++;
                if(k==t)
                  ans=i;
            }
        }
        if(ans==-1)
        {
            if(blag&&k==t+1)
              ans=sqrt(n);
            else
            {
                if(blag)
                  q=2*t+1;
                else
                  q=2*t;
                if(k<=q&&k>t)
                {
                    k=q-k+1;
                    for(int i=1;i*i<n;i++)
                    {
                        if(n%i==0)
                          p++;
                        if(k==p)
                        {
                            ans=n/i;
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
