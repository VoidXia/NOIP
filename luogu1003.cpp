#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[10010][5]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
    }
    int x,y;
    cin>>x>>y;
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(a[i][1]<=x&&a[i][2]<=y&&a[i][3]+a[i][1]>=x&&a[i][4]+a[i][2]>=y){
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}