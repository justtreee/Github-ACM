//unfinished

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,len;
struct stc{
    int length;
    int mark;
}stick[21];

int  dfs(int len,int l,int count,int pos)
{
    if(count ==4)
        return 1;
    for(int i=pos; i<m; i++)
    {
        if(stick[i].mark)
            continue;
        if(len == (l+stick[i].length))
        {
            stick[i].mark = 1;
            if(dfs(len,0,count+1,0))
                return 1;

            stick[i].mark = 0;

        }
        else if(len > (l + stick[i].length))
        {
            stick[i].mark  = 1;
            l+= stick[i].length;
            if(dfs(len,l,count,i+1))
                return 1;


            l -= stick[i].length;
            stick[i].mark = 0;

        }
    }
}

bool cmp(const stc &a,const stc &b)
{
    return a.length>b.length;
}


int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        len = 0;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&stick[i].length);
            len += stick[i].length;
            stick[i].mark = 0;
        }
        if(len%4 || m<4)
        {
            printf("no\n");
            continue;
        }
        else
        {
            len /= 4;
            sort(stick,stick+m,cmp);
            if(dfs(len,0,0,0))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
return 0;
}
