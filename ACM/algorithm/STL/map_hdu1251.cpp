#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[12];
    map<string,int> mp;
    while(gets(s)&&(strlen(s)))
    {
        for(int i=strlen(s); i>0; i--)
        {
            s[i] = '\0';
            mp[s]++;
        }
    }
    char t[12];
    while(~scanf("%s",t))
    {
        cout<<mp[t]<<endl;
    }
}
