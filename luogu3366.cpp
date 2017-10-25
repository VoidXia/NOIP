#include<iostream>
#include<cstring>
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
struct edge{
    int x,y,z;
}a[100010];

bool cmp(const edge& a,const edge& b){
    return a.z<b.z;
}

int main(){
    int n,m;
    //int sss[100010];
   // memset(sss,0,sizeof(sss));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        if(!same(a[i].x,a[i].y)){
            ans+=a[i].z;
            fa[a[i].x]=a[i].y;

        }
    }
    bool flg=1;
    for(int i=1;i<=n;i++){
        for(int j=1;i<=n;j++)
        if(!same(i,j)){
            flg=0;
            break;
        }
    }
    if(flg==1)
    printf("%d",ans);
    else printf("orz");
    return 0;
}