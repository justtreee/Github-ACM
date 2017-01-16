/*#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 66000
int prime[M];

void isprime()
{
    int i,j;
    for(i=2; i<33000; i++)
    {
        if(prime[i])
        {
            for(j = 2*i; j<M; j+=i)
            {
                prime[i] = 0;
            }

        }
    }
}
int main()
{
    int i,flag,n;
    /*for(i=0; i<M;i++)
    {
        prime[i] = 1;
    }
    memset(prime,1,sizeof(prime));
    isprime();
    while(~scanf("%d",&n))
    {
        if(prime[n])
        {
            printf("%d\n",n);
            //printf("===");
            continue;
        }
        i=2;
        flag = 0;
        while(n>1)
        {
            if(prime[i])
            {

                while(n%i==0)
                {
                    if(flag==0)
                    {
                        printf("%d",i);
                        flag++;

                    }
                    else
                        printf("*%d",i);
                    n/=i;
                }

            }
            i++;
        }
        printf("\n");
    }
return 0;
}
*/


#include<stdio.h>
#include<string.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int pri[66000];
int isprime()
{
    int i,j;
    for(i=2;i<33000;i++)
    {
        if(pri[i])
        for(j=2*i;j<66000;j+=i)
            pri[j]=0;
    }
}
int main()
{
    int flag,n,i;
    memset(pri,1,sizeof(pri));

    isprime();
    while(scanf("%d",&n)!=EOF)
    {
       if(pri[n])
       {
           printf("%d\n",n);
           continue;
       }
       i=2;
       flag=0;
       while(n>1)
       {
          if(pri[i])
          while(n%i==0)
          {
             if(flag==0)
             {
                 printf("%d",i);
                 flag++;
             }
             else
                printf("*%d",i);
             n/=i;
          }
          i++;
       }
       printf("\n");
    }
    return 0;
}
