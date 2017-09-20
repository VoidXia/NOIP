#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int next[100001]={0};
    int prev[100001]={0};
    int settt[100001]={0};
    int k,p;
    for(int i=0;i<=n;i++)next[i]=n+2,prev[i]=n+2;
    prev[1]=0;
    next[0]=1;
    for(int i=2;i<=n;i++){
        cin>>k>>p;
        if(p==0){
            prev[i]=prev[k];
            next[i]=k;
            next[prev[k]]=i;
            prev[k]=i;
        }
        if(p==1){
            next[i]=next[k];
            prev[i]=k;
            prev[next[k]]=i;
            next[k]=i;
        }
    }
    int m;
    cin>>m;
    int i;
    while(m>0){
        m--;
        cin>>i;
        if(settt[i]==0){
        settt[i]=1;

        next[prev[i]]=next[i];
        prev[next[i]]=prev[i];
        next[i]=n+2;
        prev[i]=n+2;}
    }
    for(int j=next[0];j!=n+2;j=next[j]){
        cout<<j;
        if(next[j]!=n+2)cout<<' ';
    }
    cout<<'\n';
}