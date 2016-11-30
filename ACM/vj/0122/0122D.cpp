#include <stdio.h>

#include <string.h>
using namespace std;
char str[205];
int main()
{
    int m1,m2,r1,r2,r3;
    int i,l;
    while(~scanf("%d %d",&m1,&m2))
    {
        r1=r2=r3=0;
        scanf("%s",&str);
        l = strlen(str);
        for(i=0; i<l; i++)
        {
            if(str[i] == 'A')
                r1 = m1;
            else if(str[i] == 'B')
                r2 = m2;
            else if(str[i] == 'C')
                m1 = r3;
            else if(str[i] == 'D')
                m2 = r3;
            else if(str[i] == 'E')
                r3 = r1 + r2;
            else if(str[i] == 'F')
                r3 = r1 - r2;

        }
        printf("%d,%d\n",m1,m2);
    }

return 0;
}
