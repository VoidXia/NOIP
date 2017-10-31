#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define mod 10007
using namespace std;
int mimi(int x,int y){
    int a=x;
    int ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*a)%mod;
        y>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main(){
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    a%=mod;
    b%=mod;
    a=mimi(a,n);
    b=mimi(b,m);
    //cout<<a<<' '<<b<<' ';
    int c[1010][1010];
    for(int i=1;i<=k;i++){
        c[i][i]=1;
        c[i][0]=1;
    }
    int p=min(n,m);
    for(int i=2;i<=k;i++){
        for(int j=1;j<=p;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    int ans;
    ans=(a*b)%mod;
    //cout<<c[k][p]<<' ';
    ans=(ans*c[k][p])%mod;
    cout<<ans;
    return 0;
}