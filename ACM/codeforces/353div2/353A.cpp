#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int t = b-a;
    if(c == 0)
    {
        if(a == b) printf("YES");
        else printf("NO");
    }
    else
    {
        //if(t%c == 0 && (t*c >= 0)) printf("YES"); //!t*c Òç³öÁË
        if(t%c == 0 && ((t>=0&&c > 0)|| (t<=0 && c < 0)))
            printf("YES");
        else printf("NO");
    }
    return 0;
}
