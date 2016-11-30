#include <bits/stdc++.h>
using namespace std;
map<int ,int> m;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        m[1000000000] = 1;
        for(int i=0; i<n; i++)
        {
            int id,g,ans;
            cin>>id>>g;
            m[g] = id;
            map<int,int>::iterator it = m.find(g);
            if(it == m.begin())
            {
                ans=(++it)->second;
            }
            else
            {
                map<int ,int>::iterator it1 = it;
                if(abs((++it1)->first-g) >= abs((--it)->first-g))
                {
                    ans = it->second;
                }
                else
                {
                    ans = it1->second;
                }
            }
            cout<<id<<" "<<ans<<endl;
        }
        m.clear();
    }

    return 0;
}
