#include<bits/stdc++.h>
using namespace std;
#define lowb(x) x&(-x)
int bi[500010];
int n,m;
void adde(int x,int y){
    //cout<<'k';
   // cout<<x<<' '<<n<<'\n';
    while(x<=n){
      //  cout<<bi[x]<<' ';
        bi[x]+=y;
      //  cout<<bi[x]<<' '<<y<<'\n';
        x+=lowb(x);
    }
}
int sum(int x){
    int ans;
    while(x>0){
        ans+=bi[x];
        x-=lowb(x);
      //  cout<<bi[x];
    }
    return ans;
}
int main(){
   // int n,m;
    memset(bi,0,sizeof(bi));
    cin>>n>>m;
   // cout<<n;
    int pre=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
       // cout<<n<<'\n';
        adde(i,x-pre);
      //  cout<<bi[i]<<x-pre<<'\n';
        pre=x;
    }
    for(int i=1;i<=m;i++){
        int mm;
        cin>>mm;
        if(mm==1){
            int x,y,k;
            cin>>x>>y>>k;
            adde(x,k);
            adde(y+1,-k);
        }
     //   for(int i=1;i<=n;i++)cout<<bi[i]<<' ';cout<<'\n';
        if(mm==2){
            int x;
            cin>>x;
            cout<<sum(x)<<'\n';
        }
    }
    return 0;
}
//naocanxia