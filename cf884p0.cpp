#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    int n,t;
    int ans=0;
    cin>>n>>t;
    while(n--){
        ans++;
        int w;
        scanf("%d",&w);
        t-=86400-w;
        if(t<=0)break;
    }
    cout<<ans;
    return 0;
}