#include <stdio.h>
#include <string.h>
//using namespace std;
#define  M 10005
int next[M];
char S[M],T[M*100];
int slen,tlen;
void getnext()
{
    int j,k;
    j=0,k=-1;
    next[0] =-1;
    while(j<slen)
    {
        if(k==-1||S[j]==S[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}
int kmp()
{
    int ans =0;
    if(slen ==1 && tlen ==1)
    {
        if(S[0]==T[0])  return 1;
        else
             return 0;
    }
    getnext();
    int i,j=0;
    for(i=0 ; i<tlen ; i++)
    {
        while(j>0 && T[i]!= S[j])
        {
            j = next[j];
        }
        if(S[j] == T[i])    j++;
        if(j==slen)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

int main()
{
    int CAS;
    scanf("%d",&CAS);
    while(CAS--)
    {
        scanf("%s%s",&S,&T);
        slen = strlen(S);
        tlen = strlen(T);
        //cout<<slen<<" "<<tlen<<endl;
        printf("%d\n",kmp());
    }
}
