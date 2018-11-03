#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define ini(x,a) memset(x,a,sizeof(x))
struct edge{
    int to,next;
}e1[5*maxn],e2[5*maxn];
int last1[maxn*5],last2[maxn*5];
int cnt1=0,cnt2=0;
void addedge(int x,int y){
    e1[cnt1].to=y;
    e1[cnt1].next=last1[x];
    last1[x]=cnt1++;
    e2[cnt2].to=x;
    e2[cnt2].next=last2[y];
    last2[y]=cnt2++;
}
int n,m;
int a[maxn];
inline int read(){
    int x=0,a=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}
int s[maxn];
bool vis1[maxn];
int dis[maxn];
void bfs1(){
    ini(dis,0x7f7f7f7f);
    queue<int>q;
    q.push(1);
    ini(vis1,0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        vis1[t]=1;
        //cout<<'1'<<' '<<t<<'\n';
        for(int i=last1[t];~i;i=e1[i].next){
            int to=e1[i].to;
            if(dis[to]>min(dis[t],a[to]))dis[to]=min(dis[t],a[to]);
            if(vis1[to]==0){
                q.push(to);
            }
        }
    }
    return;
}
bool vis2[maxn];
void bfs2(){
    queue<int>q;
    q.push(n);
    ini(vis2,0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        vis2[t]=1;
        //cout<<'2'<<' '<<t<<'\n';
        for(int i=last2[t];~i;i=e2[i].next){
            int to=e2[i].to;
            //cout<<"to"<<to;
            if(vis2[to]==0)q.push(to);
        }
    }
    return;
}
/*
int ans=0;
void spfa(){
    int dis[maxn];
    bool vis[maxn];
    ini(vis,0);
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(vis1[i]&&vis2[i])q.push(i),dis[i]=a[i],vis[i]=1;
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        vis[t]=0;
        for(int i=last1[t];~i;i=e1[i].next){
            int to=e1[i].to;
            if(vis1[to]&&vis2[to]){
                if(dis[to]>dis[t]){
                    dis[to]=dis[t];
                    if(vis[to]==0)q.push(to),vis[to]=1;

            }
        }
    }
}*/
int main(){
    ini(last1,-1);
    ini(last2,-1);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)a[i]=read();
    while(m--){
        int x=read(),y=read(),z=read();
        //cout<<x<<' '<<y<<' '<<z<<"a\n";
        addedge(x,y);
        if(z==2)addedge(y,x);
    }
    //cout<<last1[1]<<'\n';
    bfs1();
    bfs2();
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis1[i]&&vis2[i])ans=max(ans,a[i]-dis[i]);
    }
    cout<<ans;
    return 0;
}
