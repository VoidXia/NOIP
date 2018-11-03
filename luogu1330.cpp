#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ini(x,a) memset(x,a,sizeof(x));
const int maxn = 10510;
const int maxm = 100510;
using namespace std;
int n,m;
struct edge{
    int to,next;
}e[maxm];
int last[maxn];
int cnt=0;
void added(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
queue<int>q;
int vis[maxn];
bool val[maxn];
int bfs(){
    int countera=0;
    int counterb=1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=last[t];~i;i=e[i].next){
            int to=e[i].to;
            if(vis[to]==1){
                if(val[t]==val[to])return 0;
                continue;
            }
            vis[to]=1;
            q.push(to);
            //cout<<t<<' '<<to<<'\n';
            val[to]=(val[t]==1)?0:1; 
            //cout<<val[t]<<' '<<val[to]<<"A\n";
            if(val[to]==0)countera++;  
            if(val[to]==1)counterb++;        
        }
    }
    return min(countera,counterb);
}
bool connected[maxn];
int main(){
    ini(last,-1);
    ini(vis,0);
    ini(connected,0);
    cin>>n>>m;
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        added(x,y);
        added(y,x);
        connected[x]=1;
        connected[y]=1;
    }
    //cout<<'\n';
    int ans=0;
    int temp=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&connected[i]==1){
            q.push(i);
            vis[i]=1;
            val[i]=1;
            temp=bfs();
            //cout<<i<<' '<<temp<<"T\n\n\n";
            //cout<<i<<' '<<temp<<'\n';
            if(temp==0){ans=0;break;}
            ans+=temp;
            //cout<<ans<<"S\n";
        }
    }
    if(ans==0){cout<<"Impossible";return 0;}
    cout<<ans;
    return 0;
}