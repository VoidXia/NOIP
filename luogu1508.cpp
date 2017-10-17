#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int m,n;
    ios::sync_with_stdio(false);
    cin>>m>>n;
    int a[210][210]={0};
    int dp[210][210];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dp[m][n/2+1]=0;
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=max(a[i+1][j],max(a[i+1][j+1],a[i+1][j-1]));
            
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(max(a[m][n/2+1],a[m][n/2+2]),a[m][n/2]);
    cout<<ans;
    return 0;

}