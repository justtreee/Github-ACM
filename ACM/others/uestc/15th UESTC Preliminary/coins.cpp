#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL A,B;
const int INF = 0x3f3f3f3f;
LL f(LL A,LL B)
{
    LL a = A,b = B;
    LL a10,a5,a2,a1,b10,b5,b2,b1;
    a10=a5=a2=a1=b10=b5=b2=b1=0;
    if(A<0||B<0)    return INF;
    a10 += A/10;
    A%=10;
    a5 += A/5;
    A%=5;
    a2 += A/2;
    A%=2;
    a1 += A;
    b10 += B/10;
    B%=10;
    b5 += B/5;
    B%=5;
    b2 += B/2;
    B%=2;
    b1 += B;
    LL ans1,ans2;
    ans1 = max(a10,b10)+max(a5,b5)+max(a2,b2)+max(a1,b1);
    ans2 = a10+a5+a2+a1;
    b-=a;
    ans2+=b/10;
    b%=10;
    ans2+=b/5;
    b%=5;
    ans2+=b/2;
    b%=2;
    ans2+=b;

    return min(ans1,ans2);
}
int main()
{
    cin>>A>>B;
    if(A>B)
        swap(A,B);
    cout<<min(f(A,B),f(A-6,B-14)+4)<<endl;
    return 0;
}
