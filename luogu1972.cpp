#include<bits/stdc++.h>
using namespace std;
const long long N =1000010;
#define lowbit(x) x&(-x)
long long c[N],n,m,temp;
void add(long long a,long long x){
    //cout<<a<<' '<<x<<"adding\n";
    while(a<=n){c[a]+=x;a+=lowbit(a);}
}
inline long long sum(long long a){
    long long ans=0;
    while(a>0){ans+=c[a];a-=lowbit(a);}
    return ans;
}
inline long long read(){
    long long x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return a*x;
}
struct node{long long l,r,ans,idx;}a[N];
bool cmp1 (const node &a,const node &b){
    return a.r<b.r;
}
bool cmp2(const node&a,const node&b){
    return a.idx<b.idx;
}
long long t[N];
long long gett[2000010];
int main(){
    memset(gett,0,sizeof(gett));
    n=read();
    for(long long i=1;i<=n;i++){
        t[i]=read();
    }
    m=read();
    for(long long i=1;i<=m;i++){
        a[i].l=read();a[i].r=read();a[i].idx=i;
    }
    sort(a+1,a+m+1,cmp1);
    long long cnt=1;
    for(long long i=1;i<=n;i++){
        add(i,1);
        if(gett[t[i]]!=0){
            add(gett[t[i]],-1);
        }
        gett[t[i]]=i;
        while(a[cnt].r==i){
            a[cnt].ans=(sum(a[cnt].r)-sum(a[cnt].l-1));
            cnt++;
        }
    }
    sort(a+1,a+m+1,cmp2);
    for(int i=1;i<=m;i++)cout<<a[i].ans<<'\n';
    //注意按顺序输出
    return 0;
}