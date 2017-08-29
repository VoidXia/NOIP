#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[100000];
    ios::sync_with_stdio(false);
    int n,m;
    int ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if (sum>m){
                ans++;
                i=j-1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}