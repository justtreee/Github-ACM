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
    long long n;
    cin >> n;
    cout << 2 << endl;
    for(long long i = 2; i <= n; i++)
        cout << i*(i+1)*(i+1) - (i-1) << endl;
return 0;
}
