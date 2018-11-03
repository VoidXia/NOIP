#include<iostream>
#include<algorithm>
using namespace std;
int L,n,m;
int a[50010]={0};
int l=0,r=0;
bool judge(int s){
    int cnt=0;
    int now=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]-a[now]<s)cnt++;else now=i;
    }
    return cnt<=m;
}
int main(){
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],r=max(a[i]-a[i-1],r);
    a[n+1]=L;
    r=max(r,L-a[n]);
    
    //cout<<l<<' '<<r<<'\n';
    while(l<r){
        int mid=(l+r+1)/2;
        if(judge(mid))l=mid;else r=mid-1;
        //cout<<l<<' '<<r<<'\n';
    }
    cout<<l;
    return 0;
}
//.二分答案