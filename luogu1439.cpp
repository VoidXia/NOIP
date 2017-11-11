#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
};
bool cmp(const node& a,const node& b){return a.x<b.x;}
int main(){
    int n;
    int a[100010];
    int b[100010];
    int f[100010];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i]=f[b[i]];
       // cout<<b[i]<<' ';
    }
    int cnt=0;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if(b[i]>f[cnt])f[++cnt]=b[i];
        else{
            int t;
            t=lower_bound(f+1,f+n+1,b[i])-f;
            f[cnt]=b[i];
        }
    }
    cout<<cnt;
    return 0;

}