#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int M=100005;
int vis[M];
int x,y;
struct node
{
    int x,s;
};
bool check(node a)
{
    return (a.x>=0&&a.x<=100000)&&!vis[a.x];
}

int BFS()
{
    node s,next;
    queue <node> q;
    s.x=x;
    s.s=0;
    vis[x]=1;
    q.push(s);
    while(!q.empty())
    {
        node tp=q.front();
        q.pop();
        for(int i=0; i<3; i++)
        {
            if(i==0)
            {
                next.x = tp.x-1;
            }
            else if(i==1)
            {
                next.x = tp.x+1;
            }
            else
                next.x = tp.x*2;
            if(!check(next))    continue;
            vis[next.x] = 1;
            next.s = tp.s+1;
            q.push(next);
            if(next.x==y)
                return next.s;
        }
    }
    return -1;

}
int main()
{
    scanf("%d%d",&x,&y);
    memset(vis,0,sizeof(vis));
    if(x>=y)
        cout<<x-y<<endl;
    else
        cout<<BFS()<<endl;

    return 0;
}
