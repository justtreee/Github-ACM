#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int T,n,m;
struct node
{
    char s[25];
    int val;
} s[105];
int flag[258];
int cmp(node a,node b)
{
    if(a.val == b.val)
        return strcmp(a.s, b.s)<0;
    return a.val>b.val;
}
int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(int cas = 1; cas<=T; cas++)
    {
        scanf("%d\n",&n);
        for(int i = 0; i<n; i++)
        {
            gets(s[i].s);
            memset(flag, 0, sizeof(flag));
            for(int j = 0; s[i].s[j]; j++)
                if(s[i].s[j] !=' ')
                    flag[s[i].s[j]-'A'] = 1;
            s[i].val = 0;
            for(int j = 0; j<26; j++)
                if(flag[j])
                    s[i].val++;
        }
        sort(s,s+n,cmp);
        printf("Case #%d: %s\n",cas,s[0].s);
    }
    return 0;
}
