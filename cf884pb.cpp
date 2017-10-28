#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    int nn=n;
    while(n--){
        int x;
        scanf("%d",&x);
        ans+=x;
    }
   // cout<<m<<' '<<ans<<' '<<nn<<'\n';
    if(m-ans==nn-1)cout<<"YES";
    else cout<<"NO";
    return 0;
}