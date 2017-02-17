#include <stdio.h>
#include <algorithm>

using namespace std;
#define M 100005

int pre[M];
int mark[M];

int findx(int a)
{
    while(pre[a]!=a)
    {
        a = pre[a];
    }
    return a;/*只返回上级*/

    /*新模板
    if(a == pre[a])
        return a;
    else
        return pre[a] = findx(pre[a])*/
}

int unionx(int a,int b)
{
    a = findx(a);
    b = findx(b);
    if(a==b)
        return 0;/*有一样的上级*/

    pre[b] = a;/*在y的位置标记上级x*/
    return 1;

}
int main()
{
    int a,b,i,t;
    int flag;

    while(1)
    {
        for(i=1;i<M;i++)
        {
            pre[i] = i;
            mark[i] = 0;
        }/*重新初始化*/
        scanf("%d %d",&a,&b);

        if(a==-1 && b==-1)
            break;
        else if(a==0 && b==0)
        {
            printf("Yes\n");
            continue;
        }
        unionx(a,b);
        mark[a] = 1;
        mark[b] = 1;
        /*第一次输入的合并与标记*/
        t = 1;/*引入点数与边数的差值辅助判断 合并后t应为1*/
        flag = 1;
        while(~scanf("%d %d",&a,&b))
        {
            if(a == 0 && b == 0)
                break;
            if(mark[a] ==0)
            {
                t++;
                /*先让点数+1，之后在减去边数*/
                mark[a] = 1;
            }
            if(mark[b] ==0)
            {
                t++;
                mark[b] = 1;
            }
            if(unionx(a,b)==0)
            {
                flag = 0;
                /*ab相连且有同一个上级，则成环*/
            }
            else
                t--;/*合并减去边数*/

        }
        if(flag && t ==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
return 0;
}
