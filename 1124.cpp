#include<iostream>
using namespace std;
#define kk 3148357999
typedef unsigned long long ll;
inline ll mimi(ll x,ll k){
    ll a=x;
    ll ans=x;
    /*while(k>0){
      //  cout<<ans;
        if(k&1)
        ans=(ans*a*(k&1))%kk;
       // cout<<ans<<' '<<a<<' '<<(k&1)<<'\n';
        a=a*a%kk;
        k>>=1;
    }*/
    for(int i=2;i<=17;i++){
        ans%=kk;
        ans=(ans*ans)%kk;
      //  if(ans<0)cout<<"Boom"<<'\n';
    }

    ans*=x;
    return ans%=kk;
}
int main(){
    ll i;
    ll anss=5711711023;
    for(i=1;;i++){
        if((i&(i-1))==0)cout<<i<<'\n';
        ll yy=mimi(i,65537);
       // cout<<i<<' '<<yy<<'\n';
        if(yy==2161012058){cout<<i;
        break;
        }
    }
    cout<<"END\n";
}