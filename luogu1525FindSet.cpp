#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int fa[400010];
struct  node{
    int from,to,val;
}a[400010];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        fa[b]=a;
        //不知道为什么FA[A]=B不行
        //锅
    }
}
bool cmp(const node& a,const node& b){
    return a.val>b.val;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].val);
        /*i++;
        a[i].to=a[i-1].from;
        a[i].from=a[i-1].to;
        a[i].val=a[i-1].val;*/
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=2*n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){

        int j=find(a[i].from);
        int k=find(a[i].to);
        //	    cout<<j<<' '<<k<<'\n';
        if(j==k){
            cout<<a[i].val;
            return 0;
        }
        if(j==find(a[i].to+n)||k==find(a[i].from+n))continue;
        merge(j,k+n);
        merge(k,j+n);
                //使得父亲结点是“真”结点
    }
    cout<<0;
    return 0;
}