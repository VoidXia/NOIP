#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a [ 110 ];
    int sum = 0;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a [ i ];
        sum += a[ i ];
    }
    sum /= n;
    int ans=0;
    for(int i=1;i<n;i++){
        if ( a[ i ] != sum) a[ i+1 ] += a[ i ] - sum, ans++;
    }
    cout<<ans;
    return 0;
}