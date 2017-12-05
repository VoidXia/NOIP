#include<iostream>
using namespace std;
#define kk 3148357999
typedef long long ll;
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
    ll i;
    for(i=1;i<=(1ll<<62)-1;i<<=1){
        if((i&(i-1))==0)cout<<i<<'\n';
        //ll yy=mimi(i,65537);
        ll yy;
        if(yy==2161012058){cout<<i;
        break;
        }
    }
    cout<<i;
}