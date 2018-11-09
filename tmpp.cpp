#include<bits/stdc++.h>
using namespace std;
#define maxn 150010
#define ini(x,a) memset(x,a,sizeof(x))
int n,a,b,c;
struct edge{int to,next;}e[maxn*6];
int last[maxn*6],cnt=0;
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
    e[cnt].to=x;
    e[cnt].next=last[y];
    last[y]=cnt++;
}
void init(){
    ini(last,-1);
}
struct node{int idx,val;}aa[maxn];
bool operator <(const node &a,const node &b){return a.idx<b.idx;}
int cnt1=0;
bool vis[maxn];
int ans[maxn];
void bfs(){
    ini(vis,0);
    int s=1,to;
    queue<int>q;
    q.push(s);
    ans[s]=0;
    vis[s]=1;
    while(!q.empty()){
        s=q.front();
        //cout<<s<<"gg\n";
        q.pop();
        aa[cnt1].idx=s;
        aa[cnt1++].val=ans[s];
        for(int i=last[s];~i;i=e[i].next){
            to=e[i].to;
            //cout<<to<<"to\n";
            if(vis[to]==0){
                vis[to]=1;
                q.push(to);
                ans[to]=ans[s]+1;
            }
        }
    }
}
int main(){
    freopen("anomalies.in","r",stdin);freopen("anomalies.out","w",stdout);
    init();
    cin>>n;
    for(int i=1;i<=n;i++){scanf("%d%d%d",&a,&b,&c);
    addedge(a,b);addedge(b,c);addedge(c,a);}
    bfs();
    sort(aa,aa+cnt1);
    for(int i=0;i<cnt1;i++)cout<<aa[i].idx<<' '<<aa[i].val<<'\n';
    fclose(stdin);fclose(stdout);
}