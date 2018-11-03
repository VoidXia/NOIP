#include<bits/stdc++.h>
using namespace std;
#define ini(x,a) memset(x,a,sizeof(x))
inline long read(){
    long x=0;long a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}
inline double getdis(long x1,long y1,long z1,long x2,long y2,long z2){
    return (double)sqrt((long long)((x2-x1)*(x2-x1)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)));
}
const long maxn = 1050;
long fa[maxn];
long long a[maxn][3];
long find(long x){return (fa[x]==x)?fa[x]:find(fa[x]);}
int main(){
    long t=read();
    while(t--){
        long n=read(),h=read(),r=read();
        bool fg=0;
        ini(a,0);
        long f1[maxn];
        long f2[maxn];
        long cnt1=0,cnt2=0;
        ini(f1,0);ini(f2,0);
        for(long i=1;i<=n;i++)fa[i]=i;
        for(long i=1;i<=n;i++){
            a[i][0]=read();a[i][1]=read();a[i][2]=read();
            if(a[i][2]+r>=h)f1[cnt1++]=i;
            if(a[i][2]-r<=0)f2[cnt2++]=i;
            for(long j=1;j<i;j++){
                if(getdis(a[i][0],a[i][1],a[i][2],a[j][0],a[j][1],a[j][2])<=2*r){
                    //merge
                    //prlongf("merge %d %d  ",i,j);
                    if(find(i)!=find(j)){
                        fa[fa[i]]=find(fa[j]);
                    }
                }
            }
        }
        //cout<<n<<' '<<ans<<'\n';
        //cout<<fg1<<' '<<fg2<<'\n';
        //prlongf("fg%d\n",fg);
        for(long i=0;i<cnt1;i++){
            for(long j=0;j<cnt2;j++){
                if(find(f1[i])==find(f2[j])){fg=1;break;}
            }
        }
        if(fg==1)cout<<"Yes\n";else cout<<"No\n";
    }
    return 0;
}