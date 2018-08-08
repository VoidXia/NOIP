#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct ss{
    int a,b;
}a[1010];

bool cmp(ss a,ss b){
    return a.a<b.a;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a;
        a[i].b=i;
    }
    sort(a+1,a+n+1,cmp);
    double time=0;
    double sum=0;

    for(int i=1;i<=n;i++){
        cout<<a[i].b<<' ';
        sum+=a[i].a*(n-i);
    }
    cout<<'\n';
    time=sum/n;
    printf("%0.2lf",time);
    return 0;
}