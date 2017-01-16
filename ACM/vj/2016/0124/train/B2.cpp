#include <stdio.h>
#include <string.h>
using namespace std;
#define N 1001
int p[N],m[N];

int find(int a)
{
    if(p[a] != a)
        p[a] = find(p[a]);
    return p[a];
}


int main()
{
    int k,t,a,b,i;
    k = 1;
    int flag;/*1=yes 0=no*/
    while(~scanf("%d %d",&a,&b))
    {
        flag = 1;
        t = 0;
        if(a==-1&&b==-1)
            break;
        for(i=0; i<N; i++)
        {
            p[i] = i;
        }
        if(find(a) == find(b))
            flag = 0;
        else
            p[find(b)] == find(a);
        while(scanf("%d %d",&a,&b))
        {
            if(a == 0 && b==0)
                break;
            int fa,fb;
            fa = find(a);
            fb = find(b);
            if(fa == fb || fb != b)
                flag = 0;
            else
                p[fb] = fa;
        }
        memset(m,0,sizeof(m));
        for(i=1;i<N; i++)
        {
            if(p[i]!=i)
                m[find(i)]++;
        }
        for(i=1;i<N; i++)
        {
            if(m[i]>0)
                t++;
        }
        if(t>1)
            flag = 0;
        if(flag == 0)
            printf("Case %d is not a tree.\n",k++);
        else
            printf("Case %d is a tree.\n",k++);

    }
return 0;
}
