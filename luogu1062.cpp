#include<iostream>
using namespace std;
typedef long long ll;
ll pow(ll a,ll b){
    ll ans=1;
    ll k=a;
    while (b>0){
        if(b&1)ans*=k;
        b>>=1;
        k*=k;
    }
    return ans;
}
int main(){
    ll k,n;
    cin>>k>>n;
    ll ans=0;
    ll i=0;
    while(n>0){
        if(n&1)ans+=pow(k,i);
        i++;
        n>>=1;
    }
    cout<<ans;
    return 0;
}