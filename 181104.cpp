#include<bits/stdc++.h>
using namespace std;
int main(){
    long mod;
    scanf("%ld",&mod);
    //while(mod<=10){
        //cout<<mod;
    int i=0;
    int a0=0,a1=1,a2;
    while(1){
        i++;
        //cout<<a0<<' '<<a1<<'\n';
        a2=(a0+a1)%mod;
        //cout<<a2<<'\n';
        if(a1==0&&a2==1){cout<<i;return 0;}
        a0=a1;
        a1=a2;
    }
    //mod++;
    //}
    return 0;
}