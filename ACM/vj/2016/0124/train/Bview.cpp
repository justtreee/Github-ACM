#include <stdio.h>
#include <string.h>
using namespace std;
int pre[1001],mark[1001];
int find(int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}
int main()
{
    int a,b,k=1;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int i,flag=1,t=0;
        if(a<0&&b<0)//ÉñTM a==-1&&b==-1 »áTLE
            break;
        for(i=0;i<=1000;i++)
            pre[i]=i;
        if(find(a)==find(b))
            flag=0;
        else
            pre[find(b)]=find(a);
        while(scanf("%d%d",&a,&b))
        {
            if(a==0&&b==0)
                break;
            int fa,fb;
            fa=find(a);
            fb=find(b);
            if(fa==fb||fb!=b)
                flag=0;
            else
                pre[fb]=fa;
        }
        memset(mark,0,sizeof(mark));
        for(i=1;i<=1000;i++)
            if(pre[i]!=i)
                mark[find(i)]++;
        for(i=1;i<=1000;i++)
        if(mark[i]>0)
            t++;
        if(t>1)
            flag=0;
        if(flag==0)
            printf("Case %d is not a tree.\n",k++);
        else
            printf("Case %d is a tree.\n",k++);
    }
    return 0;
}
