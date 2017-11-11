#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mod 10000000007
using namespace std;
long long  n,k;
struct mat{
    long long  a[150][150];
    void clr(){
        memset(a,0,sizeof(a));
    }
}p,pp;

mat X(mat a,mat b){
    mat ans;
    ans.clr();
    //for(long long  i=1;i<=n;i++)ans.a[i][i]=1;
    for(long long  i=1;i<=n;i++){
        for(long long  j=1;j<=n;j++){
            for(long long  k=1;k<=n;k++){
                ans.a[i][j]=(ans.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
mat pow(mat a,long long  k){
    mat ans;
    //mat g;
    //g.clr();
    for(long long  i=1;i<=n;i++)ans.a[i][i]=1;
    while(k>0){
        if(k&1)ans=X(ans,a);
        a=X(a,a);
        k>>=1;
    }
    return ans;
}
int  main(){
    cin>>n>>k;
    for(long long  i=1;i<=n;i++){
        for(long long  j=1;j<=n;j++){
            cin>>p.a[i][j];
        }
    }
    pp=X(p,p);
    for(long long  i=1;i<=n;i++){
        for(long long  j=1;j<=n;j++){
            cout<<pp.a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}