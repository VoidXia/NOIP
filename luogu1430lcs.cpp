#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,a[100000]={0},b[100000]={0},c[2][100000]={0},l,k;
    cin>>n;
    for (i=1;i<=n;i++)cin>>a[i];
    for (i=1;i<=n;i++)cin>>b[i];
    for (i=1,l=2;i<=n;i++){
        l++;
        if (l==3) {
            l=1;
            for (k=0;k<=n;k++)c[0][k]=c[2][k];
        }
        for(k=0;k<=n;k++)c[l][k]=0;
        for (j=1;j<=n;j++){
            
            if (a[i]==b[j]){c[l][j]=c[l-1][j-1]+1;cout<<i<<' '<<j<<' '<<c[l][j]<<' '<<' ';}
            else c[l][j]=max(c[l-1][j],c[l][j-1]);
        }
        
    }
    cout<<c[l][n]<<endl;
    return 0;
}//optimized failed

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,a[1000]={0},b[1000]={0},c[1000][1000]={0};
    cin>>n;
    for (i=1;i<=n;i++)cin>>a[i];
    for (i=1;i<=n;i++)cin>>b[i];
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            if (a[i]==b[j]){c[i][j]=c[i-1][j-1]+1;cout<<i<<' '<<j<<' '<<c[i][j]<<' '<<' ';}
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
        
    }
    cout<<c[n][n]<<endl;
    return 0;
}//original

/*#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,i,j,a[100]={0},b[100]={0},c[2][100]={0},l,p;
    cin>>n;
    for (i=1;i<=n;i++)cin>>a[i];
    for (i=1;i<=n;i++)cin>>b[i];
    for (i=1,l=2;i<=n;i++){
        //cout<<' '<<i<<' '<<b[i]<<' ';
        l++;
        if (l==3) {
            l=1;
            for (p=0;p<=n;p++)c[0][p]=c[2][p];
        }
        p=0;
        while(p<=n){p++;c[l][p]=0;}
        for (j=1;j<=n;j++){
            
            if (a[i]==b[j]){c[l][j]=c[l-1][j-1]+1;cout<<i<<' '<<j<<' '<<c[l][j]<<' '<<' ';}
            else c[l][j]=max(c[l-1][j],c[l][j-1]);
        }
        
    }
    
    cout<<c[l][n]<<endl;
    return 0;
}*/



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[500000],b[500000],ans[500000]={0},pos,len;
    cin>>n;
    for(int i=1;i<=n;i++){
        int y=0;
        cin>>y;
        a[y]=i;}
    for(int i=1;i<=n;i++)cin>>b[i],b[i]=a[b[i]];
    ans[1]=b[1];
    len=1;
    for(int i=2;i<=n;i++){
        if (b[i]>=ans[len])ans[++len]=b[i];
        else{
            pos=lower_bound(ans,ans+len,b[i])-ans;
            ans[pos]=b[i];
        }
    }
    cout<<len;
}//luogu1439AC
