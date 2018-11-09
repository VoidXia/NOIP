#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 1000010
#define ini(x,a) memset(x,a,sizeof(x))
struct e{LL to,next;}e[N];
LL last[N],cnt=0,n,m,k,s,p,q,c,d;
long long safe[N];
void adde(long long a,long long b){
    e[cnt].to=b;e[cnt].next=last[a];last[a]=cnt++;
}
struct nod{LL idx;LL dis;
    bool operator <(const nod&a)const{return dis>a.dis;}
};
queue<nod>qu;
void bfs(){
    long long t,d;
    while(!qu.empty()){
        t=qu.front().idx;d=qu.front().dis;
        qu.pop();
        for(long long i=last[t];~i;i=e[i].next){
            long long to=e[i].to;
            if(safe[to]==1&&d<s){
                safe[to]=0;
                qu.push((nod){to,d+1});
            }
        }
    }
}
long long dist[N];
void dij(){
    priority_queue<nod>pq;
    pq.push((nod){1,0});
    bool vis[N];
    dist[1]=0;
    memset(vis,0,sizeof(vis));
    while(!pq.empty())
    {
        LL u=pq.top().idx;pq.pop();
        //cout<<u<<"u\n";
        if(vis[u])continue;
        vis[u]=true;
        for(LL i=last[u];~i;i=e[i].next)
        {
            //cout<<e[i].to<<"to\n";
            //if(e[i].to==n)cout<<dist[u]<<"u\n";
            if(e[i].to==n){if(dist[e[i].to]>dist[u]){dist[e[i].to]=dist[u];pq.push((nod){e[i].to,dist[e[i].to]});}continue;}
            if(safe[e[i].to]==-1)continue;
            if(safe[e[i].to]==0)
                if(dist[e[i].to]>dist[u]+q)
                {
                    if(e[i].to==n)cout<<dist[e[i].to];
                    dist[e[i].to]=dist[u]+q;
                    pq.push((nod){e[i].to,dist[e[i].to]});
                }
            if(safe[e[i].to]==1)
                if(dist[e[i].to]>dist[u]+p)
                {
                    if(e[i].to==n)cout<<dist[e[i].to];
                    dist[e[i].to]=dist[u]+p;
                    pq.push((nod){e[i].to,dist[e[i].to]});
                }
        }
    }
}
int main(){
    ini(last,-1);//ini(dist,0x3f);
    cin>>n>>m>>k>>s>>p>>q;
    for(long long i=1;i<=n;i++)safe[i]=1,dist[i]=1e16;
    for(long long i=1;i<=k;i++){scanf("%lld",&c);safe[c]=-1;qu.push((nod){c,0});}
    for(LL i=1;i<=m;i++){
        scanf("%lld%lld",&c,&d);//cout<<"\n"<<c<<' '<<d<<"\n";
        adde(c,d);adde(d,c);
        //cout<<i<<"m\n";
    }
    //cout<<"end";
    bfs();
    //for(LL i=1;i<=n;i++)cout<<last[i]<<' ';
    //cout<<'\n';
    dij();
    //if(safe[n]==1)dist[n]-=p;else dist[n]-=q;
    cout<<dist[n];
}