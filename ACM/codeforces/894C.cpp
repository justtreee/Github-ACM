#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n ,a[1005];
  cin>>n;
  int flag = 1;
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
    if(i>0 && a[i]%a[0]!=0)
      flag = 0;
  }
  if(!flag)
  {
    cout<<"-1"<<endl;
    return 0;
  }
  else
  {
    cout<<n*2<<endl;
    for(int i=0; i<n; i++)
    {
      cout<<a[i]<<" "<<a[0]<<" ";
    }
  }
}
