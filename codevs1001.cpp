
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
int n,m;
using namespace std;
int fa[100010];
int find(int x){
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b)fa[b]=a;
}
int gcd(int x,int y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
struct node{
    int x,y,v;
}a[100010];
bool cmp(const node& a,const node&b){
    return a.v<b.v;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
    }
    sort(a+1,a+m+1,cmp);
    int s,t;
    cin>>s>>t;
    init();
    for(int i=1;i<=m;i++){
        merge(a[i].x,a[i].y);
    }
    if(find(s)!=find(t)){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int ans1=214740;
    int ans2=1;
    for(int i=1;i<=m;i++){
        init();
        for(int j=i;j<=m;j++){
            merge(a[j].x,a[j].y);
            //cout<<a[j].x<<' '<<a[j].y<<'\n';
            if(find(s)==find(t)){
                //cout<<"fuck";
                    //                cout<<a[j].v*100/a[i].v<<'\n';
                    //cout<<ans1*100/ans2<<'\n';
                //    cout<<(ans1*100/ans2>a[j].v*100/a[i].v)?1:0;
               // cout<<xx;
                if(ans1*1000/ans2>a[j].v*1000/a[i].v){
                 //   cout<<'j'<<'\n';
                    ans1=a[j].v;
                    ans2=a[i].v;
                    //cout<<ans1<<' '<<ans2<<'\n';
                }
                int xx=gcd(ans1,ans2);
                ans1/=xx;
                ans2/=xx;
                break;
            }
        }
    }
    cout<<ans1<<((ans2==1)?' ':'/');
    if(ans2!=1)cout<<ans2;
    return 0;
}