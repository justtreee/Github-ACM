#include<cstdio>
#include<cmath>
using namespace std;
double a[10005];
int k,n;
bool f(double x)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
		sum=sum+(int)(a[i]/x);
	if(sum<k)
		return false;
	else
		return true;
}

int main()
{
	int i;
	double l,r,mid,max;
	while(~scanf("%d%d",&n,&k))
	{
		if(n==0&&k==0)
			break;
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		l=0,r=max;
		for(i=1;i<=50;i++)
		{
			mid=(l+r)/2;
			if(f(mid))
				l=mid;
			else
				r=mid;
		}
		printf("%.2lf\n",l);
	}
	return 0;
}
