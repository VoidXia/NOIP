#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[200][200]={0};
int fx,fy,sx,sy,tot=0;
void dfs(int x,int y){
    if (x==fx&&y==fy&&a[x][y]==0){tot++;return;}
    if(x<1||x>n||y<1||y>m||a[x][y]==1)return;
    a[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    a[x][y]=0;
    return;
}

int main(){
    memset(a,0,sizeof(a));
    ios::sync_with_stdio(false);
    //深夜刷水题
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    dfs(sx,sy);
    cout<<tot<<endl;
    return 0;
}