#include<iostream>
using namespace std;
int main(){
   // int a[500010]={0};
   int a=0;
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    /*
    for(int i=1;i<=n;i++){
        int e;
        cin>>e;
        a[i]=a[i-1]+e;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        bool o=0;
        for(int i=1;i<=n-x+1;i++){
            if(a[i+x]-a[i]==y){o=1;break;}
        }
        if(o==1)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
    */
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a<<=1;
        if(x==1)a++;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=n-x+1;i++){
            
        }
    }

    
}