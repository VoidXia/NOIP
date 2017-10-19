#include<iostream>
#include<algorithm>
using namespace std;
struct node{
  int t,f,h;
}v[110];
bool comp (const node& a,const node& b){
  return a.t<b.t;
}
int main(){
  int d,g;
  cin>>d>>g;
  for(int i=1;i<=g;i++){
    cin>>v[i].t>>v[i].f>>v[i].h;
  }
  sort(v+1,v+g+1,comp);
  
  int dp[2010][2010]={10};
  //dp[i][j] refers how long the cow could survive when getting the i garbage and the height was j;
  for(int i=1;i<=g;i++){
    for(int j=0;j<=d;j++){
      if(dp[i-1][j]>=v[i].t){
        if(j+v[i].h>=d){
          cout<<v[i].t;
          return 0;
        }
        dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i].f);
        dp[i][j+v[i].h]=max(dp[i][j+v[i].h],dp[i-1][j]);

      }
    }
  }
  int ans=0;
  for(int i=1;i<=g;i++){
    ans=max(ans,dp[i][0]);
  }
  cout<<ans;
  return 0;
}
