#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
struct Mat
{
    LL m[105][105];
};
LL N,M,T;
Mat t;
Mat operator * (Mat a,Mat b)
{
    Mat res;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            res.m[i][j] = 0;
            for(int k=0; k<N; k++)
            {
                res.m[i][j] += (a.m[i][k]*b.m[k][j])%Mod;
            }
            res.m[i][j] %= Mod;
        }
    }
    return res;
}
Mat exp(LL cnt,Mat t)
{
    Mat res;
    memset(res.m,0,sizeof(res.m));
    for(int i=0; i<N; i++)
    {
        res.m[i][i] = 1;
    }
    while(cnt)
    {
        if(cnt%2!=0)
            res = res*t;
        t=t*t;
        cnt>>=1;
    }
    return res;
}
//void test(Mat r)
//{
//    for(int i=0; i<N; i++)
//    {
//        for(int j=0; j<N; j++)
//        {
//            cout<<r.m[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//}
int main()
{
//freopen("in.txt","r",stdin);
    cin>>N>>M;
    memset(t.m,0,sizeof(t.m));
    for(int i=0; i<M; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        t.m[u][v] = 1;
        t.m[v][u] = 1;
    }
    cin>>T;
    for(int i=0; i<N-1; i++)
        t.m[N-1][i] = 0;
    t.m[N-1][N-1] = 1;
    Mat ans = exp(T,t);
    //test(ans);
//    for(int i=1; i<=T; i++)
//    {
//        Mat ans = exp(i,t);
//        test(ans);
//    }
    cout<<ans.m[0][N-1]<<endl;
    return 0;
}
