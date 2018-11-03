#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,a_b;
}a[1050];
bool operator <(const node &a,const node &b){
    return a.a_b<b.a_b;
}
inline int read(){
    int x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}
int ss[150];
int add[150];
void mul(long long w){
    memset(add,0,sizeof(add));
    for(int i=0;w>0;i++){
        
    }
}
int main(){
    int n=read();
    for(int i=0;i<=n;i++){
        a[i].a=read();
        a[i].b=read();
        a[i].a_b=a[i].a*a[i].b;
    }
    sort(a+1,a+n+1);
    long long dd=a[0].a;
    int y=a[0].a;
    int rr=0;
    while(y>0){
        ss[rr]=y%10;
        y/=10;
        rr++;
    }
    long long an=0;
    long long ans=-1;
    //for(int i=1;i<=n;i++)an=dd/a[i].b,dd*=a[i].a,ans=max(an,ans);
    for(int i=1;i<=n;i++)an=divi(a[i].b),mul(a[i].a),ans=max(an,ans);
    cout<<ans;
    return 0;
}