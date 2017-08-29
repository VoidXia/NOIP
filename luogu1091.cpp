#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int a[100000],f[100000]={0},b[100000]={0};
    int n=0,ans1=0,ans2=0,maxn=0,ll=0;
    int len=1;
    while(cin>>a[n])n++;
    ll=n;
    for(int j=1;j<=ll;j++){
    
    len=1;
    f[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<=f[len-1]) len++,f[len-1]=a[i];
        else {
            int pos;
            pos=upper_bound(f,f+len,a[i],cmp)-f;
            f[pos]=a[i];
        }
    }
    ans1=len;
   // cout<<len<<'\n';
    memset(f,0,sizeof(f));
    len=1;
    f[1]=b[0];
    for(int i=1;i<n;i++){
        if(b[i]>f[len]) f[++len]=b[i];
        else {
            int pos;
            pos=lower_bound(f,f+len,b[i])-f;
            f[pos]=b[i];
        }
    }
    if(b[0]==0&&len==1)len=0;
    ans2=len;
    maxn=max(maxn,ans1+ans2);
    b[ll-n]=a[n];
    a[n]=0;
    n--;
}
    //cout<<len;
    cout<<ll-maxn;
}