#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    if(b%a!=0){cout<<'0';return 0;}
    int c=b/a;
    int ans=0;
    for(int i=1;i<=floor(sqrt(c));i++){
        if(c%i==0&&gcd(c/i,i)==1)ans++/*,cout<<i<<' '<<c/i<<' '<<c/i/i<<'\n'*/;
    }
    ans*=2;
    cout<<ans;
    return 0;
}