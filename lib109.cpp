#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m,ans=0;
    cin>>n>>m;
    int fa[10000];
    for(int i=0;i<n;i++)
        fa[i]=i;
    for(int i=0;i<m;i++){
        int op,u,v;
        cin>>op>>u>>v;
        //cout<<op<<u<<v<<' ';
        if(op==1)ans=(ans<<1)+((fa[u]==fa[v])?1:0);
        if(op==0){
            for(int j=0;j<m;j++){
                if(fa[j]==fa[u])fa[j]=fa[v];
            }
        }
    }
    cout<<ans;
}