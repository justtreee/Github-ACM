//KMP
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000005

int next[M];
char s[M];

void kmp_next()
{
    int i=0,j=-1;
    next[0] = -1;
    int len = strlen(s);
    while(i<len)
    {
        if(s[i] == s[j]|| j==-1)
        {
            i++;
            j++;
            next[i]= j;
        }
        else
            j = next[j];
    }
}
int main()
{
    while(~scanf("%s",s) && s[0]!='.')
    {
        int len = strlen(s);
        kmp_next();
        if(len%(len - next[len]) == 0)
            printf("%d\n",len/(len - next[len]));
        else
            printf("1\n");
    }
return 0;
}
