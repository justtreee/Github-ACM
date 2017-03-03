#include <bits/stdc++.h>
using namespace std;
vector <int> gp[2100];
vector <int> gq[2100];
int T,n;char a[2100];int dis[2100];
bool pbfs(int s)
{
    memset(dis,0,sizeof(dis));
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(int i=0; i<gp[u].size();i++)
        {//cout<<"loop"<<endl;
            int v=gp[u][i];
            if(dis[v]!=0)   continue;
            Q.push(v);
            dis[v] = dis[u]+1;
            if(dis[v]>=2)
                return false;
        }
    }
    return true;
}
bool qbfs(int s)
{
    memset(dis,0,sizeof(dis));
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(int i=0; i<gq[u].size();i++)
        {
            //cout<<"loop"<<endl;
            int v=gq[u][i];
            if(dis[v]!=0)   continue;
            else
            {
                dis[v] = dis[u]+1;
                Q.push(v);
            }
            if(dis[v]>=2)
                return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1 ;i<=n; i++)
        {
            gp[i].clear();gq[i].clear();
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%s",a);
            for(int j=1; j<=n; j++)
            {
                if(a[j-1]=='P')
                {
                    gp[i].push_back(j);
                }
                else if(a[j-1]=='Q')
                {
                    gq[i].push_back(j);
                }
            }
        }
        bool pf=true,qf=true;
        for(int i=1; i<=n; i++)
        {
            if(!pbfs(i))
            {
                pf=false;break;//¼õÖ¦£¬·ñÔòTLE
            }
            if(!qbfs(i))
            {
                qf=false;break;
            }
        }
        if(pf&&qf)
            printf("T\n");
        else
        {
            printf("N\n");
        }
    }

    return 0;
}
