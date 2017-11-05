#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
    int x,y,l;
}a[10010];

bool cmp(const node& a,const node& b){
    return a.l<b.l;
}

int fa[10010];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b)fa[b]=a;
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
    }
    sort(a+1,a+m+1,cmp);
    int tot=0;
    int ans=0;
    for(int i=1;i<=m;i++){
        int x=find(a[i].x);
        int y=find(a[i].y);
        if(x!=y){
            merge(x,y);
            tot++;
            
            ans+=a[i].l;
        }
       // cout<<a[i].x<<' '<<a[i].y<<' '<<n-k<<' '<<tot<<' '<<(tot==n-k)?1:0<<'\n';
        if(tot==n-k)break;
    }
    
    if(ans==0)cout<<"No Answer";
    else cout<<ans;
    return 0;
}