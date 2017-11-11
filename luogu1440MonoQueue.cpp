#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
}v[100010];
int main(){
    int n,m;
    //int a[100010];
//  for(int i=1;i<=n;i++){
        scanf("%d",&v[0].x);
 //   }
 v[0].y=0;
    int head=0,tail=1;
    for(int i=1;i<n;i++){
        if(i-v[head].y>m)head++;
        cout<<v[head].x<<'\n';
        int x;
        scanf("%d",&x);
        while(tail>head&&x<v[tail].x)tail--;
        v[tail].x=x;v[tail++].y=i;
    }
    return 0;
}