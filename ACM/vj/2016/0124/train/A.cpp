#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 205

int pre[M],mark[M];
int ans;

struct sars{
    int sc,ec,spe;
};
sars s[M];
bool cmp(sars s1,sars s2)
{
    return s1.spe < s2.spe;
}

int find(int a)
{
    if(pre[a] != a)
        pre[a] = find(pre[a]);
    return pre[a];
}
int unionx(int a,int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa != fb)
        pre[fb] = fa;
}
int main()
{
    int m,n,q,s,e;
    while(~scanf("%d%d",&n,&m))
    {
        int i;



        for(i=1; i<M ;i++)
        {
            scanf("%d%d%d",&s[i].sc,&s[i].ec,&s[i].spe);
        }
        sort(s,s+M,cmp);

        scanf("%d",&q);
        while(q--)
        {
            ans = 0;
            int temp;
            scanf("%d%d",&s,&e);
            for(i=0; i<M ;i++)
            {
                int k;
                for(k=0; k<M; k++)
                {
                    pre[k] = k;
                }
                temp = 0;
                int j;
                for(j=i; j<M; j++)
                {
                    unionx(s[j].sc,s[j].ec);
                    if(find(s) == find(e))
                    {
                        temp = s[j].spe - s[i].spe;
                    }
                }
                ans = ans<temp?ans:temp;


            }
            if(ans == 0)
                ans = -1;
            printf("%d\n",ans);

        }
    }
return 0;
}
