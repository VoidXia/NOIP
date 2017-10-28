#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
typedef long long ll;
ll bi[100010];
ll n;
struct one{
    ll x,y;
}c[100010];
bool cmp(const one& x,const one& y){
    return x.x<y.x;
}
void add(ll i,ll x){
    while(i<=n){
        bi[i]+=x;
        i+=lowbit(i);
    }
}
ll sum(ll x){
    ll ans=0;
    while(x>0){
        ans+=bi[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin>>n;
    ll a[100010],aa[100010];
    ll b[100010],bb[100010];
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        aa[i]=a[i];
        //scanf("%d",&c[i].x);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        bb[i]=b[i];
       // cout<<bb[i];
       //scanf("%d",&c[i].y);
    }
    //sort(c+1,c+n+1,cmp);
    sort(bb+1,bb+n+1);
    //cout<<bb[3];
    sort(aa+1,aa+n+1);
    for(ll i=1;i<=n;i++){
        a[i]=upper_bound(aa+1,aa+1+n,a[i])-aa-1;
        b[i]=upper_bound(bb+1,bb+n+1,b[i])-bb-1;
        //cout<<a[i]<<' '<<b[i]<<'\n';
        c[i].x=a[i];
        c[i].y=b[i];
     //   cout<<a[i]<<' '<<b[i]<<'\n';
    }
    sort(c+1,c+n+1,cmp);
    ll d[100010];
    for(ll i=1;i<=n;i++){
        d[i-1]=c[i].y;
     //   cout<<d[i-1];
    }
   // ll bi[100010];
   ll ans=0;
    for(ll i=0;i<n;i++){
        ans=(i-sum(d[i])+ans)%99999997;
        add(d[i],1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;



}