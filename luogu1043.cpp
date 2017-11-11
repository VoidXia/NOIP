#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mi[70][70][15];
    int ma[70][70][15];
    memset(ma,0,sizeof(ma));
    //const int inf=0x7f7f7f7f;
    memset(mi,127,sizeof(mi));
    int v[100];
    int sum[100];
    memset(sum,0,sizeof(sum));
    int total[100][100];
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        v[i+n]=v[i];
      //  sum[i]=sum[i-1]+v[i];
    }
    n<<=1;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            mi[i][j][1]=ma[i][j][1]=total[i][j]=((sum[j]-sum[i-1])%10+10)%10;;
        }
    }
    //cout<<mi[0][0][0];
    for(int l=2;l<=m;l++)
    for(int j=1;j<=n;j++){
        for(int i=(j>(n<<1))?(j-(n<<1)+1):1;i<=j;i++){
            for(int k=i;k<j;k++){
                ma[i][j][l]=max(ma[i][j][l],ma[i][k][l-1]*total[k+1][j]);
                if(mi[i][k][l-1]!=mi[0][0][0])
                mi[i][j][l]=min(mi[i][j][l],mi[i][k][l-1]*total[k+1][j]);

            }
        }
    }
    n>>=1;
    int mina=1000000;
    int maxa=1<<31;
    for(int i=1;i<=n;i++)
    {
        maxa=max(maxa,ma[i][i+n-1][m]);
        mina=min(mina,mi[i][i+n-1][m]);
    }
    cout<<mina<<'\n'<<maxa;
    return 0;
}