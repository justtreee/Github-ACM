#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; int r=-1,b=-1,g=-1,y=-1;
    int ar=0,ab=0,ay=0,ag=0;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        //if(r*b*y*g<0)  break;
        if(s[i]=='R')   r=(i)%4;
        if(s[i]=='B')   b=(i)%4;
        if(s[i]=='Y')   y=(i)%4;
        if(s[i]=='G')   g=(i)%4;
    }
    //cout<<r<<b<<y<<g<<endl;
    int vis[4];memset(vis,0,sizeof(vis));
    int cnt[105];memset(cnt,0,sizeof(cnt));


        if(r>=0)   vis[r] = 1;
        if(b>=0)   vis[b] = 1;
        if(y>=0)   vis[y] = 1;
        if(g>=0)   vis[g] = 1;

//    for(int i=0; i<4;i++)
//    {
//        cout<<vis[i]<<":";
//    }
//    cout<<endl;
    for(int i=0; i<s.length(); i++)
    {
        if(r==-1&&s[i]=='!'&&!vis[(i)%4])
        {

            vis[(i)%4]= 1;
            r=(i)%4;
            ar=1;
            cnt[i] = 1;
        }
        if(b==-1&&s[i]=='!'&&!vis[(i)%4])
        {
            vis[(i)%4]= 1;
            b=(i)%4;
            ab=1;cnt[i] = 1;
        }
        if(y==-1&&s[i]=='!'&&!vis[(i)%4])
        {
            vis[(i)%4]= 1;
            y=(i)%4;
            ay=1;cnt[i] = 1;
        }
        if(g==-1&&s[i]=='!'&&!vis[(i)%4])
        {
            vis[(i)%4]= 1;
            g=(i)%4;
            ag=1;cnt[i] = 1;
        }

    }
//    for(int i=0; i<s.length();i++)
//    {
//        cout<<cnt[i]<<":";
//    }
//    cout<<endl;
    //cout<<r<<b<<y<<g<<endl;
    for(int i=0; i<s.length() ;i++)
    {
        if((i)%4==r&&s[i]=='!'&&!cnt[i])  ar++;
        if((i)%4==b&&s[i]=='!'&&!cnt[i])  ab++;
        if((i)%4==y&&s[i]=='!'&&!cnt[i])  ay++;
        if((i)%4==g&&s[i]=='!'&&!cnt[i])  ag++;

    }
    //cout<<r<<b<<y<<g<<endl;
    cout<<ar<<" "<<ab<<" "<<ay<<" "<<ag<<endl;
    return 0;
}

