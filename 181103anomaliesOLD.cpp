#include<bits/stdc++.h>
using namespace std;
const int maxn = 150050;
//map<int,int>last;
int last[6*maxn];
#define ini(x,a) memset(x,a,sizeof(x))
struct edge{
    int to,next;
}e[6*maxn];
int r[maxn];
int cnt=0;
map<int,int>cou;
void addedge(int a,int b,int c){
    e[cnt].to=a;e[cnt].next=last[b];last[b]=cnt++;
    e[cnt].to=b;e[cnt].next=last[a];last[a]=cnt++;
    e[cnt].to=c;e[cnt].next=last[b];last[b]=cnt++;
    e[cnt].to=a;e[cnt].next=last[c];last[c]=cnt++;
    e[cnt].to=b;e[cnt].next=last[c];last[c]=cnt++;
    e[cnt].to=c;e[cnt].next=last[a];last[a]=cnt++;
}
int u[maxn];
void bfs(){
    ini(u,-1);
    u[1]=0;
    queue<int>q;
    q.push(1);
    //cout<<q.front()<<'\n';
    while(!q.empty()){
        int t=q.front();
        //cout<<t<<'\n';
        //cout<<q.front()<<'\n';
        q.pop();
        //cout<<last[t]<<"t\n";
        for(int i=last[t];~i;i=e[i].next){
            int to=e[i].to;
            //cout<<t<<' '<<to<<'\n';
            //cout<<cou[t]<<' '<<cou[to]<<"g\n";
            if(u[to]==-1){
                q.push(to);
                u[to]=u[t]+1;
            }
        }
    }
}
int te[maxn][3];
inline int read(){
    int x=0,a=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*a;
}
int main(){
    //freopen("anomalies.in","r",stdin);freopen("anomalies.out","w",stdout);
    int n=read();
    int a,b,c;
    ini(last,-1);
    for(int i=1;i<=n;i++){
        te[i][0]=read();
        te[i][1]=read();
        te[i][2]=read();
        if(!cou.count(te[i][0]))cou[te[i][0]]=0;
        if(!cou.count(te[i][2]))cou[te[i][2]]=0;
        if(!cou.count(te[i][1]))cou[te[i][1]]=0;
        //addedge(a,b,c);
    }
    //cou[1]=0;
    int yy=0;
    for(map<int,int>::iterator it=cou.begin();it!=cou.end();it++){
        yy++;
        //cout<<(it->first)<<' '<<(it->second)<<'\n';
        r[yy]=it->first;
        cou[it->first]=yy;
        //by finding cou[x] to find its index
    }
    //cout<<yy<<'\n';
    for(int i=1;i<=n;i++){
        a=te[i][0];b=te[i][1];c=te[i][2];
        addedge(cou[a],cou[b],cou[c]);
    }
    bfs();
    /*yy=0;
    for(map<int,int>::iterator it=cou.begin();it!=cou.end();it++){
        yy++;
        printf("%ld %d\n",it->first,u[yy]);
        //cout<<(it->first)<<' '<<r[yy]<<'\n';
    }*/
    //cout<<cnt<<'\n';
    for(int i=1;i<=yy;i++)printf("%d %d\n",r[i],u[i]);
    //fclose(stdin);fclose(stdout);
    return 0;
}