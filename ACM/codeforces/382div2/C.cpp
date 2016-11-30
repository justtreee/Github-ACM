#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[90];
    a[0] = 0; a[1] = 1;
    for(int i=2; i<90; i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    int i=0;
    while(n>=a[i])
    {
        i++;
    }
    cout<<i-3<<endl;
    return 0;
}
