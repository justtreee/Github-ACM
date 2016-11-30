//#include <cstdio>
//#include <cmath>
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdlib>
//#include <map>
//using namespace std;
//#define M 100005
//#define INF (0x3f3f3f3f)
//typedef long long ll;
//int s[M];
//int n,k;
//
//int f(char x)
//{
//    int l=0,r=0,ans=0,cnt=0;
//    while(l<n&&r<n)
//    {
//        while(s[r]==x || cnt<k && r<n)
//        {
//            if(s[r]!=x)
//                cnt++;
//            r++;
//        }
//        ans = max(ans,r-l);
//        printf("==%d\n",ans);
//        while(s[l]==x && l<=r)
//            l++;
//        l++;
//        cnt--;
//    }
//    return ans;
//}
//
//int main()
//{
//    scanf("%d%d",&n,&k);
//    scanf("%s",s);
//    printf("%d\n",max(f('a'),f('b')));
//return 0;
//}

#include <cstdio>
#include <algorithm>
using namespace std;
int const MAX = 1e5 + 5;
char s[MAX];
int n, k;

int f(char x)
{
    int l = 0, r = 0, ans = 0, cnt = 0;
    while(l < n && r < n)
    {
        while((s[r] == x || cnt < k) && r < n)
        {
            if(s[r] != x)
            {
                cnt++;
            }
            r++;
        }
        ans = max(ans, r - l);
        //printf("==%d\n",ans);
        while(s[l] == x && l <= r)
        {
            l++;
        }
        l++;
        cnt--;
    }
    return ans;
}

int main()
{
    scanf("%d %d", &n,&k);
    scanf("%s",s);
    printf("%d\n", max(f('a'), f('b')));
}
