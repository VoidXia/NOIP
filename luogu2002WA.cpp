#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[100010];
int tot=0;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void merge(int x ,int y){
    int a,b;
    if((a=find(x))!=(b=find(y))){
        fa[b]=a;
        tot++;
    }
}
int main(){
    int n,m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    cout<<n-tot;
    return 0;
}