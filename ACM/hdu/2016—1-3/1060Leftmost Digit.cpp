/*#include <cstdio>
#include <cmath>
using namespace std;
#define M 1000
int main()
{
    int t;
    __int64 n;
    int ans;
    double x,itg;//nlgn xiao shu bu fen
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        x = n*log10(double(n));
        x -= __int64(x);
        ans = int(pow(10.0,x));
        printf("%d\n",ans);

    }
return 0;
}
*/

#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	__int64 n, ans;
	long double x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d", &n);
		x = n * log10(n);
		x -= (__int64)x;
		ans = pow(10.0, x);
		printf("%I64d\n", ans);
	}
	return 0;
}
