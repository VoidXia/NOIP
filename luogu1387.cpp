#include<iostream>
using namespace std;
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a[150][150]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int mm=min(n-i,m-j);
            mm++;
            for(int k=1;k<=mm;k++){
                if(a[i+k][j+k]-a[i][j+k]-a[i+k][j]+a[i][j]==k*k)ans=max(ans,k);
            }
        }
    }
    cout<<ans;
    return 0;
}