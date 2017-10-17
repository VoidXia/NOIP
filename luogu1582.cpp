#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    k=0;
    scanf("%lld%lld",&n,&k);
    long long ddd=1;
    long long i;
    ddd=1;
    i=0;
    bool aa[200]={0};
    long long ans=0;
    while(ddd<n){

       // cout<<ddd<<'\n';
        if((n&ddd)!=0)ans++,aa[i]=1;//,cout<<'\n'<<ddd<<'\n';
                i++;
        ddd<<=1;
    }

    k=ans-k;
    if(k<=0){cout<<'0';return 0;}
    k++;
    i=0;
    //cout<<'\n'<<'\n';
    //ddd=1;
    while(k!=0){

       // cout<<ddd<<'\n';
        if(aa[i]!=0)k--;//,cout<<'\n'<<ddd<<'\n';
                i++;
       // ddd<<=1;
    }
    
   // cout<<i<<'\n';
    long long ansa;
    if(i<31)
    ansa=(long long)(1<<i)-(long long)(n%(1<<i));
    if(i==31){
        long long gg=2147483648;
        ansa=gg-(n%gg);
    }

   // if(ansa==0)ansa=1;
    printf("%lld",ansa);
    return 0;
}