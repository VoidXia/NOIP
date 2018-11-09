#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n,sta,m;
int cnt=0;
int last[maxn*2];
const int mod = 1000000007;
struct edge{
    int to,next;
}e[maxn*2];
void adde(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
int fa[maxn];
long dd[maxn];
long long kk[maxn];
long dfs(int s){
    int l=0,r=0;
    int te=0;
    bool flg=0;
    if(dd[s]!=-1)return dd[s];
    int ans=1;
    for(int i=last[s];~i;i=e[i].next){
        int to=e[i].to;
        if(to!=fa[s]){
            //cout<<s<<'v'<<to<<'s'<<fa[s]<<'\n';
            fa[to]=s;
            dd[to]=dfs(to);
            ans+=dd[to];
            //cout<<s<<' '<<to<<' '<<dd[to]<<' '<<l<<' '<<r<<"ll\n";
            if(flg==0)l=dd[to],flg=1;else r=dd[to];
        }
    }
    //cout<<s<<' '<<l<<' '<<r<<' '<<ans<<'\n';
    te=0;
    te=l*(r+1)+r*(l+1);
    te%=mod;
    te+=l+r+1;
    kk[s]=te%mod;
    dd[s]=ans;
    //cout<<s<<'W'<<ans<<'\n';
    return ans;
}
int main(){
    memset(kk,0,sizeof(kk));
    memset(dd,-1,sizeof(dd));
    memset(last,-1,sizeof(last));
    memset(fa,-1,sizeof(fa));
    scanf("%d%d%d",&n,&sta,&m);
    int a,b;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    fa[sta]=-1;
    dd[sta]=dfs(sta);
    long long p;
    while(m--){
        scanf("%lld",&p);
        printf("%lld\n",kk[p]%mod);
    }
    return 0;
}