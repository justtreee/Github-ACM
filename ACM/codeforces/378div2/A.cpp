#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool f(char x)
{
    if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U'||x=='Y')
        return true;
    else
        return false;
}
int main()
{
    char s[105];
    scanf("%s",s);
    int tmp=0,ans=-1;
    for(int i=0; i<strlen(s); i++)
    {
        if(f(s[i]))
        {
            ans = max(ans,tmp);
            tmp = 0;
            continue;
        }
        else
        {
            tmp++;
        }

    }
    ans = max(tmp,ans);
    cout<<ans+1<<endl;
    return 0;
}
