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
    if(a!=b)fa[b]=a;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*2;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        char c;
        cin>>c;
        int x,y;
        scanf("%d%d",&x,&y);
        if(c=='F')merge(x,y);
        else merge(x,y+n),merge(y,x+n);
    }
    bool in[100010];
    for(int i=1;i<=n;i++)in[find(i)]=1;
    for(int i=1;i<=2*n;i++)if(in[i])tot++;
    cout<<tot;
    return 0;
}