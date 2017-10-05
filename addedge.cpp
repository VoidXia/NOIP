#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
struct Node{
    int u,w;
};
inline Node make_Node(int x,int y){
    Node cur;cur.u=x;cur.w=y;return cur;
}
vector<Node>G[N];
inline void addedge(int u,int v,int w){
    //在u，v之间加边权为w的边 
    //无向边 
    G[u].push_back(make_Node(v,w));
    //如果是有向边，删除下面一句 
    G[v].push_back(make_Node(u,w));
}

for(int i=0;i<G[u].size();i++){
    //枚举和这个点相连的所有边 
    int v=G[u][i].u;
    int w=G[u][i].w;
}



//邻接表
struct Edge{
    int u,v,next;
}G[N];
int head[N],tot=0;
inline void addedge(int u,int v){
    G[++tot].u=u;G[tot].v=v;G[tot].next=head[u];head[u]=tot;
    G[++tot].u=v;G[tot].v=u;G[tot].next=head[v];head[v]=tot;
}

for(int i=head[u];i;i=G[i].next){
    int v=G[i].v;
    
}

//BFS
struct Edge{
    int u,v,next;
}G[N];
int head[N],tot=0;
inline void addedge(int u,int v){
    G[++tot].u=u;G[tot].v=v;G[tot].next=head[u];head[u]=tot;
    G[++tot].u=v;G[tot].v=u;G[tot].next=head[v];head[v]=tot;
}
int vis[N];
void dfs(int u,int f){
    vis[u]=1;
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].v;
        if(vis[v])continue;
        dfs(v,u); 
    }
} 
void dfs(int u,int f){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==f)continue;
        dfs(v,u);
    }
}
queue<int> q;
int fa[N];
void bfs(int s){
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=G[i].next){
            int v=G[i].v;
            if(v==fa[u])continue;
            fa[v]=u;q.push(v);
        }
    }
}


//dfs

void dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].v;
        if(vis[v])continue;
        dfs(v);
    }
}

//bfs
void bfs(int s){
    q.push(s);vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=G[i].next){
            int v=G[i].v;if(vis[v])continue;
            q.push(v);
        }
    }
}