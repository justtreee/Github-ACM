#include <bits/stdc++.h>
using namespace std;
int n;
int judge (int m){
    int t=m*n+1;
    for (int i=2;i*i<=t;i++){
        if (t%i==0)return 1;
    }
    return 0;
}

int main()
{
    cin>>n;
    int ans;
    for(int i=1; i<=1000; i++)
    {
        if(judge(i))
        {
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}
