#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(k%2)
    {
        int mid = (k+1)/2;
        cout<<mid<<" ";
        for(int i=1; i<=k; i++)
        {
            if(i%2)
            {
                mid+=i;
                cout<<mid<<" ";
            }
            else
            {
                mid-=i;
                cout<<mid<<" ";
            }
        }
        for(int i=k+2; i<=n; i++)
            cout<<i<<" ";
    }
    else
    {
        int mid = k/2+1;
        cout<<mid<<" ";
        for(int i=1; i<=k ;i++)
        {
            if(i%2)
            {
                mid -= i;
                cout<<mid<<" ";
            }
            else
            {
                mid += i;
                cout<<mid<<" ";
            }

        }
        for(int i=k+2; i<=n; i++)
            cout<<i<<" ";
    }

    return 0;
}
