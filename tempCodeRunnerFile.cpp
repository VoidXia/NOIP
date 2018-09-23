#include<iostream>
#define DBL_MAX 1.7976931348623158e+308 /* max value */
using namespace std;
int main(){
    double a=-1;
    for(int i=1;i<=2000000;i++){
        a=(double)1/3*a*a+0.7500000001;
        cout<<a<<' ';
        if(a>=1e+308){cout<<i<<" ";break;}
    }
    cout<<a;
    return 0;
}