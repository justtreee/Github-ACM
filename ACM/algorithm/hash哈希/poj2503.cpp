#include<iostream>
#include<cstring>
using namespace std;

const int MAX=100003;
char word[MAX][11],dic[MAX][11];
int head[MAX],nextpos[MAX];

int calhash(char c[])
{
    int len = strlen(c);
    int sum = 0;
    for (int i=0; i<len; i++)
    {
        sum=sum*7+(c[i]-'a');
    }
    return sum%MAX;
}
void insert_table(int s,char ch[])
{
    int h=calhash(ch);
    nextpos[s]=head[h];
    head[h]=s;
}
int findstr(char ch[])
{
    int h=calhash(ch);
    int u=head[h];
    while (u)
    {
        if (strcmp(ch,dic[u])==0)
            return u;
        u=nextpos[u];
    }
    return 0;
}
void print(int u)
{
    int len = strlen(word[u]);
    for (int i=0; i<len; i++)
        cout<<word[u][i];
    cout<<endl;
}
int main ()
{
    char line[30];

    int dex=1;
    while (cin.getline(line,30)&&line[0]!='\0')
    {
        int i=0,j=0;
        while (line[i]!=' ')
        {
            word[dex][i]=line[i];
            i++;
        }
        word[dex][i++]='\0';
        while (line[i]!='\0')
        {
            dic[dex][j++]=line[i++];
        }
        dic[dex][j]='\0';
        insert_table(dex,dic[dex]);
        dex++;
    }
    while  (1)
    {
        char tar[11];
        cin.getline(tar,11);
        if (tar[0]=='\0') break;
        int flag=findstr(tar);
        if (flag>0)
            print(flag);
        else cout<<"eh"<<endl;
    }
    return 0;
}
