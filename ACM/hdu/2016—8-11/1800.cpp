#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
map<int,int>M;
int main()
{
    int n,l;
    while(~scanf("%d",&n))
    {
        M.clear();
        for(int i=0;i<n; i++)
        {
            scanf("%d",&l);
            M[l]++;
        }
        map<int,int>::iterator it;
        int ans = 0;
        for(it=M.begin(); it!=M.end();it++)
        {
            ans = max(it->second,ans);
        }
        cout<<ans<<endl;
    }


    return 0;
}
