#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ss{
    int a,b;
}a[5010];
bool cmp(ss a,ss b){return a.a>b.a;}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<a[i].a<<' '<<a[i].b<<'\n';
    int dp[5010];
    int len=1;
    dp[1]=a[1].b;
    fill(dp+1,dp+n+1,1<<30);
    for(int i=1;i<=n;i++){
        if(a[i].b>dp[len])dp[++len]=a[i].b;
        else *lower_bound(dp+1,dp+n+1,a[i].b)=a[i].b;
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    cout<<len;
    return 0;
}