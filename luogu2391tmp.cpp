#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int fa[1000010];
//int find(int x){return (fa[x]<0)?x:fa[x]=find(fa[x]);}
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
int main(){
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int a[1000010];
    for(int i=1;i<=n;i++)fa[i]=i;
    //memset(fa,-1,sizeof(fa));
    for(int i=m;i>=1;i--){
        int mi=(i*p+q)%n+1;
        int ma=(i*q+p)%n+1;
        if(mi>ma)swap(mi,ma);
        mi=find(mi);
        while(mi<=ma){
            a[mi]=i;
            fa[mi]=mi+1;
            mi=find(fa[mi]);
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
    return 0;
}