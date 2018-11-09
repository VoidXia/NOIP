#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int main(){
    int m,n;
    int a[maxn],b[maxn];
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    sort(b+1,b+n+1);
    int idx;
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    idx=1;
    for(int i=1;i<=m;i++){
        idx=upper_bound(b+idx,b+n+1,a[i])-b;
        while(vis[idx]==1)idx++;
        if(idx>n){cout<<0;return 0;}
        vis[idx]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0)ans+=b[i];
    }
    cout<<ans;
    return 0;
}