#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    //int qu[500000]={0};
    bool f[500000]={0};
    cin>>n>>m;
    int a[500000]={0};
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        f[i]=1;
    }
    char cc;
    while(m--){
        cin>>cc;
        if(cc=='C'){
            int x,y;
            cin>>x>>y;
            a[x]-=y;
            sum-=y;
        }
        if(cc=='D'){
            int w,x=1;
            bool ind=0;
            cin>>w;
            /*while(ind==0){
                if(x==w&&f[x]==1)ind=1;
                w-=qu[x];
                x++;
            }
            x--;*/
            while(w!=0){
                if(f[x]==1)w--;
                x++;
            }
            x--;
            sum-=a[x];
            f[x]=0;
            a[x]=0;
            //qu[x]--;
        }
        if(cc=='I'){
            int x,y;
            cin>>x>>y;
            //if(!f[x])qu[x]++;
            sum-=a[x];
            a[x]=y;
            sum+=y;
            f[x]=1;
           // ma=max(ma,x);
        }
        if(cc=='Q'){
            cout<<sum<<'\n';
        }
    }
    return 0;
}