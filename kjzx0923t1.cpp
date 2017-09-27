/*#include<iostream>
using namespace std;

int main(){
    int n,k;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    k--;n--;
    long long ans1=1,ans2=1,ans;
    for(int i=1;i<=n-k;i++)ans1*=i;
    for(int i=k+1;i<=n;i++)ans2*=i;
    ans=ans2/ans1;
    cout<<ans1<<' '<<ans2<<' '<<ans;
    return 0;
}
http://blog.csdn.net/u010582475/article/details/47707739
*/


/*
#include<iostream>
#define ll long long
#define mod 10007;
using namespace std;
int damn(ll i,ll j){
    if(i==j||j==1)return 1;
    return (damn(i-1,j-1)+damn(i-1,j))%mod;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<damn(m,n);
}*/

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