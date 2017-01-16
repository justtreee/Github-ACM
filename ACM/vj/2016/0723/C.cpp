//#include <cstdio>
//#include <cmath>
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdlib>
//#include <map>
//using namespace std;
//#define M 200
//#define INF (0x3f3f3f3f)
//typedef long long ll;
//const double PI = acos(-1.0);
//
//char word[5000][200];
//int main()
//{
//    char ch,t[M];
//    int pos=0,flag =0;
//    int n=0;
//    while(~(ch=getchar()))
//    {
//        if(isalpha(ch))
//        {
//            flag = 1;
//            t[pos++] = tolower(ch);
//        }
//        else
//        {
//            if(flag)
//            {
//                t[pos] = '\0';
//                pos = 0;
//                flag = 0;
//                int i=0,mark;
//                while(i<n && (mark = strcmp(t,word[i])>0))
//                    i++;
//                if(i==n)
//                {
//                    strcpy(word[i],t);
//                    n++;
//                }
//                else if(!mark)
//                    continue;
//                else
//                {
//                    int j;
//                    for(j=n; j>i; j--)
//                    {
//                        strcpy(word[j],word[j-1]);
//                    }
//                    strcpy(word[j],t);
//                    n++;
//                }
//            }
//
//        }
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        printf("%s\n",word[i]);
//    }
//return 0;
//}
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> dict;

int main()
{
	string s,buf;
	while(cin>>s)
	{
		for(int i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))
			    s[i]=tolower(s[i]);
			else
			    s[i]=' '; //������ķ��ַ�ת��Ϊ�ո���Ϊ���ʵķֽ�㡣
		}
		stringstream ss(s);//������s������ ss��
		while(ss>>buf)
		dict.insert(buf);//�����ﵼ����׼��string��,���뼯�Ϻ��Զ�ȡ���ظ����ʣ����������С�
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
	    cout<<*it<<"\n";
    return 0;
}
