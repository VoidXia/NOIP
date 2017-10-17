#include<iostream>
using namespace std;
int main(){
    int a[20000];
    int j=1;
    for(long long i=1;i<=400000000;i++){
        j++;
        if(j>=20000)j-=20000;
        a[j]=1;
    }
    return 0;
}