#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    int ans=1<<31;
    cin>>n;
    int a,now=0;
    for(int i=0;i<n;i++){
        cin>>a;
        now+=a;
        if(ans<now)ans=now;
        if(now<0)now=0;
    }
    cout<<ans;

}