#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[120];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int f[120][120];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=a[i];k++){
                if(j-k>=0)f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
            }
        }
    }
    cout<<f[n][m];
    return 0;
}