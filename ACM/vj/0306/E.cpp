#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int a,b,c;
int main()
{
    cin>>a>>b>>c;

    bool flag=false;
    for(int i=0;a*i<=c;i++)
    {
        if((c-a*i)%b==0)
        {
            flag= true;

            break;
        }
    }

    if(flag)
    {
        cout<<"Yes"<<endl;
    }
    else

    {
        cout<<"No"<<endl;
    }
    return 0;
}
