#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
typedef long long int;
using namespace std;
int main(){
    int n,m;
    int a[350][350]={0};
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
        sort(a[i]+1,a[i]+m+1);
    }
    for(int i=1;i<=n;i++){
        a[i][0]=0;
        for(int j=1;j<=m;j++){
            a[i][j]+=a[i][j-1];
         //   cout<<a[i][j]<<' ';
        }
    //    cout<<'\n';
    }
    
    int dp[350][350];
    memset(dp,127,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)dp[0][i]=0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        //dp[i][i]=
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<=j;k++){
            if(j-k<=m)dp[i][j]=min(dp[i][j],dp[i-1][k]+a[i][j-k]+(j-k)*(j-k));
          //  cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[i-1][j-k]<<' '<<a[i][k]<<' '<<k*k<<'\n';
          }
        }
       // cout<<'\n';
    }
    int ans=0x7f7f7f7f;
    for(int i=n;i<=n+m;i++){
        ans=min(ans,dp[n][i]);
    }
    cout<<dp[n][n];
    return 0;
}