#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s,tt;
#define N 35200
#define ini(x,a) memset(x,a,sizeof(x))
inline long long read(){
    long long x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}
long long last[N],cnt=0,a,b,c;
struct edge{long long to,next,val;}e[N*8];
void add(long long a,long long b,long long c){
    e[cnt].to=b;
    e[cnt].next=last[a];
    e[cnt].val=c;
    last[a]=cnt++;
}
long long dis[N][20];
bool vis[N][20];
struct node{long long idx;long long dis;long long used;bool operator<(const node&a)const{return dis>a.dis;}};
void dij(){
    priority_queue<node>q;
    q.push((node){s,0,0});
    dis[s][0]=0;
    while(!q.empty()){
        long long u=q.top().idx,t=q.top().used;
        q.pop();
        if(vis[u][t]==1)continue;
        vis[u][t]=1;
        if(u==tt)continue;
        for(long long i=last[u];~i;i=e[i].next){
            long long to=e[i].to;
            if(t<k&&vis[to][t+1]==0&&dis[to][t+1]>dis[u][t]){
                dis[to][t+1]=dis[u][t];
                q.push((node){to,dis[to][t+1],t+1});
            }
            if(vis[to][t]==0&&dis[to][t]>dis[u][t]+e[i].val){
                dis[to][t]=dis[u][t]+e[i].val;
                q.push((node){to,dis[to][t],t});
            }
        }
    }
}
int main(){
    ini(last,-1);
    ini(dis,0x7e);ini(vis,0);
    //cout<<dis[0]<<'\n';
    cin>>n>>m>>k>>s>>tt;
    for(long long i=1;i<=m;i++){
        a=read();b=read();c=read();
        add(a,b,c);add(b,a,c);
    }
    dij();
    long long ans=9223372036854775000;
    for(long long i=0;i<=k;i++){ans=min(ans,dis[tt][i]);}
    cout<<ans;
    return 0;
}