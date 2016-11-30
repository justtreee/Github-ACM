//hdu1233 zui xiao sheng cheng shu

/*#include <stdio.h>
using namespace std;
#define M 1000
int pre[M];
int find(int a)
{
    if(pre[a] != a)
        pre[a] = find(pre[a]);
    return pre[a];
}
int unionx(int a,int b)
{
    int fa = find(a),fb = find(b);


}
int main()
{

return 0;
} <<<<< NOT UnionFind >>>>>
*/


#include <iostream>
#include <stdio.h>
using namespace std;
#define M 999999
int map[100][100],dis[100];//dis 用来记录已节点i为终点的最小距离
int mark[100];
int n;
int prim()
{
    int i,j,pos,min,sum=0;
    for(i=2; i<=n; i++)
    {
        mark[i] = 0;
        dis[i] = map[i][1];
        //节点1已经在最小树内，初始化从1到i的距离
    }
    mark[1] = 1;

    for(i=2; i<=n; i++)
    {
        min = M;
        for(j=1; j<=n; j++)
        {
            if(!mark[j] && dis[j]<min)
            {
                min = dis[j];
                pos = j;
            }
        }
        sum += min;
        mark[pos] = 1;
        for(j=1; j<=n; j++)
        {
            if(!mark[j] && map[j][pos] < dis[j])
                dis[j] = map[j][pos];
        }


    }

    return sum;
}


int main()
{
    int i,a,b,d;
    while(~scanf("%d",&n),n)
    {
        for(i=1; i<=n; i++)
        {
            map[i][i] = 0;
            mark[i] = 0;
        }
        for(i=0; i<n*(n-1)/2; i++)
        {
            scanf("%d %d %d",&a,&b,&d);
            map[a][b] = map[b][a] = d;
        }
        cout<<prim()<<endl;
    }
    return 0;
}
