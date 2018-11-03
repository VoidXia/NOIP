#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ini(x,a) memset(x,a,sizeof(x));
const int maxn = 1e5+10;
using namespace std;
struct node{
    int to,next;
}e[2*maxn];//important!!!
int n,q;
int last[maxn];
int lg[maxn];
int f[maxn][22];
int dep[maxn];
void init(){
    lg[0]=-1;
    for(int i=1;i<=maxn;i++)lg[i]=lg[i/2]+1;//forgotten
    ini(last,-1);
}
int cnt=0;
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
/*
void dfs(int x,int fa){
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=1;i<=lg[dep[x]];i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=last[x];~i;i=e[i].next){
        if(e[i].to!=fa)dfs(e[i].to,x);
    }
}*/
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    //cout<<x<<' '<<depth[x]<<'\n';
    f[x][0]=fa;
    for(int i=1;i<=lg[dep[x]];i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(int i=last[x];~i;i=e[i].next){
        if(e[i].to!=fa)dfs(e[i].to,x);
    }
}
/*
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y])
        x=f[x][lg[dep[x]-dep[y]]];
    if(x==y)return x;
    for(int i=lg[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
*/
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
        while(dep[x]>dep[y]){
            //cout<<x<<'\n';
            //cout<<depth[x]<<' '<<depth[y]<<"A\n";
            x=f[x][lg[dep[x]-dep[y]]];
        }
        //cout<<x<<' '<<y<<'\n';
        //cout<<depth[x]<<' '<<depth[y]<<"B\n";
        if(x==y)return x;
        for(int k=lg[dep[x]];k>=0;k--){
            if(f[x][k]!=f[y][k]){
                x=f[x][k];y=f[y][k];
            }
        }
        return f[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    init();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=last[1];~i;i=e[i].next)dfs(e[i].to,1);
    //dfs(s,0);/*
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int p=lca(a,b);
        int q=lca(c,d);
        if(dep[q]>max(dep[a],dep[b])||dep[p]>max(dep[c],dep[d])){cout<<"N\n";continue;}
        if(dep[p]<=dep[q]){//changed!
            if(lca(a,q)==q||lca(b,q)==q)cout<<"Y\n";
                else cout<<"N\n";
        }
        else{
            if(lca(c,p)==p||lca(d,p)==p)cout<<"Y\n";
                else cout<<"N\n";
        }
    }/*
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }*/
    return 0;
}