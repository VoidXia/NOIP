#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define maxn 2147483647
using namespace std;
struct node{
    int to,next,v;
}a[500010];
int cnt;
int d[500010];
int n,m,s;
int head[500010];
void ins(int u,int v,int w){
    a[++cnt].to=v;
    a[cnt].next=head[u];
    a[cnt].v=w;
    head[u]=cnt;
}
/*void insert(int u,int v,int w){
    ins(u,v,w);
    ins(v,u,w);
}*/
void dj(){
    bool vis[500010]={0};
    for(;;){
        int mi=maxn;
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&d[j]<mi){
                mi=d[j];
                t=j;
            }
        }
        if(t==-1||mi==maxn)break;
        vis[t]=1;
        for(int j=head[t];j;j=a[j].next){
            if(!vis[a[j].to]&&d[a[j].to]>a[j].v+d[t])
            d[a[j].to]=a[j].v+d[t];
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)d[i]=maxn;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ins(x,y,z);
    }
    d[s]=0;
    dj();
    for(int i=1;i<=n;i++)cout<<d[i]<<' ';
    return 0;
}