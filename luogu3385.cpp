#include<bits/stdc++.h>
using namespace std;
#define ini(x,a) memset(x,a,sizeof(x))
#define inf 0x7f7f7f7f
const int maxn = 3000;
int n,m,t;
struct edge{
    int to,next,val;
}e[maxn<<1];
inline void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int last[maxn];
int cnt=0;
bool vis[maxn];
void addedge(int x,int y,int z){
    e[cnt].to=y;
    e[cnt].next=last[x];
    e[cnt].val=z;
    last[x]=cnt++;
}
int main(){
    cin>>t;
    while(t--){
        n=0;
        m=0;
        read(n);
        read(m);
        ini(last,-1);
        cnt=0;
        int mm=m;
        int x,y,z;
        while(m--){
            read(x);
            read(y);
            read(z);
            addedge(x,y,z);
            if(z>=0)addedge(y,x,z);
        }
        queue<int>q;
        q.push(1);
        ini(vis,1);
        vis[1]=0;
        int dis[maxn];
        ini(dis,inf);
        dis[1]=0;
        int count =0;
        int cou[maxn<<1];
        ini(cou,0);
        bool flag=0;
        while(!q.empty()&&flag==0){
            count++;
            //cout<<count<<"count\n";
            //cout<<mm*n<<'\n';
            int t=q.front();
            if(cou[t]>=n/3*2){
                cout<<"YE5\n";
                flag=1;
                break;
            }
            q.pop();
            //cout<<t<<"now & poped \n";
            vis[t]=1;
            for(int i=last[t];~i;i=e[i].next){
                int to=e[i].to;
                int val=e[i].val;
               // cout<<to<<' '<<dis[to]
                if(dis[t]+val<dis[to]){
                    dis[to]=dis[t]+val;
                    //cout<<'A';
                    if(vis[to]==1){
                        q.push(to);
                        vis[to]=0;
                        cou[to]++;
                        if(cou[t]>=n/3*2){
                            cout<<"YE5\n";
                            flag=1;
                            break;
                        }
                        //cout<<to<<' '<<dis[to]<<"in\n";
                    }
                }
            }
        }
        if(flag==0)cout<<"N0\n";
        //cout<<'\n';
    }
    return 0;
}
