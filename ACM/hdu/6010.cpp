#include <bits/stdc++.h>
using namespace std;
int yy,mm,dd,hh,ms,ss;
void read()
{
    scanf("%d",&yy);getchar();
    scanf("%d",&mm);getchar();
    scanf("%d",&dd);getchar();
    getchar();
    scanf("%d",&hh);getchar();
    scanf("%d",&ms);getchar();
    scanf("%d",&ss);
}
int cal1(int y,int m,int d)
{
    int day = 0;
    day += (y-2007) * 365;
    if(y!=2007)
        day+=(y-2008)/4+1;
    if(y==2100)
        day--;
    day+=60;
    int w = day%7;
    int edge;
    if(w==0)
        edge = 8;
    else
        edge = 15-w;
    return edge;
}
int cal2(int y,int m,int d)
{
    int day = 0;
    day += (y-2007) * 365;
    if(y!=2007)
        day+=(y-2008)/4+1;
    if(y==2100)
        day--;
    day+=305;
    int w = day%7;
    int edge;
    if(w==0)
        edge = 1;
    else
        edge = 8-w;
    return edge;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T; cas++)
    {
        read();
        printf("Case #%d: ",cas);
        //cout<<yy<<" "<<mm<<" "<<dd<<" "<<hh<<" "<<ms<<" "<<ss<<" "<<endl;
        if(mm<3||mm>11)
        {
            printf("PST\n");
        }
        else if(mm>3&&mm<11)
        {
            printf("PDT\n");
        }
        else
        {
            if(mm==3)
            {
                int tmp = cal1(yy,mm,dd);
                if(dd<tmp)
                    printf("PST\n");
                else if(dd>tmp)
                    printf("PDT\n");
                else
                {
                    if(hh==2)
                        printf("Neither\n");
                    else if(hh>2)
                        printf("PDT\n");
                    else
                        printf("PST\n");
                }
            }
            else
            {
                int tmp = cal2(yy,mm,dd);
                if(dd>tmp)
                    printf("PST\n");
                else if(dd<tmp)
                    printf("PDT\n");
                else
                {
                    if(hh==1)
                        printf("Both\n");
                    else if(hh<1)
                        printf("PDT\n");
                    else
                        printf("PST\n");
                }
            }
        }
    }

    return 0;
}
