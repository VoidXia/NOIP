#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1e6+10;
int n,m;
bool vis[maxn];
#define mod 100003
struct edge{
    int to,next;
}e[2*maxn];
int last[maxn];
int cnt=0;
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
int main(){
    memset(last,-1,sizeof(last));
    cin>>n>>m;
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    int a[maxn];
    //memset(a,0,sizeof(a));
    queue<int>q;
    a[1]=1;
    int dep[maxn];
    //memset(dep,0,sizeof(dep));
    q.push(1);
    //bool vis[maxn];
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    dep[1]=0;
    //cout<<q.size()<<'\n';

    while(!q.empty()){
        int t=q.front();
        //cout<<q.front();
        q.pop();
        //cout<<t<<'\n';
        for(int i=last[t];~i;i=e[i].next){
            int r=e[i].to;
            //cout<<r<<'\n';
            if(vis[r]==0){vis[r]=1;dep[r]=dep[t]+1;q.push(r);}
            //cout<<dep[r]<<' '<<dep[t]<<' '<<r<<' '<<t<<'\n';
            if(dep[r]==dep[t]+1)a[r]=(a[r]+a[t])%mod;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
    return 0;
}