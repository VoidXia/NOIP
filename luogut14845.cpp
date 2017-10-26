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
        ans*=a*(k&1);
       // cout<<ans<<' '<<a<<' '<<(k&1)<<'\n';
        a*=a;
        k>>=1;
    }
    return ans;
}
inline int calc(int x){
    return mimi(x,k)*p+q;
}
int main(){
    cin>>k>>p>>q>>l>>r;
    queue<int>q;
    int aa=0;
    for(int i=1;i<=100;i++){
        int tt=calc(i);
        if(summ(tt)==i&&tt>=l&&tt<=r)aa++,q.push(tt);
    }
    //这里因为数很多但是数位和很少，所以考虑枚举数位和
    //由数位和推出这个数，再检验是否在范围内即可
    //我说是我自己想出来的你们信吗
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