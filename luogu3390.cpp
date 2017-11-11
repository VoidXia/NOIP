#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define mod 1000000007
typedef long long ll;
ll n;
using namespace std;
struct mat{
    ll m[105][105];
    void clr(){
        memset(m,0,sizeof(m));
    }
}p,pp;
mat mul(mat x,mat y){
    mat box;
    box.clr();
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                box.m[i][j]=(box.m[i][j]+(x.m[i][k]*y.m[k][j])%mod)%mod;
            }
        }
    }
    return box;
}
mat pow(mat p,ll k){
    mat ans;
    for(ll i=1;i<=n;i++)ans.m[i][i]=1;
    while(k>0){
        if(k&1)ans=mul(ans,p);
        p=mul(p,p);
        k>>=1;
    }
    return ans;
}
int main(){
    ll k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            scanf("%lld",&p.m[i][j]);
        }
    }
    pp=pow(p,k);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            printf("%lld ",pp.m[i][j]);
        }
        printf("\n");
    }
    return 0;
}