#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
//Plz be aware that this code is partly refered or copied others code
//Further watches are expected
using namespace std;
struct node{
    int w,v;
}a[200010];

int main(){
    int n,k,p;
    int s[200010];//PrefixSum
    cin>>n>>k>>p;
    int f[51][100001];
    int t[501];
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].w,&a[i].v);
        f[a[i].w][++t[a[i].w]]=i;
        s[i]=s[i-1];
        if(a[i].v<=p)s[i]++;
    }
    int tot=0;
    for(int i=0;i<k;i++){//color
        for(int j=1;j<t[i];j++){
            for(int k=j+1;k<=t[i];k++){//qujian
                if(s[f[i][k]]>s[f[i][j]-1]){
                    tot+=t[i]-k+1;
                    break;
                }
            }
        }
    }
    cout<<tot;
    return 0;
}