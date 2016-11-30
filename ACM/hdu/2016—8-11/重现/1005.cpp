#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[50][50];
int n,m;
int ju(int x,int y)
{
    if(x<n&&x>=0&&y<m&&y>=0)
        return 1;
    else
        return 0;
}
int main()
{
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {

        cin>>n>>m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>>a[i][j];
            }
        }
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {

                if (ju(i, j+1) && a[i][j] == a[i][j+1]) flag = 1;

                if (ju(i+1, j) && a[i][j] == a[i+1][j]) flag = 1;

            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = i+1; j < m; ++j)
            {
                if (a[0][i] == a[0][j] || a[n-1][i] == a[n-1][j]) flag = 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if (a[i][0] == a[j][0] || a[i][m-1] == a[j][m-1]) flag = 1;
            }
        }
        cout << "Case #" << cas << ": ";
        if (flag) printf("Yes\n");
        else printf("No\n");
    }


    return 0;
}

