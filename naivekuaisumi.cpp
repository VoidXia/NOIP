#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstdio>
typedef long long ll;
using namespace std;
    ll b,p,kk;
inline ll mimi(ll x,ll k){
    ll a=x;
    ll ans=1;
    while(k>0){
      //  cout<<ans;
        if(k&1)
        ans=(ans*a)%kk;
       // cout<<ans<<' '<<a<<' '<<(k&1)<<'\n';
        a=a*a%kk;
        k>>=1;
    }
    return ans;
}
int main(){

    scanf("%lld%lld%lld",&b,&p,&kk);
    cout<<b<<'^'<<p<<" mod "<<kk<<'=';
    printf("%lld",mimi(b,p)%kk);
    return 0;
}