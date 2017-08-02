#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,a[2000],b[2000],i,j;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
  //  for (i=1;i<=n;i++)cout<<a[i]<<' ';
    sort (a+1,a+n+1);
  //  for (i=1;i<=n;i++)cout<<a[i]<<' ';
    for (i=1;i<=n;i++) {
        for(j=n;j>=1;j--){
            if(b[i]==a[j]){
                cout<<n-j+1<<' ';
                j=n+1;
                i=i+1;
            }
        }
    }
    
}