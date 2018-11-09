#include<bits/stdc++.h>
using namespace std;
#define maxn 210
int n,m,t[maxn],dis[maxn][maxn][maxn],a,b,c,q,r;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&t[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        dis[0][a][b]=dis[0][b][a]=c;
    }
    for(int i=0;i<n;i++)dis[0][i][i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dis[0][i][j]=min(dis[0][i][j],dis[0][i][0]+dis[0][0][j]);
    for(int k=1;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dis[k][i][j]=min(dis[k-1][i][j],dis[k-1][i][k]+dis[k-1][k][j]);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        r=upper_bound(t,t+n,c)-t-1;
        if(t[a]<=c&&t[b]<=c&&dis[r][a][b]!=0x3f3f3f3f)cout<<dis[r][a][b]<<'\n';else cout<<"-1\n";
    }
    return 0;
}