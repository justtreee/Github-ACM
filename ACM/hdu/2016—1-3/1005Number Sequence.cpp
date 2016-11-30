/*#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int f(int a,int b,int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return (a*f(a,b,n-1)+b*f(a,b,n-2))%7;
}
=============================================
int r[10000];
int main()
{
    int a,b,n;
    r[1] = r[2] = 1;
    while(cin>>a>>b>>n,a||b||n)
    {
        int i;
        for(i=3; i<10000; i++)
        {
            r[i] = (a*r[i-1]+b*r[n-2])%7;
            if(r[i]==1 && r[i-1]==1)
                break;
        }
        n = n % (i-2);//zhouqi
        r[0] = r[i-2];//zhaodao diyige
        cout<<r[n]<<endl;


    }
return 0;
}
================================================
*/

//Problem:hdu1005
//Data:2011/10/30
#include <iostream>
using namespace std;

int arr[10000];

int main()
{
	int A,B,n;
	//freopen("E:\\in.txt","r",stdin);
	arr[1] = arr[2] = 1;
	while(cin>>A>>B>>n, A || B || n)
	{
		int i;
		for(i=3; i<10000 ;i++)
		{
			arr[i] = (A*arr[i-1] + B*arr[i-2]) % 7;

			//������������� =1��������ȫ����ǰ����ͬ��������������
			//��ʱ��û��Ҫ�ٽ�����ȥ�ˣ�����ѭ��, i-2Ϊ����
			if(arr[i] == 1 && arr[i-1] == 1)
				break;
		}
		n = n % (i-2);

		// ��n��������ģ����n = i-2ʱ, n=0,��ʱ����Ӧ��ȡarr[i-2]�ģ����԰�arr[0]=arr[i-2]
		//Ҳ����������
		//if(n==0)	 n=i-2;

		arr[0] = arr[i-2];

		cout << arr[n] << endl;
	}
	return 0;
}
