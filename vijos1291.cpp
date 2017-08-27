#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n,m,a[10000]={0},b[10000]={0},loc,ans;
        ios::sync_with_stdio(false);
        cin>>n>>m;
        ans=m;
        for(int i=0;i<=n-1;i++)cin>>a[i];
        for(int i=0;i<=m-1;i++)cin>>b[i];
        sort(b,b+m);
        for(int i=0;i<=n-1;i++){
        loc=lower_bound(b,b+m,a[i])-b;
        loc-=1;
        if((loc>=0)&&(loc<m)&&(b[loc]!=-1000)&&(b[loc]!=0))ans-=1,b[loc]=-1000,sort(b,b+m);
        }
        cout<<ans<<endl;
        return 0;
}
