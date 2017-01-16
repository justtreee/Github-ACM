#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int brd[2],p1[2],p2[2];
int main()
{
    while(~scanf("%d%d",&brd[0],&brd[1]))
    {
        scanf("%d%d",&p1[0],&p1[1]);
        scanf("%d%d",&p2[0],&p2[1]);
        int flag = 0;
        int a1,a2,b1,b2;
        a1 = p1[0] + p2[0];
        a2 = p1[0] + p2[1];
        b1 = p1[1] + p2[0];
        b2 = p1[1] + p2[1];
        if(a1<=brd[0] && max(p1[1],p2[1])<=brd[1])
            flag = 1;
        if(a1<=brd[1] && max(p1[1],p2[1])<=brd[0])
            flag = 1;

        if(a2<=brd[1] && max(p1[1],p2[0])<=brd[0])
            flag = 1;

        if(a2<=brd[0] && max(p1[1],p2[0])<=brd[1])
            flag = 1;
        if(b1<=brd[0] && max(p1[0],p2[1])<=brd[1])
            flag = 1;
        if(b1<=brd[1] && max(p1[0],p2[1])<=brd[0])
            flag = 1;
        if(b2<=brd[0] && max(p1[1],p2[0])<=brd[1])
            flag = 1;
        if(b2<=brd[1] && max(p1[1],p2[0])<=brd[0])
            flag = 1;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }
return 0;
}
