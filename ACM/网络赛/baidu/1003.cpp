#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int main()
{
    int t,n,m,A[M],B[M],C[M],D[M],a[M],b[M],c[M],d[M];
    int aa[M],ab[M],ac[M],ad[M];
    int ans[50];
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d.%d.%d.%d",&A[i],&B[i],&C[i],&D[i]);
            //printf("===%d.%d.%d.%d===",A[i],B[i],C[i],D[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d.%d.%d.%d",&a[i],&b[i],&c[i],&d[i]);
        }
        int k=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                A[j] = a[i] & A[j];
                B[j] = b[i] & B[j];
                C[j] = c[i] & C[j];
                D[j] = d[i] & D[j];
                printf("=%d==%d.%d.%d.%d===\n",i,A[j],B[j],C[j],D[j]);
            }
            ans[i] = m;
            for(int p=0;p<n-1; p++)
            {
                if(A[p] == -1)
                    continue;
                for(int q=p+1; q<n; q++)
                {
                    if(A[p]==A[q] &&B[p]==B[q] &&C[p]==C[q] &&D[p]==D[q])
                    {
                        A[q] = -1;
                        B[q] = -1;
                        C[q] = -1;
                        D[q] = -1;
                        ans[i]--;
                    }
                }

            }
        }

        printf("Case #%d:\n",cas++);
        for(int i=0; i<m; i++)
        {
            printf("%d\n",ans[i]);
        }
    }

return 0;
}
