#include<bits/stdc++.h>
using namespace std;
#define N 30010
struct node{int u,v,n;}a[N];
bool operator <(const node &a,const node &b){
    return a.v<b.v;
}
int n,m;
bool vis[N]={0};
int main(){
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].n;
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        int ans=0;
        for(int j=a[i].u;j<=a[i].v;j++)if(vis[j]==1)ans++;
        ans=a[i].n-ans;
        //cout<<i<<' '<<ans<<'\n';
        for(int j=a[i].v;j>=a[i].u&&ans>0;j--){
            if(vis[j]==0){
                vis[j]=1;
                cnt++;
                //cout<<j<<"vis\n";
                ans--;
            }
            //if(ans==0)break;
        }
    }
    cout<<cnt<<'\n';
}