#include <stdio.h>
char a[105][105];
void f(int i,int j);
int main()
{
    int n,m;
    int i,j,ans = 0;

    scanf("%d %d",&n,&m);
    getchar();
    for(i=0; i<=n+1; i++)
    {
        for(j=0;j<=m+1; j++)
        {
            a[i][j] = '.';
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1;j<=m; j++)
        {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }


    for(i=1; i<=n; i++)
    {
        for(j=1;j<=m; j++)
        {
            if(a[i][j] == 'W')
            {
               f(i,j);
               ans++;
            }


        }

    }
    printf("%d\n",ans);
return 0;
}

void f(int i,int j)
{
    if(a[i][j-1]=='W')
        {
            a[i][j-1]='.';
            f(i,j-1);
        }
    if(a[i][j+1]=='W')
        {
            a[i][j+1]='.';
            f(i,j+1);
        }
    if(a[i-1][j]=='W')
        {
            a[i-1][j]='.';
            f(i-1,j);
        }
    if(a[i+1][j]=='W')
        {
            a[i+1][j]='.';
            f(i+1,j);
        }
    if(a[i-1][j-1]=='W')
        {
            a[i-1][j-1]='.';
            f(i-1,j-1);
        }
    if(a[i-1][j+1]=='W')
        {
            a[i-1][j+1]='.';
            f(i-1,j+1);
        }
    if(a[i+1][j-1]=='W')
        {
            a[i+1][j-1]='.';
            f(i+1,j-1);
        }
    if(a[i+1][j+1]=='W')
        {
            a[i+1][j+1]='.';
            f(i+1,j+1);
        }
}


/*if(a[i-1][j-1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i][j-1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i+1][j-1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i-1][j] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }


                else if(a[i+1][j] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i-1][j+1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i][j+1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else if(a[i+1][j+1] == 'W')
                {
                    a[i][j] = '.';
                    continue;
                }
                else
                    ans++;*/
