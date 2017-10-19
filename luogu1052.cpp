#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int l;
    cin>>l;
    int s,t,m;
    cin>>s>>t>>m;
    int a[1010]={0};
    int dp[301000];
    bool stone[301000];
    for(int i=1;i<=252000;i++)dp[i]=500000;
    for(int i=1;i<=m;i++)cin>>a[i];
    a[m+1]=l;
a[0]=0;
int k=0;
    for(int i=1;i<=m;i++){
        if(a[i]-a[i-1]>2520)//a[i+1]=(a[i+1]-a[i])%2520+a[i];
        k+=a[i]-a[i-1]-(a[i]-a[i-1])%2520;
        stone[a[i]-k]=1;
    }
    for(int i=1;i<=a[m+1];i++){
        for(int j=s;j<=t;j++){
            if(i>=j)
            dp[i]=min(dp[i],dp[i-j]+stone[i]);
        }
    }
    cout<<dp[a[m+1]];
    return 0;
}