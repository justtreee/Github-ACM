//UESTC 1328
//union find
//whether this man good or bad.
//人们开始互相指控，每个人都会说另外一个人是否是好人。
//好人只说真话，坏人只说假话。
//如果存在一个好人坏人的分类能够满足所有的指控，
//那么输出"Time to show my power"，否则输出"One face meng bi"
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
