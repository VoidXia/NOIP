#include<iostream>
using namespace std;

int main(){
    int n,k;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    k--;n--;
    long long ans1=1,ans2=1,ans;
    for(int i=1;i<=n-k;i++)ans1*=i;
    for(int i=k+1;i<=n;i++)ans2*=i;
    ans=ans2/ans1;
    cout<<ans1<<' '<<ans2<<' '<<ans;
    return 0;
}