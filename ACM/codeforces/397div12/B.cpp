#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[505];int vis[505];
    scanf("%s",s);
    memset(vis,0,sizeof(vis));
    int k=0,flag=1;
    for(int i=0; i<strlen(s); i++)
    {
        if(vis[i]==0)
        {
            if(k!=s[i]-'a')
            {
                flag = 0;
            }
            else
            {
                for(int j=i; j<strlen(s); j++)
                {
                    if(s[j]==s[i])  vis[j]= 1;
                }
            }
            k++;
        }
    }
    if(flag)    cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
