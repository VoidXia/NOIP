#include<iostream>
using namespace std;
long long n,a[200000],gett[200000]={0},ans=0x7f7f7f7f,dfsc=0;
void dfs(long long k){
    if(a[k]==0)return;
    dfsc++;
    if((dfsc>gett[k])&&gett[k]!=0){
        //为什么dfsc会等于gett[k]啊
        ans=min(ans,dfsc-gett[k]);
        //cout<<dfsc<<' '<<gett[k]<<' '<<k<<'\n';
        a[k]=0;
        gett[k]=0;
        return;
    }

    gett[k]=dfsc;
    //cout<<'k'<<' '<<k<<' '<<dfsc<<'\n';
    dfs(a[k]);
   gett[k]=0;
    a[k]=0;


    
}
int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long i=1;i<=n;i++)
    dfs(i);
    cout<<ans;

}