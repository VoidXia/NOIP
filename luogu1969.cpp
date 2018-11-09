#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int now,last=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>now;
        if(now>last)ans+=(now-last);
        last=now;
    }
    cout<<ans;
}