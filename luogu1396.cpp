#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int fa[100010];
int find(int x){
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b)fa[b]=a;
}
struct de{
    int x,y,l;
}a[100010];

bool cmp(const de& a,const de& b){
    return a.l<b.l;
}

bool ask(int x,int y){
    if(find(x)!=find(y))return 0;
    return 1;
}
int main(){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
    }
    int ans=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int aa=find(a[i].x);
        int bb=find(a[i].y);
        merge(aa,bb);
        if(ask(s,t)){
           // cout<<find(s)<<' '<<find(t)<<'\n';
            ans=a[i].l;
            break;
        }
    }
    cout<<ans;
    return 0;
}