#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    int strt,e;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='G')
            strt = i;
        if(s[i]=='T')
            e = i;
    }
    int flag =0;
    if(strt<e)
    {
        //cout<<strt<<endl<<s[strt]<<endl;
        for(int i=strt; i<n; i+=k)
        {
            //cout<<i<<endl<<s[i]<<endl;
            if(s[i]=='#')
            {
                cout<<"NO"<<endl;
                flag =1;
                break;
            }
            if(s[i]=='.')
            {
                continue;
            }
            if(s[i]=='T')
            {
                cout<<"YES"<<endl;flag =1;
                break;
            }
        }
    }
    else
    {
        for(int i=strt; i>=0; i-=k)
        {
            if(s[i]=='#')
            {
                cout<<"NO"<<endl;flag =1;
                break;
            }
            if(s[i]=='.')   continue;
            if(s[i]=='T')
            {
                cout<<"YES"<<endl;flag =1;
                break;
            }
        }
    }
    if(!flag)   cout<<"NO"<<endl;

    return 0;
}
