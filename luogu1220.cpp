#include<bits/stdc++.h>
#define inf 0x3f3f3f3f;
using namespace std;
int main(){
    int a[10000]={0},b[10000]={0};
    int n,c;
    int dp[10000][10000][2]={0};

    ios::sync_with_stdio(false);
    cin>>n>>c;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[c][c][1]=dp[c][c][0]=0;
    for(int i=1;i<=n;i++){cin>>a[i]>>b[i];b[i]+=b[i-1];}
    for(int i=c;i>=1;i--){
        for(int j=i;j<=n;j++){

            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i+1]-a[i])*(b[n]-b[j]+b[i]));
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[j]-a[i])*(b[n]-b[j]+b[i]));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j]-a[j-1])*(b[n]-b[j-1]+b[i-1]));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[j]-a[i])*(b[n]-b[j-1]+b[i-1]));
        }
    }
    cout<<min(dp[1][n][1],dp[1][n][0]);
    return 0;
}