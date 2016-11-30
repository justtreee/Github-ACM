#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
struct node{
    int p;
    int used;
}s[M][M];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<M;i++)
        {
            for(int j=0; j<M; j++)
            {
                s[i][j].used = 0;

            }
        }


        for(int i=0; i<n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&s[i][j].p);
                s[i][j].used = 1;
            }

        }



    }


return 0;
}
