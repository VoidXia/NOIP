#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int a[10000]={0};
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
        ans=ans+(n-i)*(a[i]);
    ans=ans-a[0];
    cout<<ans<<endl;
    return 0;
}