#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool isLeap(int y)
{
    return (y%400==0||(y%4==0&&y%100!=0));
}
char mon[12][20]={"January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November" , "December"};
LL cnt(int y,int m,int d)
{
    LL res = y/400+y/4-y/100;
    if(isLeap(y)&&(m<2||m==2&&d<29))
        res--;
    return res;
}

int main()
{
    int T;
    cin>>T;
    for(int cas = 1; cas<=T; cas++)
    {
        char mm1[20],mm2[20];
        int m1,m2,d1,d2,y1,y2;
        scanf("%s %d, %d",mm1,&d1,&y1);
        scanf("%s %d, %d",mm2,&d2,&y2);
        for(int i=0 ;i<12; i++)
        {
            if(strcmp(mm1,mon[i])==0)
                m1 = i+1;
            if(strcmp(mm2,mon[i])==0)
                m2 = i+1;
        }
        LL ans = cnt(y2,m2,d2)-cnt(y1,m1,d1);
        if((isLeap(y1))&&(m1==2)&&(d1==29))
            ans++;
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}
