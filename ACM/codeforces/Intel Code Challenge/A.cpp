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
int main()
{
    int n;
    string c;
    cin>>n>>c;
    int hh,mm;
    hh = (c[0]-'0')*10+(c[1]-'0');
    mm = (c[3]-'0')*10+(c[4]-'0');
    //cout<<hh<<mm<<endl;
    if(n==24)
    {
        if(hh>23)
        {
            c[0] = '1';
        }
//        if(hh==0&&mm>59)
//        {
//            c[1] = '1';
//        }
        if(mm>59)
        {
            c[3] = '0';
        }

    }
    else
    {
        if(hh>12)
        {
            if(c[1]=='0')
                c[0] = '1';
            else
                c[0] = '0';
        }
        if(hh==0)
        {
            c[1] = '1';
        }
        if(mm>59)
        {
            c[3] = '0';
        }
    }

    cout<<c<<endl;
return 0;
}
