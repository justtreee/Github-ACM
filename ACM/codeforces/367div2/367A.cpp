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
//struct {
//    int x,y,v
//}car[1005];

int main()
{
    int x,y,n;
    double time=INF,tmp;
    int tx,ty,v;
    scanf("%d%d%d",&x,&y,&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d",&tx,&ty,&v);
        tmp = sqrt((x-tx)*(x-tx)+(y-ty)*(y-ty))/v;
        time = min(time,tmp);

    }
    printf("%lf\n",time);



return 0;
}
