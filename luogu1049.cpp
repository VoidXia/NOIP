#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int v,n,i,j,a[100000],l[100000]={0};
    cin>>v>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
        for (j=v;j>=0;j--){
            if (j<a[i])continue;
            l[j]=max(l[j],l[j-a[i]]+a[i]);
            
        }
    }
    cout<<v-l[v]<<endl;
    return 0;
}