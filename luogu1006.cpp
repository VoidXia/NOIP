#include<iostream>
using namespace std;
int main(){
    int m,n;
    int a[55][55];
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    }
    int dp[55][55][55][55]={0};
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                for(int l=1;l<=n;l++){
                    if(i+j==k+l){
                        dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l])));
                        if(i!=j)dp[i][j][k][l]=a[i][j]+a[k][l]+dp[i][j][k][l];
                        if(i==j)dp[i][j][k][l]+=a[i][j];
                    }
                }
            }
        }
    }
    cout<<dp[m][n][m][n];
    return 0;
}