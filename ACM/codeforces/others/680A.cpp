#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+5);
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<",";
    }
    return 0;
}
