#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    double a[1005];
    double m,n,sum;
    while(~scanf("%lf %lf",&n,&m))
    {
        sum = 0;
        a[0] = n;
        for(i=1;i<m;i++)
        {
            a[i] = sqrt(a[i-1]);
        }
        for(i=0; i<m; i++)
        {
            sum += a[i];
        }
        printf("%.2lf\n",sum);
    }
return 0;
}
