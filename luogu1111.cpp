#include<iostream>
#include<cstdio>
#include<algorithm>
struct node{
    int x,y,t;
}a[1010];
int fa[100010];
bool cmp (const node &a,const node &b){
    return a.t<b.t;
}
int find (int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}

void nion(int a ,int b){
    if(fa[a]!=fa[b]||find(a)!=find(b))fa[fa[a]]=b;
}

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].t;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    bool flag[1010]={0};
   // cout<<m;
    for(int i=1;i<=m;i++){
      //  printf("fuck");
      //  cout<<find(a[i].x)<<' '<<find(a[i].y)<<'\n';
        if(fa[a[i].x]!=fa[a[i].y]||find(a[i].x)!=find(a[i].y)){
           // cout<<'p';
            ans=a[i].t;
            flag[a[i].x]=flag[a[i].y]=1;
            nion(a[i].x,a[i].y);
            
        }
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;
    return 0;

}