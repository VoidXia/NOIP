#include<iostream>
#include<algorithm>
#define modd 1000000007
using namespace std;
int main(){
    int n,m,kk;
    int f[3][1010][1010]={0};
    int s[3][1010][1010]={0};
    scanf("%d%d%d\n",&n,&m,&kk);
    char a[1002],b[1002];
    scanf("%s",a+1);
    scanf("%s",b+1);

    int past=0,now=1;
    f[0][0][0]=1;
    for(int e=1;e<=n;e++){
        f[now][0][0]=1;
        for(int j=1;j<=m;j++){
            for(int k=1;k<=kk;k++){
                if(a[e]==b[j])s[now][j][k]=(f[past][j-1][k-1]+s[past][j-1][k])%modd;
                else s[now][j][k]=0;
                f[now][j][k]=(f[past][j][k]+s[now][j][k])%modd;
            }
        }
        swap(past,now);
    }
    cout<<f[past][m][kk];
    return 0;
}