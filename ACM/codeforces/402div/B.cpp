#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[15];int k;
    scanf("%s%d",s,&k);
    int ans=0;
    for(int i=strlen(s)-1;i>=0&&k; i--)
    {
        if(s[i]=='0')
            k--;
        else
            ans++;
    }
    if(k>0) cout<<strlen(s)-1<<endl;
    else
        cout<<ans<<endl;


    return 0;
}
