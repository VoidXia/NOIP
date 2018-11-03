#include<bits/stdc++.h>
const int maxn = 100010;
using namespace std;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int main(){
    int n,c;
    int a[maxn];
    n=read();
    c=read();
    for(int i=1;i<=n;i++)a[i]=read();
    //for(int i=1;i<=n;i++)cout<<a[i];
    int l=1,r=c;
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    int cnt=0;
    while(cnt<n){
        cnt++;
        int min=2e9+10000;
        int j;
        for(int i=l;i<=r;i++)if(vis[i]==0&&a[i]<min)j=i,min=a[i];
        //cout<<j<<'\n';
        //cout<<l<<' '<<r<<'\n';
        cout<<a[j]<<' ';
        vis[j]=1;
        //for(int i=1;i<=n;i++)cout<<vis[i]<<' ';cout<<'\n';
        if(l<=j){l=j;while(vis[l]==1)l--;}
        if(l==0){l=1;while(vis[l]==1)l++;}
        if(r<n)r++;
    }
    return 0;
}

