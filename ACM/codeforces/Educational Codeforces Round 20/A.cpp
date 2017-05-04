#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int mp[105][105];
    memset(mp,0,sizeof(mp));
    int flag = 1;
    if(k>n*n)
        flag = 0;
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mp[i][j]==1)
                    continue;
                else if(i==j && k)
                {
                    mp[i][j] = 1;
                    k--;
                }
                else if(k>=2)
                {
                    mp[i][j] = mp[j][i] = 1;
                    k-=2;
                }
            }
        }
        if(k)
            flag = 0;
    }
    if(flag)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<mp[i][j]<<" ";
            }cout<<endl;
        }
    }
    else
        cout<<-1<<endl;


    return 0;
}
