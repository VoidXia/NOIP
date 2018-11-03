#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#define inf 0x7f7f7f7f
using namespace std;

int t,c,st,ed;

struct edge{
    int to,next,val;
}e[20210];

int cnt=1;
int last[5510]={0};

void addedge(int s,int v,int va){
    e[cnt].to=v;
    e[cnt].val=va;
    e[cnt].next=last[s];
    last[s]=cnt;
    cnt++;
}
struct node{
    int d,n;
};

bool operator < (const node &a,const node &b){
    return a.d>b.d;
}

int main(){
    priority_queue<node> q;
    //queue<int>q;
    //set<int>q;
    cin>>t>>c>>st>>ed;
    for(int i=1;i<=c;i++){
        int x,y,z;
        cin>>x>>y>>z;
        addedge(x,y,z);
        addedge(y,x,z);
    }
    int dis[5510];
    memset(dis,inf,sizeof(dis));
    dis[st]=0;
    node o;
    o.d=0;
    o.n=st;
    q.push(o);
    //int now=st;
    //int cn=1;
    /*while(dis[ed]==0x7f7f7f7f&&!q.empty()){
        for(int i=last[now];i;i=e[i].next){
            int v=e[i].to;
            dis[v]=min(dis[now]+e[i].val,dis[v]);
        }
        now=t+1;
        for(int i=1;i<=t;i++){
            if(dis[i]!=0x7f7f7f7f&&!q.count(i)&&dis[i]<dis[now])now=i;
        }
        q.insert(now);
    }*/
    while(1){
        o=q.top();
        q.pop();
        if(o.n==ed)break;
        if(dis[o.n]!=o.d)continue;//节点已更新，目前的元素作废
        for(int i=last[o.n];i;i=e[i].next){
            int v=e[i].to;
            if(dis[v]>dis[o.n]+e[i].val){
                dis[v]=dis[o.n]+e[i].val;
                node temp;
                temp.n=v;
                temp.d=dis[v];
                q.push(temp);
            }
        }
    }
    cout<<dis[ed];
    return 0;
}