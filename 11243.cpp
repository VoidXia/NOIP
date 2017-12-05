#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    freopen("fuck.out","w",stdout);
    char s[40];
    signed int i;
    for(i=0;i<=33;i++){
        s[i]^=0xADu;
       // cout<<0xADu;
    }
    s[i]=0;
    cout<<s;
    fclose(stdout);
    return 0;
}