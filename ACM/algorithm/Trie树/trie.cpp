#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
const int M=26;
typedef struct Node{
    bool isStr;
    struct Node *next[M];
}Trie;

void insrt(Trie *rt, const char *s)
{
    if(rt==NULL||*s=='\0')
        return ;
    Trie *p = rt;
    while(*s!='\0')
    {
        if(p->next[*s-'a']==NULL)
        {
            Trie *tmp = (Trie *)malloc(sizeof(Trie));
            for(int i=0; i<M; i++)
            {
                tmp->next[i] = NULL;
            }
            tmp->isStr = false;
            p->next[*s-'a'] = tmp;
            p = p->next[*s-'a'];
        }
        else
        {
            p = p->next[*s-'a'];
        }
        s++;

    }
    p->isStr = true;
}

bool query(Trie *rt, const char *s)
{
    Trie *p =rt;
    while(p!=NULL&&*s!='\0')
    {
        p = p->next[*s-'a'];
        s++;
    }
    return (p!=NULL&&p->isStr==true);
}

void del(Trie *rt)
{
    for(int i=0; i<M;i++)
    {
        if(rt->next[i]!=NULL)
        {
            del(rt->next[i]);
        }
    }
    free(rt);
}
int main()
{
    int n,m;
    char s[1000];
    Trie *rt = (Trie *)malloc(sizeof(Trie));
    for(int i=0;i<M; i++)
    {
        rt->next[i] = NULL;
    }
    rt->isStr = false;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        insrt(rt,s);
    }
    while(cin>>m)
    {
        for(int i=0; i<m; i++)
        {
            cin>>s;
            if(query(rt,s)==1)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    del(rt);

    return 0;
}
