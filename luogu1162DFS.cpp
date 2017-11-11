#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;

int a[50][50];
int b[50][50];
void dfs(int nx,int ny){
    if (nx<0||nx>n+1||ny<0||ny>n+1||a[nx][ny]!=0) return;
        a[nx][ny]=1;
        dfs(nx+1,ny);
        dfs(nx,ny+1);
        dfs(nx-1,ny);
        dfs(nx,ny-1);
    
}
int main(){
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j])a[i][j]=2;
        }
    }
    dfs(0,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!a[i][j])cout<<"2 ";
            else cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}