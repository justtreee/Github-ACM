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
int cal[16] =
{
    51200,58368,29184,12544,
    35968,20032,10016,4880,
    2248, 1252, 626,  305,
    140,  78,   39,   19
};
int bfs(int state)
{
    int i;
    memset(visit,false,sizeof(visit));
    queue<node>Q;
    node a,next;
    a.stat = state;
    a.stp = 0;
    Q.push(a);
    visit[state] = true;

    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.stat == 0||a.stat == 65535)
        {
            return a.stp;
        }
        for(int i=0; i<16; i++)
        {
            next.stat = a.stat^cal[i];
            next.stp = a.stp+1;
            if(visit[next.stat])
                continue;
            if(next.stat == 0||next.stat == 65535)
                return next.stp;
            visit[next.stat] = true;
            Q.push(next);

        }
    }
    return -1;


}
int main()
{
    char s[5][5];
    while(~scanf("%s",s[0]))
    {
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
                if(s[i][j]=='b')
                {
                    state++;
                }
            }

        }
        int ans = bfs(state);
        if(ans == -1)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
    }


return 0;
}
