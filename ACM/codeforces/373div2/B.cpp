#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int a1=0,a2 = 0;
    for(int i=0; i<s.size();i++)
    {
        if(i%2)
        {
            if(s[i]!='r')
                a1++;
        }
        else
        {
            if(s[i]!='b')
                a2++;
        }
    }
    int ans = abs(a1-a2)+min(a1,a2);
    a1 = a2 = 0;
    for(int i=0; i<s.size();i++)
    {
        if(i%2)
        {
            if(s[i]!='b')
                a1++;
        }
        else
        {
            if(s[i]!='r')
                a2++;
        }
    }
    ans = min(ans,abs(a1-a2)+min(a1,a2));
    cout<<ans<<endl;
    return 0;
}
