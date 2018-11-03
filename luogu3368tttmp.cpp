#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
const int maxn = 500050;
int c[maxn];
int n;
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=k;
        //cout<<i<<'\n';
    }
}
int query(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}
int main(){
    int m;
    cin>>n>>m;
    int x=0,y,z;
    int e;
    for(int i=1;i<=n;i++)y=x,scanf("%d",&x),add(i,x-y);
    while(m--){
        scanf("%d",&z);
        //cout<<z<<"gg\n";
        if(z==1){
            cin>>x>>y>>e;
            //cout<<x<<y<<e<<'\n';
            add(x,e);
            add(y+1,-e);
        }
        if(z==2){
            scanf("%d",&x);
            int y=query(x);
            cout<<y<<'\n';
        }
        //cout<<"good\n";
    }
    return 0;
}