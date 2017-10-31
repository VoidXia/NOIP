#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int fa[100010];
int num[100010];
int dis[100010];
int find(int x){
    if(x!=fa[x]){
        int k=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[k];
        num[x]=num[fa[x]];
    }
    return fa[x];
}
void merge(int x,int y){
    int r1=find(x);
    int r2=find(y);
    if(r1!=r2){
        fa[r2]=r1;
        dis[r2]=dis[r1]+num[r1];
        num[r1]+=num[r2];
        num[r2]=num[r1];
    }
}
int ask(int a,int b){
    int r1=find(a);
    int r2=find(b);
    if(r1!=r2)return -1;
    else {
        return abs(dis[a]-dis[b])-1;
    }
}
int main(){
    int t;
    for(int i=1;i<=t;i++){
        fa[i]=i;
        num[i]=1;
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        char c;
        scanf(" %c ",&c);//attention
       // cout<<c;
        int a,b;
        scanf("%d%d",&a,&b);
        if(c=='M')merge(a,b);
        else printf("%d\n",ask(a,b));

    }
    return 0;
}