#include<bits/stdc++.h>
using namespace std;
const int maxn = 150100;
map<int,int>last;
#define ini(x,a) memset(x,a,sizeof(x))
struct edge{
    int to,next;
}e[6*maxn];
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
    queue<int>q;
    q.push(1);
    //cout<<q.front()<<'\n';
    while(!q.empty()){
        int t=q.front();
        //cout<<q.front()<<'\n';
        q.pop();
        //cout<<last[t]<<"t\n";
        for(int i=last[t];~i;i=e[i].next){
            int to=e[i].to;
            //cout<<t<<' '<<to<<'\n';
            //cout<<cou[t]<<' '<<cou[to]<<"g\n";
            if(cou[to]==-1){
                q.push(to);
                cou[to]=cou[t]+1;
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
    freopen("anomalies.in","r",stdin);freopen("anomalies.out","w",stdout);
    int n=read();
    int a,b,c;
    for(int i=1;i<=n;i++){
        a=read();b=read();c=read();
        if(!cou.count(a))last[a]=-1;
        if(!cou.count(b))last[b]=-1;
        if(!cou.count(c))last[c]=-1;
        cou[a]=-1;
        cou[b]=-1;
        cou[c]=-1;
        addedge(a,b,c);
    }
    cou[1]=0;
    bfs();
    for(map<int,int>::iterator it=cou.begin();it!=cou.end();it++){
    	printf("%d %d\n",(it->first),(it->second));
        //cout<<(it->first)<<' '<<(it->second)<<'\n';
    }
    fclose(stdin);fclose(stdout);
    return 0;
}