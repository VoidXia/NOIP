#include<iostream>
using namespace std;
int fa[10010]={0};
int n,m;
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){fa[i]=i;}
    for(int i=1;i<=m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            if(fa[x]!=fa[y]&&find(x)!=find(y))
            fa[find(x)]=y;
        }
        if(z==2){
            if(fa[x]==fa[y]||find(x)==find(y))cout<<'Y'<<'\n';
            else cout<<'N'<<'\n';
        }
    }
    return 0;
}