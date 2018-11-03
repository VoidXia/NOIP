#include<bits/stdc++.h>
#include<queue>
const long long maxn = 1000010;
using namespace std;
long long read(){
    long long a=1,x=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return a*x;
}
    long long n;
    long long a[maxn];
    long long su=0;
    long long s[maxn]={0};
int main(){

    n=read();

    for(long long i=1;i<=n;i++)a[i]=read(),su+=a[i];
    long long y=su/n;
    for(long long i=1;i<=n;i++){
        a[i]-=y;
        s[i]+=s[i-1]+a[i];
    }
    sort(s+1,s+n+1);
    long long mid=(n+1)/2;
    long long ans=0;
    for(long long i=1;i<=n;i++)ans+=abs(s[i]-s[mid]);
    cout<<ans;
    return 0;
}