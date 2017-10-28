#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a[10];
    int b[10];
    while(t--){
        int ans1=0;
        int ans2=0;
        for(int i=1;i<=6;i++){
            cin>>a[i];
        }
        for(int i=1;i<=6;i++){
            cin>>b[i];
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                if(a[i]>b[j])ans1++;
                if(a[i]<b[j])ans2++;
            }
        }
        if(ans1>ans2)cout<<"Alice";
        if(ans1<ans2)cout<<"Bob";
        if(ans1==ans2)cout<<"Tie";
        cout<<'\n';
    }
    return 0;
}