#include<iostream>
using namespace std;
int main(){
    int n,m;
    int a[500010]={0};
    cin>>n>>m;
   // ios::sync_with_stdio(false);
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        int j=i-(i&(i-1));
        int k=i-1;
        while(j>1){
            a[i]+=a[k];
            k=k&(k-1);
            j=j/2;
        }
        a[i]+=t;
        cout<<a[i]<<' ';
    }
    //the array was made;
    for(int i=1;i<=m;i++){
        int n,x,k;
        scanf("%d%d%d",&n,&x,&k);
        if(n==1){
            while(x<=n){
                a[x]+=k;
                x+=x&(-x);
            }
        }
        if(n==2){
            k--;
            int ans1=0,ans2=0;
            while(x>0){
                ans1+=a[x];
                x-=x&(-x);
            }
            while(k>0){
                ans2+=a[k];
                k-=k&(-k);
            }
            cout<<ans2-ans1;
        }
    }
    return 0;

}