#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
#define M 100005
char s[M];
char o[M];
int main()
{
    int t,k;
    scanf("%d",&t);
    getchar();
    for(int cas=1; cas<=t; cas++)
    {
        memset(o,'\0',sizeof(o));
        gets(s);
        //cout<<s<<endl;
        scanf("%d",&k);
        getchar();
        int len = strlen(s);
        //printf("len = %d\n",len);
        int row = len/k+1;
        int left = len % k;

        int p=0;
        for(int i=0; i<left; i++)
        {
            for(int j=0; j<row; j++)
            {
                o[i+k*j] = s[p++];
            }
        }

        for(int i=left; i<k; i++)
        {
            for(int j=0; j<row-1; j++)
            {
                o[i+k*j] = s[p++];
            }
        }

        printf("Case #%d:\n",cas);
        puts(o);
        //printf("\n");

    }
return 0;
}
