#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int fa[100010];
int n,m;
int tott=0;
bool flg=0;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    int a=find(x);int b=find(y);
    if(a!=b){fa[b]=a;tott++;flg=1;}
}
struct node{
    int x,y,l;
}a[100010];
bool cmp(const node& a,const node& b){
    return a.l<b.l;
}
int main(){
    int n;
    cin>>n;
    int tot=0;
    //int a[110][110];
    for(int i=1;i<=n;i++){
        fa[i]=i;
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(i>=j)continue;
            tot++;
            a[tot].l=x;
            //cout<<tot;
            a[tot].x=i;
            a[tot].y=j;
           // cout<<i<<' '<<j<<' '<<a[tot].l<<'\n';
        }
    }
    sort(a+1,a+tot+1,cmp);
    int ans=0;
    for(int i=1;i<=tot;i++){
        flg=0;
        merge(a[i].x,a[i].y);
        if(flg)ans+=a[i].l;
       // cout<<tott<<' '<<a[i].x<<' '<<a[i].y<<'\n';
        if(tott+1==n)break;
    }
    cout<<ans;
    return 0;
    
}