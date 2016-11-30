#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 1005
int main()
{
    char cl[M][20];
    int m[M];
    int n,i,j;
    while(~scanf("%d",&n) && n)
    {
        memset(cl,0,sizeof(char)*M*20);
        memset(m,0,sizeof(int)*M);
        for(i=0; i<n; i++)
        {
            scanf("%s",&cl[i]);
        }
        for(i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(!strcmp(cl[i],cl[j]))
                    count++;
            }
            m[i] = count;
        }
        int max = 0;
        int plc = 0;
        for(i=0; i<n; i++)
        {
            if(m[i]>max)
            {
                max = m[i];
                plc = i;
            }
        }
        cout<<cl[plc]<<endl;
    }
return 0;
}
