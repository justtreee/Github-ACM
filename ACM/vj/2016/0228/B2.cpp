#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 105
int temp;
struct node
{
    int num,son[M];
}pre[M];
void f(int i)
{
    if(pre[i].num == 0)
        return ;
    temp += pre[i].num;
    for(int j=0; j<pre[i].num; j++)
    {
        f(pre[i].son[j]);
    }
}
int main()
{
    int n,k,a,b,count;
    while(~scanf("%d%d",&n,&k))
    {
        memset(pre,0,sizeof(pre));
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&a,&b);
            pre[a].son[pre[a].num] = b;
            pre[a].num++;

        }
        count = 0;
        for(int i=0; i<=n; i++)
        {

            temp = pre[i].num;
            for(int j=0; j<pre[i].num; j++)
            {
                f(pre[i].son[j]);
            }
            if(temp == k)
                count++;
        }
        printf("%d\n",count);

    }
return 0;
}
