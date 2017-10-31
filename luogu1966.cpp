#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define lowb(x) x&(-x)
using namespace std;
int bi[100010];
int n;
void add(int x,int y){
    while(x<=n){
        bi[x]+=y;
        bi[x]%=99999997;
        x+=lowb(x);
    }
}

int sum(int x){
    int ans=0;
    while(x>0){
        ans+=bi[x];
        ans%=99999997;
        x-=lowb(x);
    }
    return ans;
}

struct one{
    int x,y;
}a[100010],b[100010];

bool cmp(const one& x,const one& y){
    return x.x<y.x;
}

bool cmpp(const one& x,const one& y){
    return x.y<y.y;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i].x);
        b[i].y=i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    int p[100010];
    for(int i=1;i<=n;i++){
        p[a[i].y]=b[i].y;
    }
    
   /* sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i].y<<' ';
        a[i].x=i;
    }
    sort(a+1,a+n+1,cmpp);*/
    
    int ans=0;
    for(int i=1;i<=n;i++){
        add(p[i],1);
        ans=(ans+i-sum(p[i]))%99999997;
    }
    cout<<ans;
    return 0;
}