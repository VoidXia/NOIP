#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int mod;
inline ll pow(ll x,ll k){
    ll a=x;
    ll ans=1;
    while(k>0){
      //  cout<<ans;
        if(k&1)
        ans=1LL*ans*a*(k&1)%mod;
       // cout<<ans<<' '<<a<<' '<<(k&1)<<'\n';
        a=1LL*a*a%mod;
        k>>=1;
    }
    return ans;
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    ll n,m,k,x;
    cin>>n>>m>>k>>x;
    mod=n;
    ll a=pow(10,k);
    a*=m;
    a+=x;
    a%=mod;
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;

    

}