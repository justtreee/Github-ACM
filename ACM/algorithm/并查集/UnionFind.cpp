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
    return a;/*ֻ�����ϼ�*/

    /*��ģ��
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
        return 0;/*��һ�����ϼ�*/

    pre[b] = a;/*��y��λ�ñ���ϼ�x*/
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
        }/*���³�ʼ��*/
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
        /*��һ������ĺϲ�����*/
        t = 1;/*�������������Ĳ�ֵ�����ж� �ϲ���tӦΪ1*/
        flag = 1;
        while(~scanf("%d %d",&a,&b))
        {
            if(a == 0 && b == 0)
                break;
            if(mark[a] ==0)
            {
                t++;
                /*���õ���+1��֮���ڼ�ȥ����*/
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
                /*ab��������ͬһ���ϼ�����ɻ�*/
            }
            else
                t--;/*�ϲ���ȥ����*/

        }
        if(flag && t ==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
return 0;
}
