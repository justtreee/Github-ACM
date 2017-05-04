#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
int main()
{
    int n,a[M],pos[M];
    cin>>n;
    int k=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            pos[k++] = i;
        }
    }
    pos[k] = n;
    int kk=0;
    for(int i=1; i<=n; i++)
    {
        if(kk==0)
        {
            if(i<pos[kk])
            {
                a[i] = pos[kk]-i;
            }
            else if(i==pos[kk])
                kk++;
        }
        else if(kk==k)
        {
            if(i>pos[kk-1])
                a[i] = abs(pos[kk-1]-i);
        }
        else
        {
            if(i>pos[kk-1]&&i<pos[kk])
                a[i] = min(abs(pos[kk]-i),abs(pos[kk-1]-i));
            else if(i==pos[kk])
                kk++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}
