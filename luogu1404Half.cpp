#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long a[100010];
    a[0]=0;
    long long l=0,r=1<<31;
    for(long long i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]*=10000;
       // l=min(l,a[i]);
        r=max(r,a[i]);
      //  a[i]+=a[i-1];
   //     cout<<a[i]<<' ';
    }
 //   cout<<'\n';
   // cout<<l<<' '<<r<<'\n';
    while(l<=r){
        bool ok=0;
        long long s[100010];
        long long mid=(l+r)/2,mm=0;
        for(long long i=1;i<=n;i++){
            s[i]=s[i-1]+(a[i]-mid); //Trick
            if(i>=m){
                mm=min(mm,s[i-m]);//Trick
                if(s[i]>mm){
                    ok=1;
                    break;
                }
            }

        }
        if (ok) l=mid+1;
        else r=mid-1;
    }
    cout<<l/10;
    return 0;
}