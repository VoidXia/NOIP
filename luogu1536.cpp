#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int fa[100010];
int n,m;
int tot=0;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    int a=find(x);int b=find(y);
    if(a!=b){fa[b]=a;tot++;}
}
int main(){
    int n,m;
    n=1;
    while(n!=0){
        cin>>n>>m;
        tot=0;
        int x,y;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        if(n!=0)cout<<n-1-tot<<'\n';
    }
    return 0;
}