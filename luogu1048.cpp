//lg1616
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long t,m,i,j;
    long long v[100000],k[100000],a[100000]={0};
    cin>>t>>m;
    for (i=1;i<=m;i++)cin>>v[i]>>k[i];
  //  memset(a,0,sizeof(a));
    for (i=1;i<=m;i++){
        for (j=0;j<=t;j++){
            //for (j=t;j>=0;j--){lg1048
            if (j>=v[i]){
            if (a[j]<a[j-v[i]]+k[i])a[j]=a[j-v[i]]+k[i];
           // cout<<' '<<j<<' '<<a[j]<<' ';
            }
        }
    }
    //for (i=t;i>=1;i--)if (a[i]>0){
        cout<<a[t]<<endl;
    //    break;
 //   }
    return 0;
}