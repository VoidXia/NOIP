#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int fa[100010];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool same(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b)return 1;
    return 0;
}
void uni(int x,int y){
    if(fa[x]!=fa[y]&&find(x)!=find(y)){
        fa[find(x)]=find(y);
    }
}
struct edge{
    int x,y,z;
}a[200010];

bool cmp(const edge& a,const edge& b){
    return a.z<b.z;
}

int main(){
    int n,m;
    int cnt;
    //cout<<cnt<<'\n';
    //int sss[100010];
   // memset(sss,0,sizeof(sss));
   scanf("%d%d",&n,&m);
   cnt=n;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        //cout<<same(a[i].x,a[i].y);
        if(!same(a[i].x,a[i].y)){
            ans+=a[i].z;
           // cout<<'l';
            uni(a[i].x,a[i].y);
            cnt--;

        }
    }
    //bool flg=1;
  //  for(int i=1;i<=n;i++){
  //      for(int j=1;j<=n;j++)
  //      if(!same(i,j)){
      //  if(cnt==0)    flg=0;
            //cout<<i<<' '<<j<<'\n';
 //           break;
  //      }
  //  }
    //cout<<n;
    if(cnt==1)
    printf("%d",ans);
    else printf("orz");
    //cout<<'\n'<<cnt;
    return 0;
}