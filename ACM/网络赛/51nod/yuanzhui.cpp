#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    double s;
    scanf("%lf",&s);
    double v2,v;
    v2 = s*s*s/72/PI;
    v = sqrt(v2);
    printf("%lf\n",v);
return 0;
}
