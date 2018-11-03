#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ini(x,a) memset(x,a,sizeof(x));
const int maxn=1e5+10;
using namespace std;
struct node{
    int to,next;
}e[2*maxn];
int cnt=0;
int last[maxn];
int dep[maxn];
int f[maxn][22];
int lg[maxn];
int ma[maxn][22];
int mi[maxn][22];
int n,q;
int a[maxn];
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } 
    return x * f;
}
void init(){
    ini(last,-1);
    ini(ma,0);
    ini(mi,0xffffffff);
    lg[0]=-1;
    for(int i=1;i<=maxn;i++)lg[i]=lg[i/2]+1;
}
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    if(ma[x][0]==0){
    ma[x][0]=max(a[x],a[fa]);
    mi[x][0]=min(a[x],a[fa]);}
    for(int i=1;i<=lg[dep[x]];i++){
        f[x][i]=f[f[x][i-1]][i-1];
        if(ma[x][i]==0){
        ma[x][i]=max(ma[x][i-1],ma[f[x][i-1]][i-1]);
        mi[x][i]=min(mi[x][i-1],mi[f[x][i-1]][i-1]);}
    }
    for(int i=last[x];~i;i=e[i].next){
        if(e[i].to!=fa)dfs(e[i].to,x);
    }
}
int maxx=0,minn=1e9;
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y]){
        maxx=max(ma[x][lg[dep[x]-dep[y]]],maxx);
        minn=min(mi[x][lg[dep[x]-dep[y]]],minn);
        x=f[x][lg[dep[x]-dep[y]]];
    }
    if(x==y)return x;
    for(int i=lg[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]){
            maxx=max(ma[x][i],maxx);
            maxx=max(ma[y][i],maxx);
            minn=min(mi[x][i],minn);
            minn=min(mi[y][i],minn);
            //cout<<x<<' '<<y<<"A\n";
            //cout<<ma[x][i]<<' '<<mi[x][i]<<'\n';
            //cout<<ma[y][i]<<' '<<mi[y][i]<<'\n';
            x=f[x][i];
            y=f[y][i];
        }
    }
    int i=0;
    maxx=max(ma[x][i],maxx);
    maxx=max(ma[y][i],maxx);
    minn=min(mi[x][i],minn);
    minn=min(mi[y][i],minn);
    return f[x][0];
}
int main(){
    init();
    freopen("profit.in","r",stdin);
    freopen("profit.out","w",stdout);
    n=read();
    q=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<n;i++){
        int x,y;
        x=read();
        y=read();
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=last[1];~i;i=e[i].next){
        dfs(e[i].to,1);
    }
    int g,x,y;
    while(q--){
        maxx=0;minn=1e9;
        x=read();
        y=read();
        g=lca(x,y);
        printf("%d\n",(maxx-minn));
        //cout<<maxx<<' '<<minn<<' '<<g<<'\n';
    }
    fclose(stdout);
    return 0;
}