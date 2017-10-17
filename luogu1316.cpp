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
using namespace std;
int main(){
    
}