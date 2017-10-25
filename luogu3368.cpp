#include<iostream>
#define lowbit(x) x&(-x)
using namespace std;
int a[500010];
int n,m;
void change(int x,int w){
    while(x<=n){
        a[x]+=w;
        x+=lowbit(x);
    }
}
int find(int x){
    int ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int u;
    int last=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&u);
        int t=i;
        while(t<=n){
            a[t]+=u-last;
            //cout<<u-last;
            t+=lowbit(t);
        }
        
      //  a[i]+=u-last;
       // cout<<u<<' '<<last<<' '<<u-last<<'\n';
        last=u;
    }
   // for(int i=1;i<=n;i++)cout<<a[i]<<' ';
  //  cout<<'\n';
    for(int i=1;i<=m;i++){
        int flg;
        scanf("%d",&flg);
        if(flg==1){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            change(x,z);
            change(y+1,-z);
            //差分！！！非前缀和！！！
             for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<'\n';
        }
        if(flg==2){
            int x;
            scanf("%d",&x);
           // cout<<'l';
            int ans=find(x);
            printf("%d\n",ans);
        }
    }
    return 0;
}