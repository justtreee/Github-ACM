#include <iostream>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        if(a[0]==15)
            cout<<"DOWN"<<endl;
        else if(a[0]==0)
            cout<<"UP"<<endl;
        else
            cout<<"-1"<<endl;
        return 0;
    }
//    if(a[n-1]==15)
//        cout<<"DOWN"<<endl;
//
    if(a[n-1]>a[n-2]&&a[n-1]!=15)
        cout<<"UP"<<endl;
    else if(a[n-1]>a[n-2]&&a[n-1]==15)
        cout<<"DOWN"<<endl;
    else if(a[n-1]!=0)
        cout<<"DOWN"<<endl;
    else
        cout<<"UP"<<endl;

    return 0;
}
