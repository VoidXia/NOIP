#include<bits/stdc++.h>
using namespace std;
int a[1000]={0},n,t;

int dfs(int x){
    int ans=1;
    l=l+1;
    x=a[l];
 //   for (l=1;q[l]<>0;l++)h[l]=q[l];
    for (int i=2;i<=x/2;i++){
        if (x%i==0&&inin(i,l)){
            a[l]=i;
            l=l+1;
            ans=ans+dfs(x/i);
            l=l-1;
            a[l]=0;
        }
    }
    a[l]=0;
    l=l-1;
    return ans;
}

bool inin(int x,int o){
    for (int i=0;i<=o;i++)if (a[i]==x)return 0;
    return 1;
}
int main(){
    cin>>t;
    for (int k=1;k<=t;k++){
        cin>>n;
        cout<<dfs(x,0);
    }
    return 0;
}