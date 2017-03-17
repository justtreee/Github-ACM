#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[1010],s2[1010];
int ch[1010];
int main()
{
	int t,k=1;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(ch,0,sizeof(ch));
		gets(s1);
		gets(s2);
		for(int i=0;i<strlen(s1);i++)
		{
			if(s1[i]==' ') continue;
			int op;
			if(s1[i]>='a'&&s1[i]<='z')
			{
				op=s1[i]-'a';
				ch[op]++;
			}
			else if(s1[i]>='A'&&s1[i]<='Z')
			{
				op=s1[i]-'A';
				ch[op]++;
			}
		}
		bool f=false;
		for(int i=0;i<strlen(s2);i++)
		{
			if(s2[i]==' ') continue;
			int op;
			if(s2[i]>='a'&&s2[i]<='z')
			{
				op=s2[i]-'a';
				if(ch[op]!=0)
				ch[op]--;
				else f=true;
			}
			else if(s2[i]>='A'&&s2[i]<='Z')
			{
				op=s2[i]-'A';
				if(ch[op]!=0)
					ch[op]--;
				else
					f=true;
			}
		}
		if(!f) printf("Case %d: Yes\n",k++);
		else printf("Case %d: No\n",k++);
	}
	return 0;
}
