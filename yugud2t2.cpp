#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
    long long n,m,i,j,x,y,r,o,ans;
    bool a[5000][5000];
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            a[i][j]=1;
    for (o=1;o<=m;o++){
        cin>>x>>y>>r;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++){
                if (sqrt((double)(i-x)*(i-x)+(j-y)*(j-y))<=r) a[i][j]=0;
            }
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (a[i][j]==1) ans++;
    cout<<ans<<endl;
    return 0;
    
}