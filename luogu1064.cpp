#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[50010]={0};
    int b[50010]={0};
    int a1[50010]={0};
    int a2[50010]={0};
    bool flg[50010]={0};
    for(int i=1;i<=m;i++){
        int c;
        scanf("%d%d%d",&a[i],&b[i],&c);
                b[i]*=a[i];
        if(c){if(a1[c])a2[c]=i;
        else a1[c]=i;
        flg[i]=1;
       // a[i]=0;
       // b[i]=0;
        //cout<<c<<' '<<b[a1[c]]<<' '<<b[a2[c]]<<'\n';
        }
        

        
    }
   // for(int i=1;i<=m;i++)cout<<a[i]<<' '<<b[i]<<' '<<a1[i]<<' '<<a2[i]<<'\n';
    int dp[50010];
    for(int i=1;i<=m;i++){
        if(flg[i])continue;//附件不能选
        for(int j=n;j>=a[i]&&a[i]!=0;j--){
            dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
            if(j>=a[i]+a[a1[i]]){
                dp[j]=max(dp[j],dp[j-a[i]-a[a1[i]]]+b[i]+b[a1[i]]);
            }
            if(j>=a[i]+a[a2[i]]){
                dp[j]=max(dp[j],dp[j-a[i]-a[a2[i]]]+b[i]+b[a2[i]]);
            }
            if(j>=a[i]+a[a1[i]]+a[a2[i]]){
                dp[j]=max(dp[j],dp[j-a[i]-a[a1[i]]-a[a2[i]]]+b[i]+b[a1[i]]+b[a2[i]]);
            }
            
        }
     //   cout<<dp[n]<<'\n';
    }
    cout<<dp[n];
    return 0;
}