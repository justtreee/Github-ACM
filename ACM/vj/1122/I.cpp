#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
struct isl{
    int x,y,name;
};
int dis(isl a,isl b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int m,n;
char s[41][41];
int main()
{
    while(~scanf("%d%d",&m,&n)&&n&&m)
    {
        isl H[1600],C[1600];
        int h=0,c=0;
        for(int i=0; i<m; i++)
            scanf("%s",s[i]);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j]=='H')
                {
                    H[h].x = i;
                    H[h++].y = j;
                }
                else if(s[i][j]=='C')
                {
                    C[c].x = i;
                    C[c++].y = j;
                }

            }
        }
        int tmp = INF;
        int i1=0,i2=0;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(dis(H[i],C[j])<tmp)
                {
                    tmp = dis(H[i],C[j]);
                    i1 = i;
                    i2 = j;
                }
            }
        }
        cout<<H[i1].x<<" "<<H[i1].y<<" "<<C[i2].x<<" "<<C[i2].y<<endl;

    }


return 0;
}
