#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int main()
{
    int a,b,c,d;
    __int64 n;//if n is int -> WA on test 6.
    while(~scanf("%I64d%d%d%d%d",&n,&a,&b,&c,&d))
    {
        //__int64 sum = 1;
        int m;
        __int64 maxx = -1;
        int x1=-1,x2=-1,x3=-1,x4=-1;
        if(a+b>=max(max(a+c,c+d),b+d))
        {
            x1 = 1;
            m = a+b+1;
            x2 = m-a-c;
            x3 = m-b-d;
            x4 = m-c-d;
        }
        if(a+c>=max(max(a+b,c+d),b+d))
        {
            x2 = 1;
            m = a+c+1;
            x1 = m-a-b;
            x3 = m-b-d;
            x4 = m-c-d;
        }
        if(b+d>=max(max(a+b,c+d),a+c))
        {
            x3 = 1;
            m = b+d+1;
            x1 = m-a-b;
            x2 = m-a-c;
            x4 = m-c-d;
        }
        if(c+d>=max(max(a+b,a+c),d+b))
        {
            x4 = 1;
            m = c+d+1;
            x1 = m-a-b;
            x2 = m-a-c;
            x3 = m-b-d;
        }
        //printf("%d %d %d %d\n",x1,x2,x3,x4);
        int t1 = x1+a+b;
        if(t1==x2+a+c && t1==x3+b+d && t1==x4+c+d)
        {
            maxx = max(max(x1,x2),max(x3,x4));
            if(maxx<=n)
            {
//                long long ans = n*(n-maxx+1);
//                //printf("%I64d\n",ans);
//                cout<<ans<<endl;

                printf("%I64d\n",(n-maxx+1)*n);
            }
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }
return 0;
}

//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <algorithm>
//#define _LL __int64
//using namespace std;
//int main()
//{
//    int n,a,c,b,d;
//    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
//    _LL sum=1;
//    int maxi=-11,m;
//
//    int x1=-1,x2=-1,x3=-1,x4=-1;
//
//    if(a+b>=max(max(a+c,c+d),d+b))
//    {
//        x1=1;
//        m=a+b+1;
//        x2=m-a-c;
//        x3=m-b-d;
//        x4=m-c-d;
//    }
//    if(a+c>=max(max(a+b,c+d),d+b))
//    {
//        x2=1;
//        m=a+c+1;
//        x1=m-a-b;
//        x3=m-b-d;
//        x4=m-c-d;
//    }
//    if(d+b>=max(max(a+c,c+d),a+b))
//    {
//        x3=1;
//        m=d+b+1;
//        x1=m-a-b;
//        x2=m-a-c;
//        x4=m-c-d;
//    }
//    if(c+d>=max(max(a+c,a+b),d+b))
//    {
//        x4=1;
//        m=c+d+1;
//        x1=m-a-b;
//        x2=m-a-c;
//        x3=m-b-d;
//    }
//  //  printf("%d %d %d %d\n",x1,x2,x3,x4);
//    if(a+b+x1==a+c+x2&&a+b+x1==b+d+x3&&a+b+x1==d+c+x4)
//    {
//        maxi=max(max(x1,x2),max(x3,x4));
//        if(maxi<=n)
//            printf("%I64d\n",sum*(n-maxi+1)*n);
//        else
//            printf("0\n");
//    }
//    else
//        printf("0\n");
//
//    return 0;
//}
