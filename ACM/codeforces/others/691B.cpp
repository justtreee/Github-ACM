#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
int selfsy(char x)
{
    if(x=='A'||x=='H'||x=='I'||x=='i'||x=='l'||x=='M'||x=='m'||x=='O'
       ||x=='o'||x=='T'||x=='U'||x=='V'||x=='v'||x=='W'||x=='w'||x=='X'||x=='x'||x=='Y')
        return 1;
    else return 0;
}
int main()
{
    char s[1000];
    cin>>s;
    int len = strlen(s);
    //cout<<len<<endl;
    if(len % 2==1)
    {
        if(selfsy(s[len%2]))
        {

        }
    }


return 0;
}
