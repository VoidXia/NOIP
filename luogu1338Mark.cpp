#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    long long a[50010];
    long long l=1,r=n;
    for(long long i=1;i<=n;i++){
        long long x=(n-i)*(n-i-1)/2;
        if(x>=m)a[l++]=i;
        else{
            a[r--]=i;
            m-=r-l+1;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}