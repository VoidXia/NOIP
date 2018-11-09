#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
const long long M = 1000000007;
long long c[maxn],n,t,d[maxn],z,a,b,ori[maxn],m,avg;
#define lowbit(x) x&(-x)
void add1(long long a,long long x){
    while(a<=n){c[a]+=x;a+=lowbit(a);}
}
inline long long sum1(long long x){
    long long ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans%M;
}
void add2(long long a,long long x){
    while(a<=n){d[a]+=x;a+=lowbit(a);}
}
inline long long sum2(long long x){
    long long ans=0;
    while(x>0){
        ans+=d[x];
        x-=lowbit(x);
    }
    return ans%M;
}
inline long long fastpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1)ans=(ans*a)%M;
        b>>=1;
        a=(a*a)%M;
    }
    return (ans%M);
}
inline long long exgcd(long long a,long long b,long long&x,long long&y) {
    if(!b) {
        x=1;y=0;
        return a;
    }
    long long p=exgcd(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-(a/b)*y;
    return p;
}
long long rev(long long b){
    return fastpow(b,M-2);
}
long long rev2(long long b){
    long long x,y;
    exgcd(b,M,x,y);
    return (x+M)%M;
}
int main(){
    long long ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&t);
        add1(i,t);
        add2(i,t*t);
        ori[i]=t;
    }
    while(m--){
        scanf("%lld%lld%lld",&z,&a,&b);
        if(z==1){
            add1(a,-ori[a]);
            add1(a,b);
            add2(a,-(ori[a]*ori[a]));
            add2(a,b*b);
            ori[a]=b;
            //for(long long i=1;i<=n;i++)cout<<(sum1(i)-sum1(i-1))<<' ';cout<<'\n';
            //for(long long i=1;i<=n;i++)cout<<(sum2(i)-sum2(i-1))<<' ';cout<<'\n';
        }
        if(z==2){
            /*avg=sum1(b)-sum1(a-1);
            //avg=avg/(b-a+1);
            avg=(avg*avg)%M;
            ans=sum2(b)-sum2(a-1);
            ans=(ans*(b-a+1))%M;
            //ans=ans/(b-a+1);
            ans-=avg;
            b=((b-a+1)*(b-a+1))%M;
            a=ans%M;*/
            avg=(sum1(b)-sum1(a-1))%M;
            ans=(sum2(b)-sum2(a-1))%M;
            b=(b-a+1);
            ans=(ans*b)%M;
            b=(b*b)%M;
            ans=(ans-avg*avg)%M;
            a=ans;
            //cout<<(double)a/b<<' ';
            //cout<<ans<<' '<<a<<' '<<b<<'\n';
            cout<<(long long)((long long)a*rev(b))%M<<'\n';
        }
    }
    return 0;
}