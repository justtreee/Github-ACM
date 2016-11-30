#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int pre[M],mark[M];
int flag = 1;

int find(int a)
{
    if(pre[a] != a)
        pre[a] = find(pre[a]);
    return pre[a];
}

void unionx(int a,int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa != fb)
        pre[fb] = fa;
    else
        flag = 0;
}
int main()
{
    int a,b;
    int i,count = 1;

    while(~scanf("%d%d",&a,&b))
    {

        for(i=0; i<M; i++)
        {
            pre[i] = i;
            mark[i] = 0;
        }
        if(a==0&&b==0)
        {
            printf("Case %d is a tree.\n",count);
            continue;

        }
        if(a==-1&&b==-1)
            break;
        flag = 1;
        mark[a] = 1;
        mark[b] = 1;
        unionx(a,b);
        while(~scanf("%d%d",&a,&b))
        {
            if(a==0&&b==0)
                break;
            unionx(a,b);
            mark[a] = mark[b] =1;

        }
        int t=0;
        for(int j=0; j<M; j++)
        {
            if(mark[j] && pre[j] == j)
                t++;
        }
        if(t>1)
            flag =0;
        if(flag)
            printf("Case %d is a tree.\n",count);
        else
            printf("Case %d is not a tree.\n",count);


        count++;

    }
return 0;
}
