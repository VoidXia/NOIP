#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    int a[1010][1010];
    memset(a,0,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=-1){
                a[i][j]=(a[i][j-1]+a[i-1][j])%100003;
            }
        }
    }
    cout<<a[n][n];
    return 0;
}