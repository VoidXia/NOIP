#include<iostream>
using namespace std;
int main(){
int a[1000]={0};
for(int i=0;i<=90;i=i+9){
    for(int j=0;j<=18*10;j=j+18){
        cout<<i+j;
        for(int k=1;k<=a[i+j];k++)cout<<'D';
        a[i+j]++;
        cout<<' ';
    }
    cout<<'\n';
}
}
