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
int main()
{
    int n,m,a[2005];
    int cnt[2005];
    int alc = 0;
    memset(cnt,0,sizeof(cnt));
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i]<=m)
        {
            cnt[a[i]]++;
            alc++;
        }
    }

    int tmp = n-alc;
    int goal = n/m;
    sort(cnt+1,cnt+1+m);
    while(tmp)
    {
        //sort(cnt+1;cnt+1+m);
        for(int i=1; i<=m-1; i++)
        {
            if(cnt[i]<cnt[i+1])
            {
                if(tmp -=(cnt[i+1]-cnt[i])*i>=0)
                {
                    tmp -=(cnt[i+1]-cnt[i])*i;
                    for(int k=i; k>=1; k--)
                    {
                        cnt[k] = cnt[i+1];
                    }
                }
                else
                {
                    cnt[i]+=tmp;
                    tmp = 0;

                }
                //cnt[i] = cnt[i+1];


            }

        }
    }
    sort(cnt+1,cnt+1+m);
    cout<<cnt[1]<<endl;
    return 0;
}
