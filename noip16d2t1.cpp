#include<iostream>
using namespace std;
int main(){
    int t,k;
    cin>>t>>k;
    int a[2010][2010]={0};
    a[1][1]=1;
    
    for(register int i=1;i<=2000;i++){
        a[i][0]=1;//这里要0使整个式子平移
        //或者不搞下面全改成2001
        //所以不能naive一定要开大一点的
        //卡死范围会翻车
        for(register int j=1;j<i;j++){
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%k;
           // cout<<a[i][j]<<' ';
        }
        a[i][i]=1;
      //  cout<<'\n';
    }
    
    int pre[2010][2010]={0};
    for(register int i=1;i<=2000;i++){
        for(register int j=1;j<=2000;j++){//循环完整谢谢
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            if(a[i][j]==0&&j<=i)pre[i][j]++;//这里要加&&j<=i否则当n>m的时候就会gg
           // cout<<pre[i][j]<<' ';
        }
      //  cout<<'\n';
    }

    for(register int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        cout<<pre[n+1][m+1]<<'\n';
        //我他妈智熄
    }
    return 0;
}