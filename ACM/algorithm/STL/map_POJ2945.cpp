//#include <bits/stdc++.h>
//using namespace std;
//typedef struct Trie
//{
//    int cnt;
//    Trie *next[4];
//    Trie()
//    {
//        cnt=0;
//        memset(next,NULL,sizeof(next));
//    }
//}
//Trie rt;
//int trsf(char s)
//{
//    if(s=='A')  return 0;
//    else if(s=='C') return 1;
//    else if(s=='G') return 2;
//    else if(s=='T') return 3;
//}
//void crt(char *str)
//{
//    int len = strlen(str);
//    Trie *p=rt,*q;
//    for(int i=0; i<len; i++)
//    {
//        int id = trsf(str[i]);
//        if(p->next[id] == NULL)
//        {
//            q = (Trie *)malloc(sizeof(Trie));
//            q->cnt++;
//            for(int j=0; j<4;j++)
//            {
//                q->next[j]= NULL;
//            }
//            p->next[id] = q;
//            p=p->next[id];
//        }
//        else
//        {
//            p->next[id]->cnt++;
//            p=p->next[id];
//        }
//    }
//}
//
//
#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
map<string,int >mp;
vector<string>v;
int main()
{
    char s[200000][25];
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            map[s[i]]++;
        }
        for(int i=0; i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
    }




    return 0;
}
