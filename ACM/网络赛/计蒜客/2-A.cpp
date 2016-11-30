//AC

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
#define PI acos(-1.0)
#define D PI/180

typedef long long ll;
int main()
{
    double l1,l2,L3,r,dgre;
    scanf("%lf%lf%lf",&l1,&l2,&dgre);
    L3 = (l1/2)*(l1/2)+(l2/2)*(l2/2)-l1*l2/2.0*cos(dgre*D);
    L3 = sqrt(L3);
    r = (2*L3+l1+l2)/4.0;
    printf("%lf\n",PI*r*r);

    return 0;
}
