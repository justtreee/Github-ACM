#include <iostream>
using namespace std;
const int M = 100005;
int father[M*2],n;
void init()
{
    for(int i=1; i<=2*n;i++)
    {
        father[i] = i;
    }
}
int find(int a)
{
    if(father[a]!=a)
        father[a]=find(father[a]);
    return father[a];
}
void unionx(int a,int b)
{
    int fa = find(a);
    int fb = find(b);
    if(fa!=fb)
        father[fa] = fb;
}

bool judge(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int a,t;

    cin>>n;
    init();
    for(int i=1; i<=n; i++)
    {
        cin>>a>>t;
        if(t==1)
        {
            unionx(a,i);
            unionx(a+n,i+n);//bad
        }
        else
        {
            unionx(a,i+n);
            unionx(a+n,i);//bad guys lie
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(judge(i,i+n))
        {
            cout<<"One face meng bi"<<endl;
            return 0;
        }
    }



    cout<<"Time to show my power"<<endl;
    return 0;
}
