#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[100010];
int mm[100010],vv[100010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        fa[b]=a;
        vv[a]+=vv[b];
        mm[a]+=mm[b];
    }
}

int main(){
    int n,m,w;
    cin>>n>>m>>w;
   // cout<<n<<' '<<m<<' '<<w<<'\n';
    for(int i=1;i<=n;i++){
        scanf("%d%d",&mm[i],&vv[i]);
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    int dp[100010]={0};
    for(int i=1;i<=n;i++){
        if(fa[i]==i)
        for(int j=w;j>=mm[i];j--){
            dp[j]=max(dp[j],dp[j-mm[i]]+vv[i]);
         //   cout<<dp[j]<<'\n';
        }
       // cout<<fa[i]<<' '<<i<<' '<<mm[i]<<' '<<vv[i]<<'\n';}
    }
    cout<<dp[w];
    return 0;
}