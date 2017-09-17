#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int dp[1000][1000]={0};
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a[1000];
            cin>>a[i];  
        }
        memset(dp,0,sizeof(dp));
        for(int k=m;k>=1;k++){
            for(int j=1;(j+k-1)>0;j++){
                dp[j][k]=min(dp[j][k+1]+timee[i]*dp[,)
            }
        }    
    }
}
