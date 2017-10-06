#include<iostream>
#include<cstdio>
#include<algorithm>
bool cmp(int a,int b){
    return a>b;
}
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[70];
    for(register int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n+1,cmp);
    int sum=0;
    for(register int i=n;i>=1;i--)if(a[i]>50)n--;else break;
    for(register int i=1;i<=n;i++)sum+=a[i];
    for(register int i=1;i<=sum/2;i++)
        if(sum%i==0)//get;
    
}