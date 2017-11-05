#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int f[50][50];
    f[0][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int a=j-1;
            int b=j+1;
            if(j==1)a=n;
            if(j==n)b=1;
            f[i][j]=f[i-1][a]+f[i-1][b];
        }
    }
    cout<<f[m][1];
    return 0;
}