#include<iostream>
using namespace std;
int main(){
    int l,s,t,m;
    int ro=0;
    cin>>l>>s>>t>>m;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        ro+=1&(1<<x);
    }
    int dp[]
}