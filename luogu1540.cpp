#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int a[1010];
    bool vis[1010];
    memset(vis,0,sizeof(vis));
    queue<int>q;
    cin>>m>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            q.push(a[i]);
            ans++;
            if(q.size()>m){
                vis[q.front()]=0;
                q.pop();
            }
        }
    }
    cout<<ans;
}