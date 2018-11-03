#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=n*m;
    for(ll l=1,r=0;l<=n;l=r+1){
        if(m/l!=0)r=min(n,m/(m/l));else r=n;
        //cout<<l<<' '<<r<<'\n';
        ans-=(r-l+1)*(r+l)*(m/l)/2;
    }
    cout<<ans;
    return 0;
}//EXTREMELY CLEVER !!!