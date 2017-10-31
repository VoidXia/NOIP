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
        x+=lowb(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=bi[x];
        x-=lowb(x);
    }
    return ans;
}
struct one{
    int x,y;
}a[100010];

bool cmp(const one& a,const one& b){
    return a.x<b.x;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        add(a[i].y,1);
        ans+=i-sum(a[i].y);
    }
    cout<<ans;
    return 0;
}