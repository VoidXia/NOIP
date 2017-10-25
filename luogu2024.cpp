#include<iostream>
using namespace std;
int fa[100010]={0};
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void unity(int x,int y){
    int xx=find(x);
    int yy=find(y);
    fa[xx]=yy;
}
int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=3*n;i++)fa[i]=i;
    for(int i=1;i<=k;i++){
        int z,x,y;
        if(x>n||y>n){ans++;continue;}
        if(z==1){
            if(find(x)==find(y+n)||find(x)==find(y+2*n)){ans++;continue;}
            unity(x,y);
            unity(x+n,y+n);
            unity(x+2*n,y+2*n);
            continue;
        }
        if(z==2){
            if(x==y){ans++;continue;}
            if(find(x)==find(y)||find(x)==find(y+2*n)){ans++;continue;}
            unity(x,y+n);
            unity(x+n,y+2*n);
            unity(x+2*n,y);
            continue;
        }

    }
    cout<<ans;
    return 0;
}