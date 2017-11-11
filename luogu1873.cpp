#include<iostream>
#include<cstdio>
using namespace std;
long long  n,m;
long long  a[1000010];
bool judge(long long  mid){
    long long  ans=0;
    for(long long  i=1;i<=n;i++){
        if(a[i]>mid)ans+=a[i]-mid;
    }
    return ans>m;
}

int main(){
    cin>>n>>m;
    long long  mx=0;
    for(long long  i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);}
    long long  l=0,r=mx;
    while(l+1<r){
        long long  mid=(l+r)/2;
        if(judge(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}