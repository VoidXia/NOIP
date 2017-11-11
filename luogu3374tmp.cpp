#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define lowb(x) x&(-x);
using namespace std;
int b[100010];
int n;
void add(int x,int y){
    while(x<=n){
        b[x]+=y;
        x+=lowb(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=b[x];
        x-=lowb(x);
    }
    return ans;
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(i,x);
    }
    for(int i=1;i<=m;i++){
        int m,x,y;
        scanf("%d%d%d",&m,&x,&y);
        if(m==1)add(x,y);
        if(m==2)cout<<(sum(y)-sum(x-1))<<'\n';
    }


}