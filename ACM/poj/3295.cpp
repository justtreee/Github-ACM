#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
const int M = 150;
const int INF = (0x3f3f3f3f);
typedef long long ll;
const double PI = acos(-1.0);
char str[M];    int st[M];
int p,q,r,s,t;
void f()
{
    int k=0;
    for(int i=strlen(str)-1;i>=0; i--)
    {
        if(str[i]=='p') st[k++]=p;
        if(str[i]=='q') st[k++]=q;
        if(str[i]=='r') st[k++]=r;
        if(str[i]=='s') st[k++]=s;
        if(str[i]=='t') st[k++]=t;
        if(str[i]=='K')
        {
            int a=st[--k],b=st[--k];
            st[k++] = a&&b;
        }
        if(str[i]=='A')
        {
            int a=st[--k],b=st[--k];
            st[k++] = a||b;
        }
        if(str[i]=='N')
        {
            int a=st[--k];
            st[k++] = !a;
        }
        if(str[i]=='C')
        {
            int a=st[--k],b=st[--k];
            if(a==1&&b==0)  st[k++] = 0;
            else            st[k++] = 1;
        }
        if(str[i]=='E')
        {
            int a=st[--k],b=st[--k];
            if(a!=b)  st[k++] = 0;
            else      st[k++] = 1;
        }

    }
}
int f2()
{
    for(p=0;p<2;p++)
        for(q=0;q<2;q++)
        for(r=0;r<2;r++)
        for(s=0;s<2;s++)
        for(t=0;t<2;t++)
        {
            f();
            if(st[0]==0)
            {
                return 0;
            }
        }
    return 1;
}
int main()
{
    while(scanf("%s",str)&&str[0]!='0')
    {
        if(f2())
        cout<<"tautology"<<endl;
        else
            cout<<"not"<<endl;
    }
return 0;
}
