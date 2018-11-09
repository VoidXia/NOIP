#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,t[100010];
    scanf("%lld",&n);
    long long sum=0;
    for(long long i=1;i<=n;i++)scanf("%lld",&t[i]),sum+=t[i];
    long long l=1,r=1;
    long long ans=0;
    while(l<=n&&sum>0){
        while(t[l]==0)l++;
        r=l;
        while(t[r]>0)r++;
        r--;
        for(long long i=l;i<=r;i++)t[i]--,sum--;
        ans++;
        //cout<<l<<' '<<r<<'\n';for(long long i=1;i<=n;i++)cout<<t[i]<<' ';cout<<sum<<'\n';
    }
    cout<<ans;
    return 0;
}