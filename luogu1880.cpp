#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1000]={0},s[1000]={0};
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[n+i]=a[i];
    for(int i=1;i<=2*n;i++)s[i]=s[i-1]+a[i];
    for (int l=2;l<=n;l++){
        for(int i=1;i<=2*n-l+1;i++){
            j=i+l-1;
            f1[i,j]=-INFINITY;
            f2[i,j]=INFINITY;
            for(int k=i;k<=j-1;k++){
                f1[i,j]=max(f1[i,j],f1[i,k]+f1[k+1,j]+s[j]-s[i-1]);
                f2[i,j]=min(f2[i,j],f2[i,k]+f2[k+1,j]+s[j]-s[i-1]);
            }
        }
        
    }
    for(i=1;i<=n;i++)ans1=max(ans1,f1[i,i+n-1]);
    for(i=1;i<=n;i++)ans2=min(ans2,f2[i,i+n-1]);
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}