#include<iostream>
using namespace std;
int main(){
    int fx,fy,dx,dy;
    cin>>fx>>fy>>dx>>dy;
    bool a[30][30]={0};
    a[dx][dy]=a[dx+2][dy+1]=a[dx+2][dy-1]=a[dx-2][dy+1]=a[dx-2][dy-1]=a[dx+1][dy+2]=a[dx+1][dy-2]=a[dx-1][dy+2]=a[dx-1][dy-2]=1;

    long long dp[30][30]={0};
    for(int i=0;i<30;i++)dp[0][i]=1,dp[i][0]=1;
    for(int i=1;i<=fx;i++){
        for(int j=1;j<=fy;j++){
            if(a[i][j]==0)dp[i][j]=dp[i-1][j]+dp[i][j-1];

        }
    }
    cout<<dp[fx][fy];
    return 0;
}