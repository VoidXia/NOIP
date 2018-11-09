#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+100;
int a[maxn];
inline int read(){
    int x=0;char c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x;
}
int main(){
    set<int>s;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        //a[i]=read();
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);
    
    int mid=0;
    mid=(n+1)/2;
    k--;
    s.insert(a[mid]);
    int l,r;
    l=mid;
    if(n%2==0)r=mid+1;else r=mid;
    while(k>0){
        if(!s.count(a[r])){
            s.insert(a[r]);
            k--;
        }
        if(k==0)break;
        if(!s.count(a[l])){
            s.insert(a[l]);
            k--;
        }
        l--;r++;
    }
    long long ans=0;
    for(set<int>::iterator iter=s.begin();iter!=s.end();iter++){
        //int temp=(*iter);
        //cout<<(*iter)<<' ';
        //ans=0;
        for(int i=1;i<=n;i++){ans+=(long long)abs((*iter)-a[i]);}
        //cout<<ans<<"k\n";
    }
    cout<<ans;
    return 0;
}
