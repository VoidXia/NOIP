#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ini(x,a) memset(x,a,sizeof(x))
int n,m,p,k;
const int maxn = 1010;
#define inf 0x7f7f7f7f
struct edge{
    int to,next,val;
}e[300000];
inline int getpos(int x,int y,int z){
    return n*m*z+(x-1)*n+y;
}
inline void decoded(int a){
    int x,y,z;
    a-=1;
    z=a/(m*n);
    a%=(m*n);
    x=(a/n)+1;
    y=a%n+1;
    cout<<x<<' '<<y<<' '<<z<<'\n';
}
inline int read(){
    int x=0,a=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')a=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=10*x+c-'0';c=getchar();}
    return x*a;
}
int last[300000];
int cnt=0;
void addedge(int x,int y,int val){
    e[cnt].to=y;
    e[cnt].next=last[x];
    e[cnt].val=val;
    //printf("adding %d %d at %d\n",x,y,cnt);
    last[x]=cnt++;

}
int mape[15][15][15][15];
struct node{
    int idx,dis;
};
bool operator <(const node &a,const node &b){
    return a.dis>b.dis;
}
int main(){
    ini(last,-1);
    ini(mape,-1);
    n=read();m=read();p=read();k=read();
    int x1,y1,x2,y2,g,q;
    while(k--){
        x1=read();y1=read();x2=read();y2=read();g=read();
        mape[x1][y1][x2][y2]=g;
        mape[x2][y2][x1][y1]=g;
    }
    int s=read();
    for(int i=1;i<=s;i++){
        x1=read();y1=read();q=read();
        for(int j=0;j<(1<<(s-1));j++){
            int t1,t2;
            t1=((j>>(q-1))<<(q))+(1<<(q-1))+j%((int)pow(10,q-1));
            t2=((j>>(q-1))<<(q))+j%((int)pow(10,q-1));
            addedge(getpos(x1,y1,t2),getpos(x1,y1,t1),0);
            //printf("* %d %d %d to %d %d %d layers\n",x1,y1,t2,x1,y1,t1);
        }
    }
    {
    for(int k=1;k<(1<<s);k++){
        int kk=k;
        for(int r=1;r<=s;r++){
            if((kk&1)==1){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if((mape[i][j][i+1][j]==r)&&(i+1<=n)){
                            addedge(getpos(i,j,k),getpos(i+1,j,k),1);
                            addedge(getpos(i+1,j,k),getpos(i,j,k),1);
                            //printf("%d %d %d to %d %d %d samebi\n",i,j,k,i+1,j,k);
                        }
                        if((mape[i][j][i][j+1]==r)&&(j+1<=m)){
                            addedge(getpos(i,j,k),getpos(i,j+1,k),1);
                            addedge(getpos(i,j+1,k),getpos(i,j,k),1);
                            //printf("%d %d %d to %d %d %d samebi\n",i,j,k,i,j+1,k);
                        }
                    }
                }
            }
            kk>>=1;
        }   
    }
    for(int k=0;k<(1<<s);k++)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mape[i][j][i+1][j]==-1&&i+1<=n){
                    addedge(getpos(i,j,k),getpos(i+1,j,k),1);
                    addedge(getpos(i+1,j,k),getpos(i,j,k),1);
                    //printf("%d %d %d to %d %d %d samebi\n",i,j,k,i+1,j,k);
                }
                if(mape[i][j][i][j+1]==-1&&j+1<=m){
                    addedge(getpos(i,j,k),getpos(i,j+1,k),1);
                    addedge(getpos(i,j+1,k),getpos(i,j,k),1);
                    //printf("%d %d %d to %d %d %d samebi\n",i,j,k,i,j+1,k);
                }
            }
        } 
    }
    /*
    priority_queue<node>sb;
    bool vis[300000];
    int dis[300000];
    ini(dis,inf);
    dis[1]=0;
    node t,temp;
    temp.idx=1;
    temp.dis=0;
    sb.push(temp);
    vis[1]=1;
    bool flag=0;
    int destination=getpos(n,m,(1<<s)-1);
    while(!sb.empty()){
        t=sb.top();
        //cout<<"NOWLIVE";
        //decoded(t.idx);
        sb.pop();
        //decoded(t.idx);
        if(t.idx==destination){
            cout<<dis[t.idx];
            flag=1;
            break;
        }
        //decoded(t.idx);
        //cout<<dis[t.idx]<<' '<<t.dis<<'\n';
        //if(dis[t.idx]!=t.dis)continue;
        //decoded(t.idx);
        //cout<<last[t.idx]<<'\n';
        for(int i=last[t.idx];~i;i=e[i].next){
            int to=e[i].to;
            //decoded(to);cout<<t.idx<<' '<<to<<' '<<i<<"to\n";
            if(dis[t.idx]+e[i].val<dis[to]&&vis[to]==0){
                dis[to]=dis[t.idx]+e[i].val;
                temp.idx=to;
                temp.dis=dis[to];
                sb.push(temp);
                vis[to]=1;
            }
        }
    }
    if(flag==0)cout<<-1<<'\n';
    //cout<<n<<' '<<m<<' '<<(1<<s)-1<<'\n';
    //decoded(getpos(n,m,(1<<s)-1));
    //cout<<n<<m<<(1<<s)-1<<'\n';
    //cout<<getpos(n,m,(1<<s)-1)<<' '<<aa<<' '<<bb<<' '<<cc<<'\n';*/
    int dis[300000];
    bool vis[300000];
    int destination=getpos(n,m,(1<<s)-1);
    ini(dis,inf);
    ini(vis,1);
    dis[1]=0;
    queue<int>qq;
    qq.push(1);
    vis[1]=0;
    while(!qq.empty()){
        int u=qq.front();
        qq.pop();
        //cout<<u<<'\n';
        vis[u]=1;
        for(int i=last[u];~i;i=e[i].next){
            int v=e[i].to;
            //cout<<v<<' '<<vis[v]<<'\n';
            if(dis[u]+e[i].val<dis[v]){
                dis[v]=dis[u]+e[i].val;
                //cout<<vis[v]<<'\n';
                if(vis[v]){
                    qq.push(v);
                    //cout<<qq.size()<<"K\n";
                    vis[v]=0;
                }
            }
        }
    }
    if(dis[destination]==inf)dis[destination]=-1;
    cout<<dis[destination];
    return 0;
}