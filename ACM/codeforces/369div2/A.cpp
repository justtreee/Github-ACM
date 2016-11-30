#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    int r;
    string s[2000];
    scanf("%d",&r);
    int flag = 0;
    for(int i=0; i<r; i++)
    {
        cin>>s[i];
        if(!flag)
        {
            if(s[i][0]=='O'&&s[i][1]=='O'&&!flag)
            {
                s[i][0] = '+';
                s[i][1] = '+';
                flag = 1;
            }
            if(s[i][3]=='O'&&s[i][4]=='O'&&!flag)
            {
                s[i][3] = '+';
                s[i][4] = '+';
                flag = 1;
            }
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        for(int i=0; i<r; i++)
        {
            cout<<s[i]<<endl;

        }
    }
    else
        cout<<"NO";

    return 0;

}
