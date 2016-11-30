#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100000
struct node{
    int b;
    int e;
    int dis;
}s[M];
int main()
{
    int n,m,c,d,k;
    scanf("%d %d%d%d%d",&n,&m,&c,&d,&k);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&s[i].b,&s[i].e,&s[i].dis);
    }


return 0;
}
