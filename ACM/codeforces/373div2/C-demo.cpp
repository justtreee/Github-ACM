#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

#define MAXN 5005
#define inf 0x3f3f3f3f
#define ONES(x) __builtin_popcount(x)
using namespace std;


int n,t;
int ans;
char str[200005];
int main()
{
    //freopen("test.txt","r",stdin);
    cin>>n>>t;
    cin>>str;
    int len = strlen(str);
    int dot_pos = 0,pos = 0;//pos->the operation place
    int flag = 0;
    int last = len;//last��ǽ�ֹ��λ�ã�ʱ�̸���
    for(int i = 0; i<len ; i++)//Ԥ�����֣��ҵ�С�����λ�ú�С��������һ������5�����ֵ�λ��
    {
        if(str[i]=='.')
            {dot_pos = i;flag = 1;}
        if(flag==1 && str[i]-'5'>=0)
            {pos = i;break;}
    }
    if(pos <= dot_pos)//����С�����û�д���5�����ֵ����
    {
        for(int i = 0; i<len ; i++)
            cout << str[i];
        cout << endl;
        return 0;
    }
    int m = len - dot_pos;
    int k = 0;
    while(k<min(m-1,t) && pos>dot_pos && str[pos]>='5')//�������k���������룬λ�ò��ܳ���С����
    {
        if(pos-1 == dot_pos)
            pos--;
        while(str[pos-1]=='9')//����9�Ľ�λ�����
        {
            pos--;
            if(pos-1 == dot_pos)//����Խ��С����
                pos--;
            last = pos;
        }
        str[pos-1] += 1;
        pos--;
        last = pos;
        k++;
    }
    //cout << last << endl;
    for(int i = 0; i<=last ; i++)
        cout << str[i];
    if(last==-1 && str[0]=='9')//���⴦����Ҫ+1�����
        cout << "1" ;
    while(last+1<dot_pos)
    {
        cout << "0";
        last++;
    }
    cout << endl;
    //cout << ans << endl;
    return 0;
}
