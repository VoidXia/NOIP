#include<bits/stdc++.h>
using namespace std;
#define maxn 100100
long long n,k,a[maxn],ti[maxn],cc[maxn],temp,ans[maxn],anss[maxn],it[maxn];
int cur=0;
queue<int>q;
void dfs(long long s){
    if(ti[s]!=-1)return;
    ti[s]=cur;
    it[cur]=s;
    cur++;
    dfs(a[s]);
    cc[s]=cur;
    q.push(s);
    return;
}
void get(long long s){
    long long t;
    while(!q.empty()){
        t=q.front();
        q.pop();
        ans[t]=it[(ti[t]+temp)%cur];
    }
}
int main(){
    memset(ti,-1,sizeof(ti));
    cin>>n>>k;
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]),ans[i]=i;
    for(long long i=1;i<=n;i++)
        if(ti[i]==-1){cur=0;dfs(i);temp=k%cur;get(i);}
    for(long long i=1;i<=n;i++)anss[ans[i]]=i;
    for(long long i=1;i<=n;i++)cout<<anss[i]<<' ';
    return 0;
}