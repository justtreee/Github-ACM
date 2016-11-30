#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dir[4][2]= {1,0,-1,0,0,1,0,-1},vist[25][25][5000];
char mapp[25][25];
int n,m,t,flag=0,ans=0;
int sx,sy,ex,ey;
struct node
{
    int x,y;
    int time;
    int k;
};
void bfs()
{
    queue<node>q;
    node p;
    p.x=sx;
    p.y=sy;
    p.time=0;
    p.k=0;
    q.push(p);
    while(!q.empty())
    {
        node p1;
        p1=q.front();
        q.pop();
        if(p1.time>=t)//judge
            return;
        if(p1.x==ex&&p1.y==ey)//find the exit
        {
            flag=1;
            ans=p1.time;
            break;
        }

        for(int i=0; i<4; i++)//4 direction
        {
            node p2;
            p2.x=p1.x+dir[i][0];
            p2.y=p1.y+dir[i][1];
            p2.time=p1.time+1;
            p2.k=p1.k;
            if(p2.x>=0&&p2.x<n&&p2.y>=0&&p2.y<m&&mapp[p2.x][p2.y]!='*')
            {

                if('a'<=mapp[p2.x][p2.y]&&mapp[p2.x][p2.y]<='z')
                {
                    p2.k=p2.k|(1<<(mapp[p2.x][p2.y]-'a'));//!!!black_sci_tch!!!
                    if(!vist[p2.x][p2.y][p2.k])           //you have a key chain
                    {                                     //as 00000,00000
                        vist[p2.x][p2.y][p2.k]=1;         //A's key a named as
                        q.push(p2);                       //00000,00001
                    }                                     //while you have a new key
                }                                         //use "|" to add it
                                                          //eg. 00010,00001 means you have AG's key
                else if('A'<=mapp[p2.x][p2.y]&&mapp[p2.x][p2.y]<='Z')
                {
                    int k=p2.k&(1<<(mapp[p2.x][p2.y]-'A'));//"&"
                    if(!vist[p2.x][p2.y][p2.k]&&k)         //whether u have this key
                    {
                        vist[p2.x][p2.y][p2.k]=1;
                        q.push(p2);
                    }
                }
                else  if(vist[p2.x][p2.y][p2.k]==0)
                {
                    vist[p2.x][p2.y][p2.k]=1;
                    q.push(p2);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)>0)
    {
        for(int i=0; i<n; i++)
            scanf("%s",mapp[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(mapp[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if(mapp[i][j]=='^')
                {
                    ex=i;
                    ey=j;
                }
            }
        flag=0;
        ans=0;
        memset(vist,0,sizeof(vist));
        bfs();
        if(flag==0)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

