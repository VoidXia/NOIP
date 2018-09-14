#include<iostream>
#include<algorithm>
using namespace std;
struct a{
    int a,b;
}a[3000];
bool cmp(struct a a,struct a b){
    return a.a<b.a;
}
int main(){
    int m;
    cin>>m;
    int x=0;
    for(int i=3;i<=m/2;i+=2){
        if(m%i==0&&m/i>=(i-1)/2)a[x].a=(m/i-(i-1)/2),a[x++].b=(m/i+(i-1)/2);
    }
    m*=2;
    for(int i=3;i<=m;i+=2){
        if(m%i==0&&(m/i)%2==0&&((i-1)/2-((m/i)/2-1))>0)a[x].a=((i-1)/2-((m/i)/2-1)),a[x++].b=(i-1)/2+(m/i)/2;
    }
    sort(a,a+x,cmp);
    for(int i=0;i<x;i++)cout<<a[i].a<<' '<<a[i].b<<'\n';
    return 0;
}