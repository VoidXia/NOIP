#include<bits/stdc++.h>
#include<cstring>
using namespace std;
inline int read(){
    int c=getchar();
    return (c-'0');
}
int main(){
    string s;int k;
    cin>>s>>k;
    int len=s.length();
    bool a[20][20];
    memset(a,0,sizeof(a));
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int kk=0;kk<=9;kk++)
                if(a[j][i]==1&&a[i][kk]==1)a[j][kk]=1;
    int g[510];
    memset(g,0,sizeof(g));
    g[0]=1;
    int q[15];
    memset(q,0,sizeof(q));
    for(int i=0;i<=9;i++){
        a[i][i]=1;
        for(int j=0;j<=9;j++){
            if(a[i][j]==1)q[i]++;
        }
    }
    for(int i=0;i<len;i++){
        int z=0;
        int c=q[s[i]-'0'];
        //cout<<c<<'\n';
        for(int j=0;j<=500;j++){
            //cout<<j<<' '<<g[j]<<'\n';
            g[j]=(g[j]*c)+z;
            z=g[j]/10;
            g[j]=g[j]%10;
            //cout<<j<<' '<<g[j]<<'\n';
        }
    }
    int u=500;
    while(g[u]==0)u--;
    for(int i=u;i>=0;i--){cout<<g[i];}
    return 0;
}