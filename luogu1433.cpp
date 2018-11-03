#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
bool que[20];
int n;
double dis[20][20];
double a[20][2];
int r=0;
double anss=9999999.0;
double ans=0;
void dfs(int i){
    if(ans>anss)return;
    //cout<<r<<'r'<<'\n';
    if(r==n){anss=min(ans,anss);return;}
    for(int j=1;j<=n;j++)if(que[j]==0){
        if(dis[i][j]==0&&i!=j)dis[i][j]=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
        ans+=(double)dis[i][j];
        //ans+=(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
        //cout<<(double)dis[i][j]-(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))<<'\n';
        //cout<<(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))<<'\n';
        //cout<<(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])<<'d'<<'\n';
        //cout<<j<<'+'<<'\n';
        r++;
        que[j]=1;
        dfs(j);
        r--;
        que[j]=0;
        //cout<<j<<'-'<<'\n';
        ans-=(double)dis[i][j];
        //ans-=(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
    }
}
int main(){
    a[0][0]=0;
    a[0][1]=0;
    cin>>n;
    if(n==0){
        cout<<0.00;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
            cout<<(double)dis[i][j]-(double)sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))<<'\n';
        }
    }*/
    que[0]=1;
    dfs(0);
    printf("%.2f",anss);
    return 0;
}