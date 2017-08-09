#include<bits/stdc++.h>
using namespace std;

//int DP(int x;int y){}
int a[1000]={0},dp[1000][1000]={0},l,r,x,ans,n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
    for (int i=2;i<2*n;i++)for(l=1;l+i-1<=2*n;l++){r=l+i-1;for (x=l;x<r;x++){
        dp[l][r]=max(dp[l][r],dp[l][x]+dp[x+1][r]+a[l]*a[r+1]*a[x+1]);
    }}
    for(l=1;l<=n;l++)ans=max(ans,dp[l][l+n-1]);
    cout<<ans<<endl;
    return 0;
}