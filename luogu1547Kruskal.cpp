#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int fa[100010];
int toto=0;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        fa[b]=a;
        toto++;
    }
}
struct node{
    int x,y,l;
}a[100010];
bool cmp(const node& a,const node& b){
    return a.l<b.l;
}
int main(){
    int n,m;
    int ma=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        merge(a[i].x,a[i].y);
        ma=max(ma,a[i].l);
        if(toto>=n-1)break;
    }
    cout<<ma;
    return 0;
}