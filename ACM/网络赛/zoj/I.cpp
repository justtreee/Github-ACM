#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 105
char c[M][M];
int main()
{
    int h,w,t;
    scanf("%d",&t);
    while(t--)
    {
        int num =0;
//        int cnt =0;
//        int head = 0;
//        int ll , rl , lh , rh;
//        ll = rl = lh = rh = 0;
//        int body = 0;
        scanf("%d%d",&h,&w);
        for(int i=0; i<h; i++)
        {
            scanf("%s",&c[i]);
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(c[i][j] == 'O')
                {
                    c[i][j] = '.';
                    if(i+1<h)
                    {
                        //printf("== | ==%d\n",i+1);
                        if(c[i+1][j]=='|')
                        {
                            c[i+1][j]='.';
                            //printf("===%c\n",c[i+1][j]);
                        }
                    }
                    if(i+1<h)
                    {
                        if(c[i+1][j-1]=='/'&& j-1>=0)
                            c[i+1][j-1] = '.';
                        if(c[i+1][j+1]=='\\'  && j+1<w)
                            c[i+1][j+1]='.';
                    }
                    if(i+2<h)
                    {
                        if(c[i+2][j-1]=='('&& j-1>=0)
                            c[i+2][j-1] = '.';
                        if(c[i+2][j+1]==')' && j+1<w)
                        {
                            c[i+2][j+1]='.';
                            //printf("===%c\n",c[i+2][j+1]);
                        }
                    }
                    num++;

//                    for(int k=0; k<h; k++)
//                    {
//                        printf("%s\n",c[k]);
//                    }
//                    printf("===%d\n",num);


                }
                if(c[i][j] == '|')
                {
                    c[i][j] = '.';
                    if(i-1>=0)
                    {
                        if(c[i-1][j]=='O')
                            c[i-1][j]='.';
                    }
                    if(i<h )
                    {
                        if(c[i][j-1]=='/'&& j-1>=0 )
                            c[i][j-1] = '.';
                        if(c[i][j+1]=='\\'&& j+1<w)
                            c[i][j+1]='.';
                    }
                    if(i+1<h )
                    {
                        if(c[i+1][j-1]=='('&& j-1>=0)
                            c[i+1][j-1] = '.';
                        if(c[i+1][j+1]==')'&& j+1<w)
                            c[i+1][j+1]='.';
                    }
                    num++;
                }
                if(c[i][j] == '/')
                {
                    c[i][j] = '.';
                    if(i-1>=0 && j+1<w)
                    {
                        if(c[i-1][j+1]=='O')
                            c[i-1][j+1]='.';
                    }
                    if(i<h )
                    {
                        if(c[i][j+1]=='|'&&  j+1<w)
                            c[i][j+1] = '.';
                        if(c[i][j+2]=='\\'&&  j+2<w)
                            c[i][j+2]='.';
                    }
                    if(i+1<h)
                    {
                        if(c[i+1][j]=='(')
                            c[i+1][j] = '.';
                        if(c[i+1][j+2]==')' && j+2<w)
                            c[i+1][j+2]='.';
                    }
                    num++;
                }
                if(c[i][j] == '\\')
                {
                    c[i][j] = '.';
                    if(i-1>=0 && j-1>=0)
                    {
                        if(c[i-1][j-1]=='O')
                            c[i-1][j-1]='.';

                    }
                    if(i<h)
                    {
                        if(c[i][j-1]=='|'&&j-1>=0)
                            c[i][j-1] = '.';
                        if(c[i][j-2]=='/'&&j-2>=0)
                            c[i][j-2] = '.';
                    }
                    if(i+1<h )
                    {
                        if(c[i+1][j]==')')
                            c[i+1][j]='.';
                        if(c[i+1][j-2]=='('&& j-2>=0)
                            c[i+1][j-2]='.';
                    }
                    num++;
                }
                if(c[i][j] == ')')
                {
                    c[i][j] = '.';
                    if(i-2>=0 && j-1>=0)
                    {
                        if(c[i-2][j-1]=='O')
                            c[i-2][j-1]='.';

                    }
                    if(j-2>=0)
                    {
                        if(c[i][j-2]=='(')
                            c[i][j-2] = '.';

                    }
                    if(i-1<h )
                    {
                        if(c[i-1][j-2]=='/'&& j-2>=0)
                            c[i-1][j-2]='.';
                        if(c[i-1][j-1]=='|'&& j-1>=0)
                            c[i-1][j-1]='.';
                        if(c[i-1][j]=='\\')
                            c[i-1][j]='.';
                    }
                    num++;
                }
                if(c[i][j] == '(')
                {
                    c[i][j] = '.';
                    if(i-2>=0 && j+1<w)
                    {
                        if(c[i-2][j+1]=='O')
                            c[i-2][j+1]='.';

                    }
                    if(j+2<w)
                    {
                        if(c[i][j+2]==')')
                            c[i][j+2] = '.';

                    }
                    if(i-1<h )
                    {
                        if(c[i-1][j+1]=='|'&& j+1<w)
                            c[i-1][j+1]='.';
                        if(c[i-1][j+2]=='\\'&& j+2<w)
                            c[i-1][j+2]='.';
                        if(c[i-1][j]=='/')
                            c[i-1][j]='.';
                    }
                    num++;
                }



            }
        }

        printf("%d\n",num);
    }

return 0;
}

