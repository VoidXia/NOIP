#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0;char c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x;
}
int main(){
    //freopen("store.in","r",stdin);
    //freopen("store.out","w",stdout);
    unsigned long long t,m,i,j;
    unsigned long long v[100100],k[100100],a[100100];
    m=read();t=read();
    for (i=1;i<=m;i++){v[i]=read();k[i]=read();if(k[i]>=v[i]){cout<<-1<<'\n';return 0;}}
    memset(a,0,sizeof(a));
    for (i=1;i<=m;i++){
        for (j=v[i];j<=t;j++){
            a[j]=max(a[j],a[j-v[i]+k[i]]+1);
            //cout<<' '<<j<<' '<<a[j]<<'\n';
        }
        //cout<<i<<' '<<a[t]<<'\n';
    }
    //for (i=t;i>=1;i--)if (a[i]>0){
    cout<<a[t]<<'\n';
    //    break;
 //   }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}