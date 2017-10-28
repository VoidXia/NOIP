#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    int a[310][310]={0};
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
        sort(a[i]+1,a[i]+m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]+=a[i][j-1];
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    int dp[310][310];
    memset(dp,127,sizeof(dp));
    //for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        //dp[i][i]=
        for(int j=i;j<=m;j++){
            for(int k=1;k<=m;k++)
            dp[i][j]=min(dp[i][j],dp[i-1][j-k]+a[i][k]+k*k);
            cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
        cout<<'\n';
    }
    int ans=0x7f7f7f7f;
    for(int i=n;i<=n+m;i++){
        ans=min(ans,dp[n][i]);
    }
    cout<<ans;
    return 0;
}