#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<cstdlib>
#include<cstdio>
using namespace std;

int t,c,st,ed;

struct edge{
    int to,next,val;
}e[20010];

int cnt=1;
int last[5510]={0};

void addedge(int s,int v,int va){
    e[cnt].to=v;
    e[cnt].val=va;
    e[cnt].next=last[s];
    last[s]=cnt;
    cnt++;
}
int main(){
    //priority_queue<int,vector<int>,greater<int> > q;
    //queue<int>q;
    set<int>q;
    cin>>t>>c>>st>>ed;
    for(int i=1;i<=c;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    int dis[3510];
    memset(dis,0x7f7f7f7f,sizeof(dis));
    dis[st]=0;
    q.insert(st);
    int now=st;
    dis[t+1]=0x7f7f7f7f;
    while(!q.count(ed)){
        for(int i=last[now];i;i=e[i].next){
            int v=e[i].to;
            dis[v]=min(dis[now]+e[i].val,dis[v]);
        }
        now=t+1;
        for(int i=1;i<=t;i++){
            if(dis[i]!=0x7f7f7f7f&&!q.count(i)&&dis[i]<dis[now])now=i;
        }
        q.insert(now);
    }
    cout<<dis[ed];
    return 0;
}