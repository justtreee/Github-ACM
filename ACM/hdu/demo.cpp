#include <iostream>
using namespace std;
typedef struct M{
    int m[2][2];
}Ma;
int main()
{
    M a.m[2][2] = {{1,2},{3,4}};
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<a.m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
