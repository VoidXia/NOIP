#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstdio>
using namespace std;
int k,p,q,l,r;
inline int summ(int x){
    int ans=0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
inline int mimi(int x,int k){
    int a=x;
    int ans=1;
    while(k>0){
      //  cout<<ans;
        if(k&1)
        ans=ans*a*(k&1)%1000000000;
       // cout<<ans<<' '<<a<<' '<<(k&1)<<'\n';
        a=a*a%1000000000;
        k>>=1;
    }
    return ans;
}
inline int calc(int x){
    int ans;
    ans=(mimi(x,k)*p+q);
    ans=ans%1000000000;
    return ans;
}
int main(){
    cin>>k>>p>>q>>l>>r;
    queue<int>q;
    int aa=0;
    for(int i=1;i<=100;i++){
        int tt=calc(i);
        if(summ(tt)==i&&tt>=l&&tt<=r)aa++,q.push(tt);
    }
    cout<<aa<<'\n';
    if(aa==0)cout<<"-1";
    for(int i=1;i<=aa;i++){
        printf("%d ",q.front());
        q.pop();
    }
   // if(aa=0)cout<<"-1";
    return 0;
    //cout<<(aa);
}