#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int a[10000000]={0};
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int n,m,q,qq;
        cin>>n>>m>>q;
        int now=0,pre=0;
        if(n==m){
            q=q-q/n;
            cout<<q;
            continue;
        }
        qq=q;
        if(n<m)swap(n,m);
        for(int i=0;i<=q/n;i++){
            int ii=i*n;
            qq-=(q-ii)%m;
            cout<<qq;
        }
        for(int i=0;i<=q/n;i++){
            for(int j=0;j*m+i*n<=q;j++){
                a[j*m+i*n]++;
                if(a[j*m+i*n]==2)q++,a[j*m+i*n]--;
            }
        }
        cout<<qq;
        memset(a,0,sizeof(a));



    }


}