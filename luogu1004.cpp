#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int p=n;
    int a[12][12]={0};
    int dp[12][12][12][12]={0};
    int x,y,z=1;
    while(x!=0&&y!=0&&z!=0){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=z;
    }
    for(register int i=1;i<=p;i++){
        for(register int j=1;j<=p;j++){
            for(register int k=1;k<=p;k++){
                for(register int l=1;l<=p;l++){
                    dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l])))+a[i][j]+a[k][l];
                    if(i==k&&j==l)dp[i][j][k][l]-=a[i][j];
                }
            }
        }
    }
    printf("%d\n",dp[p][p][p][p]);
    return 0;
}