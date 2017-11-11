#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
}a[100010];
#define lowbit(x) x&(-x)
int n;
int b[100010];
void add(int x,int w){
    while(x<=n){
        b[x]+=w;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=b[x];
        x-=lowbit(x);
    }
    return ans;
}
bool cmp(const node& a,const node& b){
    return a.x<b.x;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        add(a[i].y,1);
        ans+=i-(sum(a[i].y));
    }
    cout<<ans;
    return 0;
    
}