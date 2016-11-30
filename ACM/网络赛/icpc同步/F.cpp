#include <iostream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    char t;
    int cnt;
}M[5];
bool cmp(node a,node b)
{
    if(a.cnt==b.cnt)
        return a.t<b.t;
    return a.cnt>b.cnt;
}
int main()
{
    int n,m,c,d,e,g,a;
    char s[21][21];
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        c=d=e=g=a=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",&s[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //cout<<s[i][j];
                if(s[i][j]=='C')
                    c++;
                if(s[i][j]=='D')
                    d++;
                if(s[i][j]=='E')
                    e++;
                if(s[i][j]=='G')
                    g++;
                if(s[i][j]=='A')
                    a++;
            }
        }
        M[0].t = 'C';   M[0].cnt=c;
        M[1].t = 'D';   M[1].cnt=d;
        M[2].t = 'E';   M[2].cnt=e;
        M[3].t = 'G';   M[3].cnt=g;
        M[4].t = 'A';   M[4].cnt=a;
        sort(M,M+5,cmp);
        for(int i=0; i<5; i++)
        {
            if(i==0)
            cout<<M[i].t<<" "<<M[i].cnt;
            if(i>0&&i!=4)
                cout<<" "<<M[i].t<<" "<<M[i].cnt;
            if(i==4)
                cout<<" "<<M[i].t<<" "<<M[i].cnt<<endl;
        }
        //printf("C %d D %d E %d G %d A %d",c,d,e,g,a);
    }

    return 0;
}
