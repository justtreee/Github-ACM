#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,day;
char c[5] = ".!X#";
int rule[16],dish[25][25];
int tmpdish[25][25];

int main()
{
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&day);
            for(int i=0; i<16; i++)
            {
                scanf("%d",&rule[i]);
            }
            memset(dish,0,sizeof(dish));
            for(int i=1; i<=20; i++)
            {
                for(int j=1; j<=20; j++)
                {
                    scanf("%d",&dish[i][j]);
                }
            }
            while(day--)
            {
                for(int i=1; i<=20; i++)
                {
                    for(int j=1; j<=20; j++)
                    {
                        tmpdish[i][j] = dish[i][j]   +dish[i-1][j]
                                       +dish[i+1][j] +dish[i][j+1]
                                       +dish[i][j-1];

                    }
                }

                for(int i=1; i<=20; i++)
                {
                    for(int j=1; j<=20; j++)
                    {
                        dish[i][j] += rule[tmpdish[i][j]];
                        if(dish[i][j]>3)
                            dish[i][j] = 3;
                        if(dish[i][j]<0)
                            dish[i][j] = 0;
                    }
                }



            }
            for(int i=1; i<=20; i++)
            {
                for(int j=1; j<=20 ;j++)
                {
                    putchar(c[dish[i][j]]);
                }
                putchar('\n');
            }
            if(t)
                putchar('\n');

        }

    }

    return 0;
}

