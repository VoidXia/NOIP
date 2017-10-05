#include<iostream>
using namespace std;
int n,t;
int calc(int a,int b,int c,int t,int n){
    int ans;
    ans=n*(a+b)+((n)*(n-1)*(c)/2);
    //cout<<ans<<'\n';
    if(ans>t)return 2;
    else if(ans<t)return 0;
    else if(ans==t)return 1;
}



int solve(int x,int y,int z){
    int q=1;
    for(int i=1;calc(x,y,z,t,q)==0;i++){
        q=q<<1;
    }
   // cout<<'\n';
    int l,r;
    l=q>>1;
    r=q;
    while(l+1<r){
        int mid=(l+r)/2;
        int fff;
        fff=calc(x,y,z,t,mid);
        if(fff==0)l=mid;
        if(fff==2)r=mid;
        if(fff==1)l=mid,r=mid;
    }
    return l;
}
int main(){
    int anss=0;
    ios::sync_with_stdio(false);
    cin>>n>>t;
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
        int u;
        u=solve(x,y,z);
        //cout<<u<<'\n';
       
        int yy=u*(x+y)+((u)*(u-1)*(z)/2);
       // cout<<yy<<'\n'<<'\n';
        anss+=t-u*x-((t-yy)>x?x:(t-yy));
      //  cout<<t-u*x-((t-yy)>x?x:(t-yy))<<'\n';
    }
    cout<<anss;
}    