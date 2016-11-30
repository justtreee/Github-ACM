#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,k,n,m,t,flag;
	int c[110] = {0};

	while(~scanf("%d %d",&n,&m))
	{

		for(i=0;i<n;i++)
        {
			scanf("%d",&k);
			for(j=0;j<k;++j)
			{
				scanf("%d",&t);
				c[t]++;
			}
		}
		flag = 0;
		for(i=1;i<=m;i++)
		{
			if(c[i]==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
return 0;
}
