#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<cstring>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int f[100010][31];
    for(int i=1;i<=n;i++)scanf("%d",&f[i][0]);
    int ln[100010];
    for(int i=2;i<=n;i++){
        ln[i]=ln[i<<1]+1;
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n-(1<<(j-1));i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<j)][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int t=ln[y-x+1];
        cout<<max(f[x][t],f[y-(1<<t)][t])<<'\n';
    }
    return 0;
}