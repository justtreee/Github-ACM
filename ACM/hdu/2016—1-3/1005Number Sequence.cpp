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

			//如果有两个连着 =1，则后面的全部和前面相同，即出现了周期
			//这时就没必要再进行下去了，跳出循环, i-2为周期
			if(arr[i] == 1 && arr[i-1] == 1)
				break;
		}
		n = n % (i-2);

		// 把n对周期求模，当n = i-2时, n=0,此时本来应该取arr[i-2]的，所以把arr[0]=arr[i-2]
		//也可以这样：
		//if(n==0)	 n=i-2;

		arr[0] = arr[i-2];

		cout << arr[n] << endl;
	}
	return 0;
}
