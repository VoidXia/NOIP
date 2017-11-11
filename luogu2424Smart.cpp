#include<cstdio>

//参考zzlzk题解
using namespace std;
typedef long long ll;
ll sum(ll n){
    if(n<=1)return n;
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=(n/l)/*约数*/*(l+r)*(r-l+1);
    }
    return ans;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld",sum(m)-sum(n-1));
    return 0;
}