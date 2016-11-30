#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define I64d_OJ

#ifdef I64d_OJ
#define LL __int64
#endif // I64d_OJ
//#ifdef I64d_OJ
//#define LL long long
//#endif // I64d_OJ

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

inline LL read()
{
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-f;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

template< typename T >
inline void Max(T &a,T &b)
{
    if(a<b) a=b;
}
template< typename T>
inline void Min(T &a,T &b)
{
    if(a>b) a=b;
}

const double pi=(double)acos(-1.0);
const double eps=(double)1e-10;
const int INF= (int) 0x3f3f3f3f;
const int MOD = (int) 1e9+7;
const int MAXN =(int) 1e4+10;
const int MAXM = (int) 1e4+10;

///--------------------START-------------------------
int n,m,s,t;
LL L;
LL dist[MAXN];
//int cnt[MAXN];
//int p[MAXN];
bool vis[MAXN];
int mark[MAXN];

struct Edge
{
    int u,v;
    LL w;
    int next;
} edge[MAXM<<1];
int head[MAXN];
int edgenum;

void Add_Edge(int u,int v,LL w)
{
    edge[edgenum].u=u;
    edge[edgenum].v=v;
    edge[edgenum].w=w;
    edge[edgenum].next=head[u];
    head[u]=edgenum++;
}

void SPFA_BFS(int s)
{
    queue<int> q;
    for(int i=0; i<MAXN; i++) dist[i]=INF;
    dist[s]=0;
//    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));

    q.push(s);
    vis[s]=1;
//    cnt[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            LL w=edge[i].w;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                if(!vis[v])
                {
                    vis[v]=1;
//                    cnt[v]++;
                    q.push(v);
                }
            }
        }
    }
}

void work()
{
    scanf("%d%d%I64d%d%d",&n,&m,&L,&s,&t);
    memset(head,-1,sizeof(head));
    edgenum=0;
    for(int i=0; i<m; i++)
    {
        int u,v;
        LL w;
        scanf("%d%d%I64d",&u,&v,&w);
        if(w==0)
        {
            w=1;
            mark[i]=1;
        }
        Add_Edge(u,v,w);
        Add_Edge(v,u,w);
    }
    SPFA_BFS(s);
    if(dist[t]==INF||dist[t]>L)
    {
        printf("NO\n");
        return;
    }
    cout<<"dist:"<<dist[t]<<endl;
    LL delta=L-dist[t];
    int ok=0;
    if(dist[t]==L) ok=1;
    if(!ok)
    {
        for(int i=0; i<m; i++)
        {
            if(mark[i])
            {
                edge[i*2].w+=delta;
                edge[i*2+1].w+=delta;
                SPFA_BFS(s);
                if(dist[t]==L)
                {
                    ok=1;
                    break;
                }
                else delta=L-dist[t];
            }
        }
    }
    if(!ok) printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=0; i<m; i++)
        {
            printf("%d %d %I64d\n",edge[i*2].u,edge[i*2].v,edge[i*2].w);
        }
    }
}

///--------------------END-------------------------
int main()
{
#ifdef NNever
    freopen("data.in","r",stdin);
///freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}
