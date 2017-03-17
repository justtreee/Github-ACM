#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    string s;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        cout<<"Case "<<cas<<":"<<endl;
        int all=0,x;
        cin>>n;
        while(n--)
        {
            cin>>s;
            if(s[0]=='d')
            {
                cin>>x;
                all+=x;
            }
            else
                cout<<all<<endl;


        }
    }

    return 0;
}
