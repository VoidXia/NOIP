#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int w,n;
    int a[220]={0};
    //bool b[220]={0};
    cin>>w>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    //for(int i=0;i<n;i++)cout<<a[i]<<'\n',b[i]=1;
//    int sum=0;
    int ans=0;
    int l=0;
    int r=n-1;
    while(l<=r)if(a[l]+a[r]<=w){ans++,l++,r--;}else{ans++,r--;}
/*    for(int i=n-1;i>=0;i--){
        if(b[i]){
            ans++;
//        sum+=a[i];
            int t=-1;
            for(int j=0;j<i;j++)if(a[j]+a[i]<=w&&b[j]==1)t=j;
        //cout<<a[i]<<' '<<a[t]<<'\n';
            if(t!=-1)b[t]=0;
        }
    }*/
    //for(int i=0;i<n;i++)cout<<b[i]<<' ';
    cout<<ans;
    return 0;
}
//如果最大的a[r]不与最小的a[l]分在一组，而是a[r]与a[i]在一组,a[l]与a[j]在一组，因为a[l]<=a[i]&&a[r]>=a[j],所以交换两者分组不影响后续选择，而a[r]如果不能与a[l]在一组，因为a[l]为当前最小值，所以a[r]只能单独为一组，所以贪心是 正确的