#include<bits/stdc++.h>
using namespace std;
#define maxn 10
const double pi = 3.141592653589793238;
int n,x1,x2,yy1,y2,area;
int x[maxn],y[maxn];bool vis[maxn];
double r[maxn];
double getrad(int i){
    double an=min(min(abs(x1-x[i]),abs(x2-x[i])),min(abs(y2-y[i]),abs(yy1-y[i])));
    for(int j=1;j<=n;j++){
        if(i!=j&&vis[j]==1){
            double dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            an=min(an,max(dis-r[j],0.0));
        }
    }
    return an;
}
double ans=0;
void dfs(int k,double sum){
    if(k==n){ans=max(sum,ans);return;}
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            r[i]=getrad(i);
            //cout<<i<<' '<<r[i]<<'\n';
            vis[i]=1;
            dfs(k+1,sum+r[i]*r[i]*pi);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d%d%d",&n,&x1,&yy1,&x2,&y2);
    area=abs((x1-x2)*(yy1-y2));
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    dfs(0,0);
    ans=(int)(area-ans+0.5);
    printf("%d",(int)ans);
    return 0;
}