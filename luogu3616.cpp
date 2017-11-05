#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define lowbit(x) x&(-x)
int b[100010];
int n;
void add(int x,int y){
    while(x<=n){
        b[x]+=y;
        y+=lowbit(y);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=b[x];
        x-=lowbit(x);
    }
    return ans;
}
