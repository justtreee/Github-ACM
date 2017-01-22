#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 105;
const ll INF = 1e18;
ll cnt[maxn*2][maxn];
int main()
{
    ll n, m, k, x, y, axy,amin = INF, amax = -INF, c;
    cin >> n >> m >> k >> x >> y;
    if(n == 1)
    {
        amin = k / m;
        if(k%m) amax = k / m + 1;
        else amax = amin;
        if(k%m < y) axy = amin;
        else axy = amax;
    }
    else
    {
        c = k / ((2*n-2)*m);
        k %= ((2*n-2)*m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cnt[i][j] += c;
        for(int i = n - 1; i >= 2; i--)
            for(int j = 1; j <= m; j++)
                cnt[i][j] += c;
        for(int i = 1; i <= n && k; i++)
            for(int j = 1; j <= m && k; j++)
                cnt[i][j]++, k--;
        for(int i = n - 1; i >= 2 && k; i--)
            for(int j = 1; j <= m && k; j++)
                cnt[i][j]++, k--;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                amin = min(amin, cnt[i][j]), amax = max(amax, cnt[i][j]);
        axy = cnt[x][y];
    }
    cout << amax << ' ' << amin << ' ' << axy << endl;
    return 0;
}
