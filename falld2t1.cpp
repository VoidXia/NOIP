#include<iostream>
const int maxn=1010;
using namespace std;
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    if(n>1010){
        cout<<"19260817";
        return 0;
    }
    int a[maxn],b[maxn];
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    //要所有防御攻击方的差值的最大值最小
    //先看第一个最大值可以吗？可以再二分的向下
    sort(a+1,a+n);
    sort(b+1,b+n);
    int c[maxn];
    for(int i=1;i<=n;i++)c[i]=b[i]-a[i];
    sort(c+1,c+n);
    if(x==0){
        cout<<c[n];
        return 0;
    }
    if(x==n){
        if((c[n]-y)>0)cout<<c[n]-y;else cout<<'0';
        return 0;
    }
    int d[maxn];
    for(int i=1;i<=n;i++)
        d[i]=b[i]-y;
    
}