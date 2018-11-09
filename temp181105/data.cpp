#include<bits/stdc++.h>
using namespace std;
int main(){
    srand((int)time(0));
    int n=rand()%10000,m=rand()%n;
    cout<<m<<' '<<n<<' ';
    for(int i=1;i<=m;i++)cout<<rand()%1000000<<' ';
    for(int i=1;i<=n;i++)cout<<rand()%1000000<<' ';
}