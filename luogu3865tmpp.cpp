#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
   // int a[100010];
    int f[100010][40];
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i][0]);
    }
    int ln[100010];
    for(int i=2;i<=n;i++)
    ln[i]=ln[i>>1]+1;
    for(int i=1;i<=40;i++){
        for(int j=1;j<=n-(1<<(j-1));j++){
            f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        int t=ln[r-l+1];
        cout<<max(f[l][t],f[r-(1<<t)][t])<<'\n';
    }
    return 0;

}