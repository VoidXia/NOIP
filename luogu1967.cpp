#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int n,m,f[maxn];
int find(int x){return f[x]==x?f[x]:find(f[x]);}
int a,b,c;
struct edge{
    int f,t,val;
}ed[maxn*5];
bool operator < (const edge &a,const edge &b){
    return a.val>b.val;
}
struct edd{
    int to,next,val;
}e[maxn*5];
int cnt1=0;
int last[maxn];
void addedge(int x,int y,int z){
    e[cnt1].to=y;
    e[cnt1].next=last[x];
    e[cnt1].val=z;
    last[x]=cnt1++;
    //cout<<"adding"<<x<<' '<<y<<' '<<z<<'\n';
}
int cnt=0,x,y;
int lg[maxn],depth[maxn];
int fa[maxn][25],minval[maxn][25];
void dfs(int s){
    for(int i=1;i<=lg[depth[s]];i++){
        fa[s][i]=fa[fa[s][i-1]][i-1];
        minval[s][i]=min(minval[s][i-1],minval[fa[s][i-1]][i-1]);
    }
    for(int i=last[s];~i;i=e[i].next){
        int to=e[i].to;
        if(to!=fa[s][0]){
            fa[to][0]=s;
            minval[to][0]=e[i].val;
            depth[to]=depth[s]+1;
            dfs(to);
        }
    }
}
int lca(int x,int y){
    int ans=0x7f7f7f7f;
    if(depth[x]<depth[y])swap(x,y);
    while(depth[x]!=depth[y]){
        ans=min(ans,minval[x][lg[depth[x]-depth[y]]]);
        x=fa[x][lg[depth[x]-depth[y]]];
    }
    if(x==y)return ans;
    for(int i=lg[depth[x]];i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans,min(minval[x][i],minval[y][i]));
            x=fa[x][i];y=fa[y][i];
        }
    }
    ans=min(ans,min(minval[x][0],minval[y][0]));
    return ans;
}
int main(){
    memset(last,-1,sizeof(last));
    memset(depth,-1,sizeof(depth));
    memset(fa,-1,sizeof(fa));
    memset(minval,-1,sizeof(minval));
    cin>>n>>m;
    lg[0]=-1;
    for(int i=1;i<=n;i++)lg[i]=lg[i/2]+1;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        ed[cnt++]=(edge){a,b,c};
        //e[cnt++]=(edge){b,a,c};
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(ed,ed+cnt);
    for(int i=0;i<cnt;i++){
        x=find(ed[i].f);y=find(ed[i].t);
        if(x!=y)f[x]=y,addedge(ed[i].f,ed[i].t,ed[i].val),addedge(ed[i].t,ed[i].f,ed[i].val);
    }
    for(int i=1;i<=n;i++){
        if(depth[i]==-1){depth[i]=0;dfs(i);}
    }
    int q;
    cin>>q;
    while(q--){
        scanf("%d%d",&x,&y);
        cout<<lca(x,y)<<'\n';
    }
    return 0;
}