#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char s[50005];
    int num[26];
    memset(num,0,sizeof(num));
    scanf("%s",s);
    int ju =1;
    for(int i=0; i<strlen(s); i++)
    {
        memset(num,0,sizeof(num));
        for(int j=0; j<26; j++)
        {

            if(s[i+j]!='?')
                num[s[i+j]-'A']++;
        }
        int tmp =0;
        int tmp1=0;
        for(int j=0; j<26; j++)
        {
            if(num[j]==0)tmp++;
            if(s[i+j]=='?')tmp1++;
        }
        if(tmp==tmp1)
        {
            int x=0;
            for(int j=0; j<26; j++)
            {
//                if(s[i+j]!='?')
//                    printf("%c",s[i+j]);
//                else
//                {
//                    while(num[x]!=0)x++;
//                    printf("%c",x+'A');
//                    x++;
//                }
                if(s[i+j]=='?')
                {
                    while(num[x]!=0)
                        x++;
                    s[i+j]=x+'A';
                    x++;
                }
            }
//            int p=0;
//            for(int j=0;i+j<strlen(s) ;j++)
//            {
//
//                    printf("%c",s[i+j]);
//
//
//            }

            ju = 0;
            //cout<<"1"<<endl;
            break;
        }

    }
    if(ju==1)
        cout<<"-1";
    else
    {
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i]=='?')
                s[i] = 'A';

        }
        puts(s);
    }
    return 0;
}
