#include<iostream>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    int w[110]={0};
    int v[110]={0};
    for(int i=1;i<=t;i++){
        cin>>w[i]>>v[i];
    }
    int dp[1010]={0};
    for(int i=1;i<=n;i++){
        for(int j=100;j>=1;j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
   cout<<dp[n];
   return 0;
}