#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ln[100010];
    int ma[100010][40];
    int mi[100010][40];
    for(int i=1;i<=n;i++){
        scanf("%d",&mi[i][0]);
        ma[i][0]=mi[i][0];
    }
    for(int i=2;i<=n;i++){
        ln[i]=ln[i>>1]+1;
    }
    for(int j=1;j<31;j++){
        for(int i=1;i<=n-(1<<(j-1));i++){
            ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
            mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int t=ln[y-x+1];
        printf("%d ",max(ma[x][t],ma[y-(1<<t)+1][t])-min(mi[x][t],mi[y-(1<<t)+1][t]));
    }
    return 0;
}