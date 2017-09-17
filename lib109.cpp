#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int fa[10000];
    for(int i=0;i<n;i++)
        fa[i]=i;
    for(int i=1;i<m;i++){
        int op,u,v;
        cin>>op>>u>>v;
        if(op==1)cout<<(fa[u]=fa[v]);
        if(op==0){
            for(int j=0;j<m;j++){
                if(fa[j]==fa[u])fa[j]=fa[v];
            }
        }
    }
}