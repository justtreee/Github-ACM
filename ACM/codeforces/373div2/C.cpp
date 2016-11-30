#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{

    int n,t;
    string s;
    cin>>n>>t>>s;
    int dot=0,flag =0,pos=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='.')
        {
            dot = i;
            flag = 1;
        }
        if(flag ==1&&s[i]>='5')
        {
            pos = i;    break;
        }
    }
    if(pos <=  dot)
    {
        cout<<s<<endl;
        return 0;
    }
    int last = n,k=0,m=n-dot;

    while(pos>dot&&k<(min(m-1,t))&&s[pos]>='5')
    {
        if(pos-1==dot)
            pos--;
        while(s[pos-1]=='9')
        {
            pos--;
            if(pos-1==dot)
                pos--;
            last  = pos;
        }
        s[pos-1]+=1;
        pos--;
        last = pos;
        k++;

    }

    if(last==-1&&s[0]=='9')
        cout<<'1';
    for(int i=0; i<=last; i++)
    {
        cout<<s[i];
    }
    while(last+1<dot)
    {
        cout<<'0';
        last++;
    }
    cout<<endl;

    return 0;
}
