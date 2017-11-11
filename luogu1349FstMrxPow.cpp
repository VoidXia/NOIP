#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
//#define mod 1000000007
int mod;
typedef long long ll;
ll n=2;
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
//Multiply
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
    ll ppp,q,a1,a2,nn,m;
    mod=m;
    cin>>ppp>>q>>a1>>a2>>nn>>m;
    p.m[1][1]=ppp;
    p.m[1][2]=q;
    p.m[2][1]=1;
    p.m[2][2]=0;
    //C    O    R    E    :
    //[f[n+1],f[n]]=A^(n-1)*[f[2],f[1]]


    /*for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            scanf("%lld",&p.m[i][j]);
        }
    }*/
    pp=pow(p,nn-1);
    /*for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            printf("%lld ",pp.m[i][j]);
        }
        printf("\n");
    }*/
    cout<<pp.m[2][1]*a2+pp.m[2][2]*a1;
    return 0;
}













//naive version
/*#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef longlong ll;
ll DP(ll x){
    if(x==1||x==2)return 1;
    if(dp[i]<>0)return dp[i];
    return dp[i]=DP(i-1)+DP(i-2);
}

int main(){
    ll dp[i]={1,1},n;
    cin>>n;
    cout<<DP(n)<<endl;
    return 0;

    
}*/