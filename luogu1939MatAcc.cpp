#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
typedef long long ll;
#define mod 1000000007
using namespace std;
ll n=3;
struct mat{
    ll a[10][10];
    void clr(){
        memset(a,0,sizeof(a));
    }
};
mat X(mat a,mat b){
    mat ans;
    ans.clr();
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                ans.a[i][j]=(ans.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
mat pow(mat a,ll i){
    mat ans;
    ans.clr();//Somehow important
    for(ll i=1;i<=n;i++){ans.a[i][i]=1;}
    while(i>0){
        if(i&1)ans=X(ans,a);
        a=X(a,a);
        i>>=1;
    }
    return ans;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        mat a;
        a.clr();
        a.a[1][1]=1;
        a.a[1][3]=1;
        a.a[2][1]=1;
        a.a[3][2]=1;
        mat ans;
        ans=pow(a,x-3);
        ll aa;
        aa=(ans.a[1][1]+ans.a[1][2]+ans.a[1][3])%mod;
        //MOD!!!
        cout<<aa<<'\n';
        //ans=X(a,a);
       /* for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
        cout<<ans.a[i][j]<<' ';
        cout<<'\n';
        }*/
    }
    return 0;
}