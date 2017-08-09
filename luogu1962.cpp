#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef longlong ll;
ll DP(ll x){
    if(x==1||x==2)return 1;
    if(dp[i]<>0)return dp[i];
    return dp[i]=DP(i-1)+DP(i-2);
}

int main(){
    ll dp[i]={1,1},n;
    cin>>n;
    cout<<DP(n)<<endl;
    return 0;

    
}