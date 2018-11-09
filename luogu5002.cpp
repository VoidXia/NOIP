#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
#define ini(x,a) memset(x,a,sizeof(x))
int n,m;
int last[maxn*2];
struct edge{
    int to,next;
}e[maxn*2];
int cnt=0;
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
int fa[maxn][25];
int lg[maxn],depth[maxn];
void dfs(int s){
    for(int i=1;i<=lg[depth[s]];i++){
        fa[s][i]=fa[fa[s][i-1]][i-1];
    }
    for(int i=last[s];~i;i=e[i].next){
        int to=e[i].to;
        if(fa[s][0]!=to){
            fa[to][0]=s;
            depth[to]=depth[s]+1;
            dfs(to);
        }
    }
}

int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    while(depth[x]>depth[y])x=fa[x][lg[depth[x]-depth[y]]];
    if(x!=y){
        for(int i=lg[depth[x]];i>=0;i--){
            if(fa[x][i]!=fa[y][i]){x=fa[x][i];y=fa[x][i];}
        }
        x=fa[x][0];y=fa[y][0];
    }
    return x;
}
int ans[maxn];
void init(){
    ini(last,-1);
    lg[0]=-1;
    for(int i=1;i<=n;i++)lg[i]=lg[i/2]+1;
    ini(depth,-1);
    ini(ans,0);
}
int a,b,ll,len,la,lb,d;
int t[maxn];
int main(){
    cin>>n>>m;init();
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        addedge(a,b);addedge(b,a);
    }
    depth[1]=0;
    dfs(1);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]);
    while(m--){
        scanf("%d%d",&a,&b);
        ll=lca(a,b);
        //cout<<ll<<"ll\n";
        len=-(depth[ll]-depth[a]+depth[ll]-depth[b]);
        //cout<<len<<"len\n";
        for(int i=1;i<=n;i++){
            if(i!=a&&i!=b){
                la=lca(a,i);lb=lca(b,i);
                //cout<<i<<' '<<la<<' '<<lb<<"ii\n";
                if(la!=lb&&la==ll&&lb==i){
                    //cout<<"this is on the route\n";
                    d=depth[b]-depth[i];
                    if(t[i]==(len-d))ans[i]++;
                }
                if(la!=lb&&lb==ll&&la==i){
                    //cout<<"this is on the route\n";
                    d=depth[a]-depth[i];
                    if(d==t[i])ans[i]++;
                }
                if(i==ll){
                    //cout<<"this is on the route\n";
                    d=depth[a]-depth[i];
                    if(d==t[i])ans[i]++;
                }
            }
            if(i==a&&t[i]==0)ans[i]++;
            else if(i==b&&t[i]==len)ans[i]++;
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}