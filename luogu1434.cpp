#include<bits/stdc++.h>
using namespace std;
int a[110][110]={0},dp[110][110]={0},vi[110][110]={0},n,m;

int DP(int x,int y){
    if (x<0||y<0||x>n||y>m)return -9999;
    if (vi[x][y])return dp[x][y];
    vi[x][y]=1;
    if (a[x-1][y]<a[x][y])dp[x][y]=max(dp[x][y],DP(x-1,y));
    if (a[x][y-1]<a[x][y])dp[x][y]=max(dp[x][y],DP(x,y-1));
    if (a[x+1][y]<a[x][y])dp[x][y]=max(dp[x][y],DP(x+1,y));
    if (a[x][y+1]<a[x][y])dp[x][y]=max(dp[x][y],DP(x,y+1));
    return ++dp[x][y];
}


int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    int ans=0;
    for (int i=1;i<=n+1;i++)a[i][0]=a[i][m+1]=INFINITY;
    for (int i=1;i<=m+1;i++)a[0][i]=a[n+1][i]=INFINITY;
    for (int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans=max(ans,DP(i,j));
    cout<<ans<<endl;
    return 0;
}