#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
struct node{int idx,val;}b[maxn];
bool operator < (const node &a,const node &b){return a.val<b.val;}
int a[maxn],n;
node ma,mi;
int maa,mii;
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=(node){i,a[i]};
    }
    sort(b+1,b+n+1);
    ma=b[n];mi=b[1];
    mii=0x7f7f7f7f;
    maa=-mii;
    for(int i=1;i<=ma.idx;i++)mii=min(mii,a[i]);ans=ma.val-mii;
    for(int i=mi.idx;i<=n;i++)maa=max(maa,a[i]);ans=max(ans,maa-mi.val);
    cout<<ans;
    return 0;
}