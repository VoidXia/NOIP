#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    k++;
    int a[810][810]={0};
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[i][j]%=k;
        }
    }
    int dp[801][801][801][801];
    
}