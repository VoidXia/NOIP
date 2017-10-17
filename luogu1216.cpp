#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1010][1010];
    for(int i=1;i<=n;i++){
        for(register int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=n-1;i>=1;i++){
        for(register int j=1;j<i;j++){
            a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
        }
    }
    cout<<a[1][1];
    return 0;
}