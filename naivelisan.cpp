#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
}a[100010];
bool cmp(const node& a,const node& b){
    return a.x<b.x;
}
bool cmpp(const node& a,const node& b){
    return a.y<b.y;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=i;
    }
    
    sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)cout<<a[i].x<<' ';
        cout<<'\n';
    int top=1;
    int now=a[1].x;
    a[1].x=1;
    for(int i=2;i<=n;i++){
        if(a[i].x!=now){now=a[i].x;top++;}
        a[i].x=top;
    }
    sort(a+1,a+1+n,cmpp);
    for(int i=1;i<=n;i++)cout<<a[i].x<<' ';
    return 0;
}