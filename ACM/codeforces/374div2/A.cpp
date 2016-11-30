#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int ans[100];
    int tmp = 0;
    int k=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='B') tmp++;
        else
        {
            if(tmp)
                ans[k++] = tmp;
            tmp = 0;
        }
    }
    if(tmp)
        ans[k++] = tmp;
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
