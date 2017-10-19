#include<iostream>
#include<algorithm>
#define mod 10007;
using namespace std;
int main(){
    int m,n;
    int f[2000010]={1};
    bool ok;
    cin>>m>>n;
    ok=n<(m/2);
    if(ok==1){
        for(int i=1;i<n;i++){
            f[i]=1;
            for(int j=i-1;j>=1;j--){
              f[j]=(f[j]+f[j-1])%mod;
             // cout<<f[j]<<' ';
            }
          //  cout<<"   "<<i<<'\n';
        }
        //cout<<'\n';
        for(int i=n;i<=m-n;i++){
            f[i]=1;
            for(int j=n-1;j>=1;j--){
                f[j]=(f[j]+f[j-1])%mod;
               // cout<<f[j]<<' ';
            }
            //cout<<"   "<<i<<'\n';
        }
       // cout<<'\n';
        for(int i=m-n+1;i<=m;i++){
            f[i]=1;
            for(int j=n-1;j>=i-m+n;j--){
                f[j]=(f[j]+f[j-1])%mod;
               // cout<<f[j]<<' ';
            }
         //   cout<<"   "<<i<<'\n';
        }
     //   cout<<'\n';
        cout<<f[n-1];
    }
    if(ok==0){
        for(int i=1;i<=m-n;i++){
            f[i]=1;
            for(int j=i-1;j>=1;j--){
              f[j]=(f[j]+f[j-1])%mod;
             // cout<<f[j]<<' ';
            }
           // cout<<"   "<<i<<'\n';
        }
        //cout<<'\n';
        for(int i=m-n+1;i<n;i++){
            f[i]=1;
            for(int j=i-1;j>=i-m+n;j--){
                f[j]=(f[j]+f[j-1])%mod;
               // cout<<f[j]<<' ';
                
            }
           // cout<<"   "<<i<<'\n';
        }
        //cout<<'\n';
        for(int i=n;i<m;i++){
            f[i]=1;
            for(int j=n-1;j>=i-m+n;j--){
                f[j]=(f[j]+f[j-1])%mod;
               // cout<<f[j]<<' ';
            }
         //  cout<<"   "<<i<<'\n';
        }
       // cout<<'\n';
        cout<<f[n-1];
    }
}
