#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int x,h,f1=1,f2=1;
    scanf("%d",&n);
    scanf("%d",&h);
    for(int i=2;i<=n;i++){
        x=h;
        scanf("%d",&h);
        if(x>h)f1=max(f1,f2+1);
        if(x<h)f2=max(f2,f1+1);
    }
    cout<<max(f1,f2);
    return 0;
}