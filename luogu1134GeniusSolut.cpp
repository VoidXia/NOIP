#include<iostream>
#include<algorithm>
//HARD!!!!
using namespace std;
int a[4]={6,8,4,2};
int main(){
    int n;
    cin>>n;
    int ans=1;
    while(n!=0){
        for(int t=2;t<=n%10;t++) if(t!=5) (ans*=t)%=10;
        n/=5;
        (ans*=a[n%4])%=10;
    }
    cout<<ans;
    return 0;
}