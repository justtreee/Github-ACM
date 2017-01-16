#include <stdio.h>
#include <string.h>

int p[1001],m[1001];
int find(int x)
{
    if(p[x]!=x)
    p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int a,b,k=1;
    while(~scanf("%d%d",&a,&b))
    {
        int i,flag=1,t=0;
        if(a==-1&&b==-1)
        break;
        for(i=0;i<1001;i++)
        {
            p[i]=i;

        }
        if(find(a)==find(b))
            flag=0;
        else
            p[find(b)]=find(a);
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
                p[fb]=fa;
        }
        memset(m,0,sizeof(m));
        for(i=1;i<1001;i++)
        if(p[i]!=i)
            m[find(i)]++;
        for(i=1;i<1001;i++)
        {
            if(m[i]>0)
                t++;
        }
        if(t>1)
            flag=0;
        if(flag==0)
            printf("Case %d is not a tree.\n",k++);
        else
            printf("Case %d is a tree.\n",k++);
    }
    return 0;
}
