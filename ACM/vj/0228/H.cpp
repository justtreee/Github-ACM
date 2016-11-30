#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int x[3],y[3];
int main()
{
    int ax,ay;
    while(~scanf("%d%d",&x[0],&y[0]))
    {

        for(int i=1; i<3; i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        int mark = 0;
        for(int i=0; i<3; i++)
        {
            ax = ay =0;
            for(int j=0; j<3; j++)
            {
                if(x[i]==x[j])
                    ax++;
                if(y[i]==y[j])
                    ay++;

            }
            mark = max(mark,ax);
            mark = max(mark,ay);
        }
        if(mark==3)
            printf("1\n");
        else if(mark == 2)
        {
            bool flag = 0;
            for(int i=0; i<3; i++)
            {
                for(int j=0;j<3; j++)
                {
                    if(i!=j)
                    {
                        int k = 3-i-j;
                        if(x[i]==x[j])
                        {
                            if(y[k]<=min(y[i],y[j]) || y[k]>=max(y[i],y[j]))
                                flag = 1;
                        }
                        if(y[i]==y[j])
                        {
                            if(x[k]<=min(x[i],x[j]) || x[k]>=max(x[i],x[j]))
                                flag = 1;
                        }
                    }
                }
            }
            if(flag)
                printf("2\n");
            else
                printf("3\n");
        }
        else
            printf("3\n");

    }
return 0;
}
