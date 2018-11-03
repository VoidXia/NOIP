#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

int st,ed;
int n,m;

struct edge{
    int to,next;
}e1[200010],e2[200010];

int cnt=1;
int last1[10010]={0},last2[10010]={0};
//memset(last1,0,sizeof(last1));
//memset(last2,0,sizeof(last2));

void addedge(int u,int v){
    e1[cnt].to=v;
    e1[cnt].next=last1[u];
    last1[u]=cnt;//正向
    e2[cnt].to=u;
    e2[cnt].next=last2[v];
    last2[v]=cnt; //逆向
    cnt++;
}

bool used[10010]={0};
//memset(us,0,sizeof(us));

bool check(int ch){
    for(int i=last1[ch];i;i=e1[i].next){
        //cout<<e1[i].to;
        //if(!used[e1[i].to]){cout<<e1[i].to<<"A\n";return 0;}
        if(!used[e1[i].to])return 0;
    }
    return 1;
}//

void bfs1(){
    queue<int> q;
    q.push(ed);
    while(!q.empty()){
        int temp=q.front();
        //cout<<temp<<'\n';
        q.pop();
        used[temp]=1;
        for(int i=last2[temp];i;i=e2[i].next){
            if(!used[e2[i].to]){
                //cout<<e2[i].to;
                q.push(e2[i].to);
                used[e2[i].to]=1;
                //cout<<e2[i].to<<used[e2[i].to]<<'\n';
            }
        }
        //cout<<"\n\n";
    }
}//逆向bfs，得出哪些点不符合

void bfs2(){//正向bfs
    queue<int> q;
    q.push(st);
    int dis[10010];
    memset(dis,-1,sizeof(dis));
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        //cout<<temp<<' '<<check(temp)<<'\n';
        if(!check(temp))continue;
        for(int i=last1[temp];i;i=e1[i].next){
            int v=e1[i].to;
            if(dis[v]==-1){
                dis[v]=dis[temp]+1;
                q.push(v);
                //cout<<v<<'v'<<dis[v]<<'\n';
                if(v==ed){cout<<dis[v]+1;return;}
            }
        }
    }
    cout<<-1;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y)addedge(x,y);//eliminate self circle
    }
    cin>>st>>ed;
    //cout<<'\n';
    bfs1();
    //for(int i=1;i<=n;i++)cout<<check(i)<<'\n';
    //cout<<check(2);
    if(!used[st]){cout<<-1;return 0;}
    bfs2();
    return 0;
}