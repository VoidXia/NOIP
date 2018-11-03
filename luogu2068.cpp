#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int c[maxn];
#define lowbit(x) (x&-x)
int n,m;
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=k;
    }
}
int que(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}
int main(){
    cin>>n>>m;
    char cc;
    int a,b;
    while(m--){
        cin>>cc;
        scanf("%d%d",&a,&b);
        if(cc=='x'){
            add(a,b);
        }
        else{
            cout<<(que(b)-que(a-1))<<'\n';
        }
    }
    return 0;
}