#include <bits/stdc++.h>
using namespace std;
long long f(int x)
{
    int s=0,res=0;
    while(x)
    {
        s = x%10;
        res+=s*s;
        x/=10;
    }
    return res;

}
int main()
{
    long long x;
    while(cin>>x)
    {
        int cnt=0,flag;
        while(1)
        {
            int tmp = x;
            x = f(x);
            cnt++;
            if(x==tmp) {flag = 0;break;}
            else if(x==1)   {flag=1;break;}
            if(cnt>=10000000)  {flag=0;break;}
        }
        if(flag)    cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
