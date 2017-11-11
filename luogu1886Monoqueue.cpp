#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
int q1[1000010],q2[1000010],a[1000010];
void getmin(){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&q1[h]+m<=i)h++;//delete the extra ele
        while(h<=t&&a[i]<a[q1[t]])t--;//insert into proper loc
        q1[++t]=i;//insert the idx
        if(i>=m)cout<<a[q1[h]]<<' ';
    }
    //q1[h] stores the idx of the element
}
void getmax(){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&q1[h]+m<=i)h++;//delete the extra ele
        while(h<=t&&a[i]>a[q1[t]])t--;//insert into proper loc
        q1[++t]=i;//insert the idx
        if(i>=m)cout<<a[q1[h]]<<' ';
    }
    //q1[h] stores the idx of the element
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    getmin();
    getmax();
    return 0;
}