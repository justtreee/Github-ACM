#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char a[1000005],b[1000005];
int main()
{
    int len1,len2,i=0,j=0;
    scanf("%s",&a);
    scanf("%s",&b);
    len1 = strlen(a);
    len2 = strlen(b);
    while(a[i] == '0')
        i++;
    while(b[j] == '0')
        j++;
    if(len1 - i > len2 - j)
        printf(">\n");
    else if(len1 - i < len2 - j)
        printf("<\n");
    else
    {
        for( ; i<len1; i++,j++)
        {
            if(a[i]>b[j])
            {
                printf(">\n");
                break;
            }
            else if(a[i]<b[j])
            {
                printf("<\n");
                break;
            }

        }
        if(i == len1)
            printf("=\n");
    }
return 0;
}
