#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
template <typename tn>
void read(tn& a){
    a = 0; char c;
    while (!isdigit(c = getchar()));
    do a = a * 10 + c - '0'; while (isdigit(c = getchar()));
}
int fa[400010],head[400010],h[400010],ans[400010],en=0,i;
bool e[400010];
int cc,dd,aa,bb,n,m,k,tot;

struct node{
    int from,to,next;
}a[400010];

inline int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

inline void inse(int x,int y){
    en++;
    a[en].from=x;
    a[en].to=y;
    a[en].next=head[x];
    head[x]=en;
}


int main(){
   // int n,m;
    read(n);
    read(m);
    for(i=1;i<=n;i++){
        fa[i]=i;
        head[i]=0;
    }
    int x,y;
    for(i=1;i<=m;i++){
    //    int x,y;
        read(x);
        read(y);
        inse(x,y);
        inse(y,x);
    }
//    sort(a+1,a+m+1,cmp);

    //scanf("%d",&k);
    read(k);
    tot=n-k;//nearly answer
    for(i=1;i<=k;i++){
        //int x;
        read(x);
        e[x]=1;
        h[i]=x;
    }
    for(i=1;i<=en;i++){
        if(e[a[i].from]==false&&e[a[i].to]==false){
            aa=find(a[i].from);
            bb=find(a[i].to);
            if(aa!=bb){
                fa[bb]=aa;
                tot--;
            }
        }
    }
    ans[k+1]=tot;
    int u;
    for(i=k;i>=1;i--){
        u=h[i];
        tot++;
        e[u]=0;
        for(register int j=head[u];j;){//这里的j是边的编号
            cc=find(a[j].to);
            dd=find(u);
            if(e[a[j].to]==0&&cc!=dd){
                tot--;
                fa[cc]=dd;
            }
            j=a[j].next;
           // a[j].next=-1;
        }
      //  cout<<i;
        ans[i]=tot;
    }
    for(i=1;i<=k+1;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}