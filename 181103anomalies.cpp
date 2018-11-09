#include<bits/stdc++.h>
namespace fast_IO {
    const int IN_LEN=10000000,OUT_LEN=10000000;
    char ibuf[IN_LEN],obuf[OUT_LEN],*ih=ibuf+IN_LEN,*oh=obuf;
    char *lastin=ibuf+IN_LEN;
    const char *lastout=ibuf+OUT_LEN-1;
    inline char getchar_() {
        if(ih==lastin)lastin=ibuf+fread(ibuf,1,IN_LEN,stdin),ih=ibuf;
        return (*ih++);
    } inline void putchar_(const char x) {
        if(ih==lastout)fwrite(obuf,1,oh-obuf,stdout),oh=obuf;
        *oh++=x;
    } inline void flush() {
        fwrite(obuf, 1, oh - obuf, stdout);
    }
}
using namespace fast_IO;
using namespace std;
template <typename T>
inline void Read(T&x) {
    char cu=getchar();
    x=0;
    bool fla=0;
    while(!isdigit(cu)) {
        if(cu=='-')fla=1;
        cu=getchar();
    }
    while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
    if(fla)x=-x;
}
template <typename T>
void printe(const T x) {
    if(x>=10)printe(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void Write(const T x) {
    if(x<0)putchar('-'),printe(-x);
    else printe(x);
}
using namespace std;
const int maxn = 150100;
//map<int,int>last;
int last[6*maxn];
#define ini(x,a) memset(x,a,sizeof(x))
struct edge{
    int to,next;
}e[6*maxn];
//int cnt1[maxn];
//vector<int>v[maxn];
int r[maxn*3];
int cnt=0;
map<int,int>cou;
void addedge(int a,int b){
    e[cnt].to=a;e[cnt].next=last[b];last[b]=cnt++;
    e[cnt].to=b;e[cnt].next=last[a];last[a]=cnt++;
}
int u[maxn*3];
bool vis[maxn];
void bfs(){
    ini(u,-1);
    u[1]=0;
    vis[1]=1;
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
            if(vis[to]==0){
                q.push(to);
                u[to]=u[t]+1;
            }
        }
    }
}
int te[maxn][3];
inline int read(){
    int x=0;char c=getchar();
    //while(!isdigit(c)){if(c=='-')a=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x;
}
int main(){
    set<pair<int,int> >temp;
    freopen("anomalies.in","r",stdin);freopen("anomalies.out","w",stdout);
    int n=read();
    int a,b,c;
    ini(last,-1);
    for(int i=1;i<=n;i++){
        te[i][0]=read();
        te[i][1]=read();
        te[i][2]=read();
        /*cou[te[i][0]];
        cou[te[i][1]];
        cou[te[i][2]];*/
        cou.insert(pair<int,int>(te[i][0],0));
        cou.insert(pair<int,int>(te[i][1],0));
        cou.insert(pair<int,int>(te[i][2],0));
        //addedge(a,b,c);
    }
    //cou[1]=0;
    int yy=0;
    for(map<int,int>::iterator it=cou.begin();it!=cou.end();it++){
        yy++;
        //cout<<(it->first)<<' '<<(it->second)<<'\n';
        r[yy]=it->first;
        it->second=yy;
        //by finding cou[x] to find its index
    }
    //cout<<yy<<'\n';
    //bool fg=0;
    pair<int,int>ab,ac,bc,ba,ca,cb;
    for(int i=1;i<=n;i++){
        a=cou[te[i][0]];b=cou[te[i][1]];c=cou[te[i][2]];
        /*fg=0;for(int i=0;i<v[a].size();i++)if(v[a][i]==b)fg=1;
        if(fg==0){addedge(a,b);v[a].push_back(b);v[b].push_back(a);}
        fg=0;for(int i=0;i<v[b].size();i++)if(v[b][i]==c)fg=1;
        if(fg==0){addedge(b,c);v[b].push_back(c);v[c].push_back(b);}
        fg=0;for(int i=0;i<v[c].size();i++)if(v[c][i]==a)fg=1;
        if(fg==0){addedge(c,a);v[c].push_back(a);v[a].push_back(c);}*/
        /*ab=make_pair(a,b);bc=make_pair(b,c);ca=make_pair(c,a);
        ba=make_pair(b,a);cb=make_pair(c,b);ac=make_pair(a,c);
        if(!temp.count(ab)){addedge(a,b);temp.insert(ab);temp.insert(ba);}
        if(!temp.count(bc)){addedge(b,c);temp.insert(bc);temp.insert(cb);}
        if(!temp.count(ca)){addedge(c,a);temp.insert(ca);temp.insert(ac);}*/
        addedge(a,b);addedge(b,c);addedge(c,a);
    }
    bfs();
    /*yy=0;
    for(map<int,int>::iterator it=cou.begin();it!=cou.end();it++){
        yy++;
        printf("%ld %d\n",it->first,u[yy]);
        //cout<<(it->first)<<' '<<r[yy]<<'\n';
    }*/
    for(int i=1;i<=yy;i++)printf("%d %d\n",r[i],u[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}