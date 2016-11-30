#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;string s;
    cin>>n;
    while(n--)
    {
        int ans=0;
        cin>>s;
        for(int q=2; q<320;q++)
        {
            for(int i=1; (i)*q*q<=s.size(); i++)
            {
                if(s[i-1]=='y'&&s[i*q-1]=='r'&&s[i*q*q-1]=='x')
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
