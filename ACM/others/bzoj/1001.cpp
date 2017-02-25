#include <cstdio>
#define M 1005
using namespace std;
int h[M][M],s[M][M],x[M][M];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                scanf("%d",&h[i][j]);
            }
        }
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                scanf("%d",&x[i][j]);
            }
        }


    }
    return 0;
}
