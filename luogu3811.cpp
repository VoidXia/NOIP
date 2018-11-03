#include<bits/stdc++.h>
using namespace std;
int inv[3000010];
int n,p;
int main(){
    scanf("%d%d",&n,&p);
    inv[1]=1;
    cout<<inv[1]<<'\n';
    for(int i=2;i<=n;i++){
        inv[i]=((long long)(p-p/i)*inv[p%i])%p;
        cout<<inv[i]<<'\n';
    }
    return 0;
}