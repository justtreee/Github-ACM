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
const double PI = acos(-1.0);
string s;
bool ju(int i)
{
    return s[i]=='('||s[i]==')';
}
int main()
{
    int n;

    cin>>n>>s;
    int in=0,out=0,len=0,inunder=0,outunder=0;
    int flag = 0;
    int tmp = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            flag = 1;
        }
        if(s[i]==')')
        {
            flag = 0;
        }
        if(!flag&&(s[i]=='_'))
        {
            len = max(len,tmp);
            tmp = 0;
        }
        if(s[i]=='_'&&s[i+1]!='_'&&i<n-1&&flag)
        {
            tmp = 0;
            inunder++;
        }
        if(s[i]=='_'&&s[i+1]!='_'&&i<n-1&&!flag)
        {tmp = 0;
            outunder++;
        }
        if(!ju(i)&&s[i]!='_'&&(s[i+1]=='_'||s[i+1]=='('||s[i+1]==')')&&flag&&i<n-1)
        {
            in++;
        }
        if(!ju(i)&&s[i]!='_'&&(s[i+1]=='_'||s[i+1]=='('||s[i+1]==')')&&!flag&&i<n-1)
        {
            out++;
        }

        if(!ju(i)&&!flag&&s[i]!='_')
        {

            tmp++;//cout<<tmp<<" i:"<<i<<endl;
        }

            len = max(len,tmp);



    }
    cout<<len<<" "<<in<<endl;
return 0;
}
