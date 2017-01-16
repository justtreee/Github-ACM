#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
char f[M];
int main()
{
    gets(f);
    int len = strlen(f);
    int day = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if(f[i]>='0'&&f[i]<='9')
        {
            day = day * 10 +f[i] - '0';
        }

    }
    int flag = 0;
    int l = len - 1;
    if(f[l]=='k')
        flag = 0;
    else
        flag = 1;


    if(!flag)
    {
        if(day==5||day==6)
            printf("53\n");
        else
            printf("52\n");

    }
    else
    {
        if(day<=29)
            printf("12\n");
        else if(day>=31)
            printf("7\n");
        else
            printf("11\n");
    }
return 0;
}
