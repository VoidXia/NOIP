#include<iostream>
#include<algorithm>
#include<string>
int n,m;    int a[100010]={0};
int maxn=0;
using namespace std;
bool judge(int x){
    int cur=0;
    int ans=0;
    if(x<maxn)return 0;
  //  cout<<x<<"  ";
    for(int i=1;i<=n;i++){
        if(a[i]-a[cur]>x)cur=i-1,ans++;
   //     cout<<i<<' ';
    }
  //  cout<<ans;
  //  cout<<'\n';
    return ans+1<=m;


}
int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        int y;
        cin>>y;
        a[i]+=a[i-1];
        a[i]+=y;
        maxn=max(y,maxn);
    }
  //  cout<<a[n]<<'\n';
    int l=0,r=a[n];
    while(l+1<r){
        int x=(l+r)/2;
        if(judge(x)==0)l=x;else r=x;
        //cout<<l<<' '<<r<<'\n';
    }
    cout<<r<<'\n';
   // for(int i=1;i<=a[n];i++)cout<<judge(i)<<' ';
    return 0;

}