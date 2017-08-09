#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100000]={0},b[100000]={0},f[100000],suma=0,sumb=0,sum=0,k;
    cin>>n;
    memset(f,30000,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        suma+=a[i];
        sumb+=b[i];
        sum+=abs(a[i]-b[i]);
    }
    f[suma-sumb+sum]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>b[i])
            for(int j=0;j<=sum*2;j++)
                f[j]=min(f[j],f[j+2*(a[i]-b[i])]+1);
        if(a[i]<b[i])
            for(int j=2*sum;j>=0;j--)
                f[j]=min(f[j],f[j+2*(a[i]-b[i])]+1);
    }
    for(k=0;k<=sum;k++){
        if (f[sum+k]<30000)break;
        if (f[sum-k]<30000)break;
    }
    cout<<min(f[sum+k],f[sum-k]);
    return 0;


}