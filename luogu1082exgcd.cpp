#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int exgcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
    int m,n;
    cin>>m>>n;
    int a;
    int x=0;
    int y=0;
    a=exgcd(m,n,x,y);
    cout<<(x+n)%n;
    return 0;
}