#include<iostream>
#include<stack>
#include<list>
using namespace std;
int a[1000];
int dfn[1000]={0},low[1000]={0},vis[1000]={0};
int ind,instack[1000]={0};
stack<int>st;

inline void tarjan (int u){
    dfn[u]=low[u]=++ind;
    st.push(u);
    instack[u]=1;
    int v=a[u];
    if( vis[v]==0){
        tarjan(v);
        low[u]=min(low[u],low[v]);
    }
    else if (instack[v]){
        low[u]=min(low[u],dfn[v]);
    }
    if (dfn[u]==low[u]){
        v=0;
        for(;;){
            v=st.top();
            st.pop();
            cout<<v;
            if (u==v)break;}

        }
    
    }



int main(){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    tarjan(1);
    return 0;
}