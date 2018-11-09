#include<bits/stdc++.h>
using namespace std;
int n,d;
const int maxn = 100100;
struct node{
    int x,y,idx;
}a[maxn],b[maxn];
bool operator < (const node &a,const node &b){
    return a.y<b.y;
}
int getydist(int x,int y){
    return (a[x].y-b[y].y);
}
int getredist(int x,int y){
    return (abs(a[x].x-b[y].x)+abs(a[x].y-b[y].y));
}
inline int read(){
    int x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}

int main(){
    freopen("portal.in","r",stdin);
    freopen("portal.out","w",stdout);
    n=read();d=read();
    int tt[maxn];
    for(int i=1;i<=n;i++){
        a[i].x=read();a[i].y=read();a[i].idx=i;
    }
    for(int i=1;i<=n;i++){
        b[i].x=read();b[i].y=read();
    }
    int ans[maxn],an[maxn];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        int mini=0x7f7fffff;
        for(int j=1;j<=n;j++){
            if(getydist(i,j)<(-d))break;
            if(abs(getydist(i,j))<=d)mini=min(mini,getredist(i,j));
        }
        if(mini==0x7f7fffff)mini=0;
        an[i]=mini;
    }
    for(int i=1;i<=n;i++){
        ans[a[i].idx]=an[i];
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}