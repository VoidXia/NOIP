#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define lowbit(x) x&(-x)
int n,m;
int a[500010];
void change(int x,int w){
    while(x<=n){
        a[x]+=w;
        x+=lowbit(x);
    }
}
int find(int x,int y){
    int ans=0;
    while(y>0){
        ans+=a[y];
        y-=lowbit(y);
    }
    x--;
    while(x>0){
        
        ans-=a[x];
        x-=lowbit(x);
    }
    return ans;
}
void check(){
     
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int j=i;
        while(j<=n){
            a[j]+=k;
            j+=lowbit(j);
        }
    }
    
//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//     cout<<'\n';
    //cout<<'\n';
    for(int i=1;i<=m;i++){
        int flg;
        scanf("%d",&flg);
        int x,y;
        if(flg==1){
            scanf("%d%d",&x,&y);
            change(x,y);
           //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
   //  cout<<'\n';
        }
        if(flg==2){
            scanf("%d%d",&x,&y);
            int ans=find(x,y);
            printf("%d\n",ans);
         // for(int i=1;i<=n;i++)cout<<a[i]<<' ';
  //   cout<<'\n';
        }
    }
    return 0;
}