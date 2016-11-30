//UESTC 1328
//union find
//whether this man good or bad.
//���ǿ�ʼ����ָ�أ�ÿ���˶���˵����һ�����Ƿ��Ǻ��ˡ�
//����ֻ˵�滰������ֻ˵�ٻ���
//�������һ�����˻��˵ķ����ܹ��������е�ָ�أ�
//��ô���"Time to show my power"���������"One face meng bi"
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int  M = 10e5;
int pre[2*M+10];//but memory is large.....
void init()
{
    for(int i=1; i<2*M+10; i++)
    {
        pre[i] = i;
    }
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
    int n,x,op;
    scanf("%d",&n);
    init();
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&op);
        if(op == 1)
        {
            unionx(i,x);//good guy tree
            unionx(M+i,M+x);//bad guys are on the right of tree
        }
        else
        {
            unionx(i,M+x);
            unionx(M+i,x);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(find(i)==find(M+i))
        {
            printf("One face meng bi\n");
            return 0;
        }
    }
    printf("Time to show my power\n");

return 0;
}
