#include<bits/stdc++.h>
using namespace std;
int n;
int add(int aa,int bb){
    int res[26];
    for(int i=1;i<=n;i++){
        int a=aa%10;
        int b=bb%10;
        aa=aa/10;
        bb=bb/10;
        res[i]=a+b;
        if( res[i]>=n)res[i]-=n,res[i+1]+=1;

    }
    int resu,ten;
    ten=1;
    for(int i=1;i<=n;i++)
    resu+=res[i]*ten,
    ten*=10;
    return resu;
}

int main(){
    string a,b,c;
    cin>>n;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    
}

