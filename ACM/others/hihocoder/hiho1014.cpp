#include <bits/stdc++.h>
using namespace std;
const int M = 26;
typedef struct Trie
{
    int cnt;
    struct Trie *next[M];
};
Trie mem[1000000];//预先开内存，比malloc快
int alloc = 0;
Trie * creat()
{
    Trie * tmp = &mem[alloc++];
    tmp->cnt = 1;
    for(int i=0; i<M; i++)
    {
        tmp->next[i] = NULL;
    }
    return tmp;
}
void Insrt(Trie * * p,char * str)
{
    Trie * tmp = *p;
    int i=0,k;
    while(str[i])
    {
        k = str[i] - 'a';
        if(tmp->next[k])
            tmp->next[k]->cnt++;
        else
        {
            tmp->next[k] = creat();
        }
        tmp = tmp->next[k];
        i++;
    }
}
int fnd(Trie * rt, char * str)
{
    if(rt == NULL)
        return 0;
    Trie * tmp = rt;
    int i=0,k;
    while(str[i])
    {
        k = str[i]-'a';
        if(tmp->next[k])
            tmp = tmp->next[k];
        else
            return 0;

        i++;
    }
    return tmp->cnt;
}

int main()
{
    int n,m;
    cin>>n;
    Trie *rt = creat();
    char str[15];
    for(int i=0; i<n; i++)
    {
        scanf("%s",str);
        Insrt(&rt,str);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        scanf("%s",str);
        cout<<fnd(rt,str)<<endl;
    }
    return 0;
}
