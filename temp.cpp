#include<bits/stdc++.h>
using namespace std;
long long a[1000],i=0,l=0,ans=0,f=0,ansans=0;
long long convert(long long x){
    if(x==1)return 1;
    a[i]=x%2;
    ans=ans+a[i];
    i=i+1;
    return a[i]=convert((x-a[i-1])/2);
}

int main(){
    cin>>l;
    ans=1;
        a[999]=convert(l);
    cout<<ans;
    //if(ans-f>1){
    for(long long o=i;o>=0;o--)cout<<a[o];
  //  }
    //   cout<<l<<' '<<ans<<' ';
    if (ansans==0)ansans=1;
  //  cout<<ansans-1<<endl;
    return 0;
}