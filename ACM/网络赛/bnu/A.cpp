#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[105][100];
int cnt;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        cnt =0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);

            if(s[i][0]=='b' &&s[i][1]=='n' && s[i][2] =='u'&& s[i][3] =='1'&& s[i][4] =='6')
                    cnt++;

        }

        printf("%d\n",cnt);
    }

    return 0;
}
