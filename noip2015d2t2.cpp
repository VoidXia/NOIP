#include<iostream>
using namespace std;
char a[1000],b[200];
int w,ans,t,i,y;

int dfs(int x,o)
{
    for (int i=o;i<=n;i++) if (a[i]=b[x]) {if (x<m) ans++,dfs(x+1,i); else ans++};
}

int main()
{
    cin>>n>>m>>k;
    for (y=1;y<=n;y++) cin>>a[i];
    for (y=1;y<=m;y++) cin>>b[i];
    dfs(1,1);
    cout<<ans;
    return 0;
}