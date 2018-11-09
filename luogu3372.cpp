#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define lowbit(x) x&(-x)
long long c[N],d[N],n,m,z=0,x,y,k;
void add(long long x,long long a){while(x<=n){c[x]+=a;x+=lowbit(x);}}
long long sum(long long x){long long ans=0;while(x>0)ans+=c[x],x-=lowbit(x);return ans;}
void addd(long long x,long long a){while(x<=n){d[x]+=a;x+=lowbit(x);}}
long long sumd(long long x){long long ans=0;while(x>0)ans+=d[x],x-=lowbit(x);return ans;}
inline long long read(){
    long long x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return a*x;
}
long long get(long long x){
    long long ans=0;
    ans=(x+1)*sum(x)-sumd(x);
    return ans;
}
int main(){
    n=read();m=read();
    for(long long i=1;i<=n;i++){k=z;z=read();addd(i,(z-k)*i);add(i,z-k);}
    while(m--){
        z=read();x=read();y=read();
        //cout<<z<<' '<<x<<' '<<y<<"kk\n";
        if(z==1){
            //cout<<1<<'\n';
            k=read();
            add(x,k);add(y+1,-k);
            addd(x,x*k);addd(y+1,(y+1)*(-k));
        }
        if(z==2){
            //cout<<"2\n";
            cout<<(get(y)-get(x-1))<<'\n';
        }
    }
    return 0;
}