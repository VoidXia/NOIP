#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define Ll unsigned long long
using namespace std;
const Ll NN=1e9;
const int N=9;
struct H{
    Ll a[1500],len;
    H(){memset(a,0,sizeof a);len=1;}
};
int n;
H s;
void init(H &a){//读入 
    string s; cin>>s; 
    int l; 
    a.len=0;
    for(int r=s.length()-1;r>=0;r-=N){
        a.len++;                      
        if(r>=N-1)l=r-N+1;else l=0;
        for(int i=l;i<=r;i++)a.a[a.len]=a.a[a.len]*10+s[i]-48;
    }
}  
void outit(H a){//输出 
    printf("%d",a.a[a.len]);
    for(int i=a.len-1;i;i--){
        for(int k=NN/10;a.a[i]<k;k/=10)printf("0");
        if(a.a[i])printf("%d",a.a[i]); 
    }printf("\n");    
}
void in(H &a,int x){//赋值 
    if(!x)return;
    a.len=0;
    while(x){a.a[++a.len]=x%NN;x=x/NN;}
}
bool bigD(H a,H b){//比较是否大于等于 
    if(a.len>b.len)return 1;
    if(a.len<b.len)return 0;
    for(int i=a.len;i;i--)
        if(a.a[i]!=b.a[i])
            if(a.a[i]>b.a[i])return 1;else return 0;
    return 1;
}
H jia(H a,H b){//加法 
    H c;
    int l=max(a.len,b.len);
    for(int i=1;i<=l;i++){
        c.a[i]+=a.a[i]+b.a[i];
        c.a[i+1]=c.a[i]/NN;
        c.a[i]%=NN;
    }
    if(c.a[l+1])l++;
    c.len=l;
    return c;
}
H chu(H a){//除法 
    H c;
    if(a.len==1){c.a[1]=a.a[1]>>1;return c;}
    for(int i=a.len;i;i--){
        if(a.a[i]&1ll)a.a[i-1]+=NN;
        c.a[i]=a.a[i]>>1;
    }
    if(c.a[a.len])c.len=a.len;else c.len=a.len-1;
    return c;
}
H rrr(H a){//-1操作 
    if(a.len==1){
        a.a[1]--;return a;
    }
    H c=a;
    c.a[1]--;
    int l=1;
    while(c.a[l]<0){
        c.a[l]=NN-1;
        c.a[++l]--;
    }
    if(!c.a[c.len])c.len--;
    return c;
}
H chen(H a,H b){//乘法 
    H z;
    z.len=a.len+b.len+2;
    for(int i=1;i<=a.len;i++)
    for(int j=1;j<=b.len;j++)z.a[i+j-1]+=(a.a[i]*b.a[j]);
    for(int i=1;i<=z.len;i++)z.a[i+1]+=z.a[i]/NN,z.a[i]%=NN; //取mo慢，放到外面取   
    while(z.len>1&&!z.a[z.len])z.len--;
    return z;
}
H ksm(H a,int n){//快速幂 
    if(n==1)return a;
    H c=ksm(a,n>>1);
    c=chen(c,c);
    if(n&1)c=chen(c,a);
    return c;
}
bool Chu(H a){//本来这个函数名是骂出题人的，怕和谐，就改了 
    if(a.len*n-n+1>s.len)return 0;
    if(bigD(s,ksm(a,n)))return 1;
    return 0;
}
int main(){
//    freopen("calc.in","r",stdin);
//    freopen("calc.out","w",stdout);
    scanf("%d",&n);
    init(s);
    if(n==1){outit(s);return 0;}
    H l,r,mid,ans;
    in(l,1);
    r=s;
    while(bigD(r,l)){
        mid=jia(l,r);
        mid=chu(mid);
        if(Chu(mid)){
            if(bigD(mid,ans))ans=mid;
            H c;
            in(c,1);
            l=jia(mid,c);
        }else r=rrr(mid);         
    }
    outit(ans);
}