#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[100010]={0};
    a[1]=a[0]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k&&j<=i;j++){
            a[i]+=a[i-j];
            //cout<<i<<' '<<i-j<<' '<<a[i]<<'\n';
            a[i]%=100003;
        }
    }
    cout<<a[n];
    return 0;
}
/*
0 1
1 1
2 2
3 3
4 5
5 
*/
