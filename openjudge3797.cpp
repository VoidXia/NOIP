#include<iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
  //  vector<int>v;
    cout<<n<<'=';
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            cout<<i;
            if(n!=0)cout<<'*';
        }
    }

    return 0;
}