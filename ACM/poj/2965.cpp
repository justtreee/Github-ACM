//初期:
//一.基本算法:
//     (1)枚举. (poj1753,poj2965)
//     (2)贪心(poj1328,poj2109,poj2586)
//     (3)递归和分治法.
//     (4)递推.
//     (5)构造法.(poj3295)
//     (6)模拟法.(poj1068,poj2632,poj1573,poj2993,poj2996)

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define M 65536
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
bool visit[M];
struct node{
    int stat;
    int stp;
};
struct dway{
    int pre,x,y;
}way[M];
int cal[16] =
{
    63624,62532,61986,61713,
    36744,20292,12066,7953,
    35064,17652,8946 ,4593,
    34959,17487,8751 , 4383
};
int bfs(int tstate)
{
    int i;
    memset(visit,false,sizeof(visit));
    queue<node>Q;
    node a,next;
    a.stat = tstate;
    a.stp = 0;
    Q.push(a);
    visit[tstate] = true;

    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.stat == 0)
        {
            return a.stp;
        }
        for(int i=0; i<16; i++)
        {
            next.stat = a.stat^cal[i];
            next.stp = a.stp+1;
            if(visit[next.stat])
            {
                continue;
            }
            if(next.stat == 0)
            {
                way[next.stat].pre = a.stat;
                way[next.stat].x = i/4+1;
                way[next.stat].y = i%4+1;
                return next.stp;
            }
            way[next.stat].pre = a.stat;
            way[next.stat].x = i/4+1;
            way[next.stat].y = i%4+1;
            visit[next.stat] = true;
            Q.push(next);

        }
    }
    return -1;


}

void outway(int state)
{
    int pres = 0;
    stack <dway> s;
    while(!s.empty())
    {
        s.pop();
    }
    while(pres != state)
    {
        s.push(way[pres]);
        pres = way[pres].pre;
    }
    while(!s.empty())
    {
        dway tmp = s.top();
        s.pop();
        cout<<tmp.x<<" "<<tmp.y<<endl;
    }
}
int main()
{
    char s[5][5];
    while(~scanf("%s",s[0]))
    {
        //cntstp = 0;
        for(int i=1; i<4; i++)
        {
            scanf("%s",s[i]);
        }
        int state = 0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                state <<= 1;
                if(s[i][j]=='+')
                {
                    state+=1;
                }
            }

        }
        int N = bfs(state);
        cout<<N<<endl;
        outway(state);
    }


return 0;
}
