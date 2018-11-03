#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
const int maxn = 500010;
using namespace std;
int n,m,s;
//vector<int >E[maxn];
struct node{
    int to,next;
}E[2*maxn];
int last[maxn];
int cnt=0;
int dep[maxn];
int f[maxn][21];
int lg[maxn];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    //cout<<x<<' '<<dep[x]<<'\n';
    f[x][0]=fa;
    for(int i=1;i<=lg[dep[x]];i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(int i=last[x];~i;i=E[i].next){
        if(E[i].to!=fa)dfs(E[i].to,x);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
        while(dep[x]>dep[y]){
            //cout<<x<<'\n';
            //cout<<dep[x]<<' '<<dep[y]<<"A\n";
            x=f[x][lg[dep[x]-dep[y]]];
        }
        //cout<<x<<' '<<y<<'\n';
        //cout<<dep[x]<<' '<<dep[y]<<"B\n";
        if(x==y)return x;
        for(int k=lg[dep[x]];k>=0;k--){
            if(f[x][k]!=f[y][k]){
                x=f[x][k];y=f[y][k];
            }
        }
        return f[x][0];
}
void addedge(int x,int y){
    E[cnt].to=y;
    E[cnt].next=last[x];
    last[x]=cnt++;
}
int main(){
    memset(last,-1,sizeof(last));
    cin>>n>>m;
    s=1;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    lg[0]=-1;
    for(int i=1;i<=maxn;i++)lg[i]=lg[i/2]+1;
    dep[0]=0;
    f[0][0]=0;
    //cout<<'\n';
    for(int i=last[s];~i;i=E[i].next){
        dfs(E[i].to,s);
    }
    //dfs(s,0);
    while(m--){
        int q1,q2,w1,w2;
        scanf("%d%d%d%d",&q1,&w1,&q2,&w2);
        if(dep[lca(q1,w1)]>dep[lca(q2,w2)]){
            swap(q1,q2);
            swap(w1,w2);
        }
        if((dep[lca(q1,w1)]>dep[q2]&&dep[lca(q1,w1)]>dep[w2])||(dep[lca(q2,w2)]>dep[q1]&&dep[lca(q2,w2)]>dep[w1]))
        {
            printf("N\n");
        }
        else{
            if(lca(q1,lca(q2,w2))==lca(q2,w2)||lca(w1,lca(q2,w2))==lca(q2,w2)){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }
    }
    return 0;
}