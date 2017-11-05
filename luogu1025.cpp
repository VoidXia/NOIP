#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int f[3000][3000];
    for(int i=1;i<=n;i++)f[i][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            f[i][j]=f[i-1][j-1]+f[i-j][j];
        }
    }
    cout<<f[n][k];
    return 0;
}