#include <bits/stdc++.h>
using namespace std;
const int M=5*1e4+10;
typedef struct cost
{
    int pos;
    int v;
};
bool operator <(cost a,cost b)
{
    return a.v<b.v;
}
priority_queue<cost>q;
int main()
{
    char s[M];
    int cnt=0;long long ans=0;
    scanf("%s",s);
    for(int i=0; s[i]!='\0'; i++)
    {

        if(s[i]=='(')   cnt++;
        else    cnt--;
        if(s[i]=='?')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            cost tmp;
            tmp.pos = i;
            tmp.v = b-a;
            q.push(tmp);
            ans+=b;
            s[i] = ')';
        }
        if(cnt<0&&!q.empty())
        {
            cost tmp = q.top(); q.pop();
            ans -=tmp.v;
            s[tmp.pos]='(';
            cnt+=2;
        }
        if(cnt<0&&q.empty())
        {
            ans=-1; break;
        }

    }
    if(cnt>0)   ans=-1;
    cout<<ans<<endl;
    if(ans>=0)cout<<s<<endl;


    return 0;
}
