#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string s;
    scanf("%d%d",&n,&m);
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>s;

            if(s=="C"||s=="M"||s=="Y")
            {
                flag = 1;

            }


        }
    }
    if(flag)
        cout<<"#Color"<<endl;
    else
        cout<<"#Black&White"<<endl;

    return 0;
}
