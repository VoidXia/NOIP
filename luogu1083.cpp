#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
int r[1000010];
struct node{
    int d,s,j;
}a[1000010];

bool check(int mid){
    int sum[1000010];
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=mid;i++){
        sum[a[i].s]+=a[i].d;
        sum[a[i].j+1]-=a[i].d;
    }
    for(int i=1;i<=n;i++){
       sum[i]+=sum[i-1];
       if(sum[i]>r[i])return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].j);
       // a[i].i=i;
    }
   // sort(a+1,a+n+1,cmp);
    int l=1,rr=m;
    while(l<rr){
        int mid=(l+rr)/2;
        if(check(mid))rr=mid;
        else l=mid+1;
    }
    if(rr!=m)cout<<-1<<'\n'<<rr;
    else cout<<'0'<<'\n';
    return 0;
}