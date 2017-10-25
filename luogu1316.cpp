/*#include<iostream>
#include<algorithm>
using namespace std;
int a[100010]={0};
int x,y;
bool judge(int q){
    int cur=1,ans=0;
    for(int i=2;i<=x;i++){
        if(a[i]-a[cur]<q)ans++; else cur=i;
    }
    return ans<y;
}
int main(){

    cin>>x>>y;
    y=x-y;
    for(int i=1;i<=x;i++)cin>>a[i];
    sort(a,a+x+1);
   //     for(int i=1;i<=x;i++)cout<<a[i]<<'\n';
    int l=0,r=a[x]-a[1];
    while(l+1<r){
        int u=(l+r)/2;
        if(judge(u))l=u+1;else r=u-1;
    }
    cout<<l;
  //  for(int i=1;i<=a[x]-a[1];i++){
    //    cout<<judge(i);
    //}


}*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,b;
int a[100010];
bool check(int x){
    int prev=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]-prev<x)ans++;
        else prev=a[i];
    }
    return ans<b;
}
int main(){

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    b=n-b;
    int l=0,r=a[n]-a[1];
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid+1;
    }
    cout<<l;
    return 0;
}