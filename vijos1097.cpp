#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,ll;
    int a[100000]={0};
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll=n;
    long long ans=0;
    for(int i=0;i<ll-1;i++){
        if (a[2]==100000)break;
        ans=ans+a[0]+a[1];
        a[1]=a[1]+a[0];
        a[0]=100000;
       // n--;
        //sort(a+1,a+n);
        for(int j=2;j<n;j++){
            if(a[j-1]>a[j])swap(a[j-1],a[j]);
        }
        for(int j=0;j<n;j++)a[j]=a[j+1];
        n--;
    }
       /* a[i+1]=a[i]+a[i+1];
        for(int j=i+1;j<n;j++){
            if (a[i]>a[j])swap(a[i],a[j]);else break;
        }}*/
    cout<<ans<<endl;
    return 0;
}