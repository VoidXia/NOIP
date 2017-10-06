#include<iostream>
using namespace std;
int main(){
    int t,k;
    cin>>t>>k;
    int a[2010][2010]={0};
    a[1][1]=1;
    
    for(register int i=1;i<=2001;i++){
        a[i][1]=1;
        for(register int j=1;j<i;j++){
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%k;
           // cout<<a[i][j]<<' ';
        }
        a[i][i]=1;
      //  cout<<'\n';
    }
    
    //int pre[2010][2010]={0};
    for(register int i=1;i<=2001;i++){
        for(register int j=1;j<=2001;j++){//循环完整谢谢
            if(a[i][j]==0&&j<=i)a[i][j]++;//这里要加&&j<=i否则当n>m的时候就会gg
            else a[i][j]=0;
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            
           // cout<<pre[i][j]<<' ';
        }
      //  cout<<'\n';
    }

    for(register int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        cout<<a[n+1][m+1]<<'\n';
        //我他妈智熄
    }
    return 0;
}