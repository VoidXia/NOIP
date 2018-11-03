#include<bits/stdc++.h>
using namespace std;
#define ini(x,a) memset(x,a,sizeof(x));
const int maxn = 2010;
int n;
int dp[maxn],a[maxn];
inline int read(){
    int x=0,a=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')a=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return a*x;
}
struct edge{
    int to,next;
}e[maxn<<1];
int last[maxn];
int cnt=0;
void addedge(int x,int y){
    e[cnt].to=y;
    e[cnt].next=last[x];
    last[x]=cnt++;
}
int col[maxn];
void bfs(int s){
    queue<int>q;
    q.push(s);
    col[s]=1;
    int fls[maxn];
    int cc=0;
    fls[++cc]=s;
    int one=1,zero=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        fls[++cc]=t;
        for(int i=last[t];~i;i=e[i].next){
            int to=e[i].to;
            if(col[to]==-1){
                if(col[t]==1)col[to]=0,zero++;
                if(col[t]==0)col[to]=1,one++;
                q.push(to);
            }
            if(col[to]==col[t]){
                cout<<'0';
                exit(0);
            }
        }
    }
    //if(one<zero){
    //    for(int i=1;i<=cc;i++)col[i]^=1;
    //}
}
int main(){
    ini(col,-1);
    ini(last,-1);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[n]=a[n];
    for(int i=n-1;i>=1;i--)dp[i]=min(a[i],dp[i+1]);
    //for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    //cout<<"dp\n";
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]&&dp[j+1]<a[i]){
                //cout<<i<<' '<<j<<"addedge\n";
                addedge(i,j);
                addedge(j,i);
            }
        }
    }
    for(int i=1;i<=n;i++)if(col[i]==-1)bfs(i);
    //for(int i=1;i<=n;i++)cout<<col[i]<<'\n';
    /*int s1=1e9,c1=0;
    int s2=1e9,c2=0;
    for(int i=1;i<=n;i++){
        //if(col[i]==1){cout<<"a ";}
        //if(col[i]==0)cout<<"b ";
        if(col[i]==1){
            if(a[i]>s1){
                while(c1--)cout<<"b ";
                s1=0;
            }
            else {
                s1=a[i];
                c1++;
            }
            s1=a[i];
            c1++;
            cout<<"a ";
        }
        if(col[i]==0){
            if(a[i]>s2){
                while(c2--)cout<<"d ";
                s2=0;
            }
            else {
                s2=a[i];
                c2++;
            }
            s2=a[i];
            c2++;
            cout<<"c ";
        }     
    }*/
    /*int ct=1;
    stack<int> s1,s2;
    for(int i=1; i<=n; ++i)
    {
        if(col[i]==1)
        {
            s1.push(a[i]);
            cout<<"a ";
        }
        else
        {
            s2.push(a[i]);
            cout<<"c ";
        }
        while((!s1.empty() && s1.top()==ct) || (!s2.empty() && s2.top()==ct))
        {
            if(!s1.empty() && s1.top()==ct)
            {
                s1.pop();
                cout<<"b ";
            }
            else
            {
                s2.pop();
                cout<<"d ";
            }
            ++ct;
        }
    }
    */
    int yy=1;
    stack<int>s1;
    stack<int>s2;
    for(int i=1;i<=n;++i){
        //cout<<a[i]<<'\n';
        if(col[i]==1){
            s1.push(a[i]);
            cout<<"a ";
        }
        else{
            s2.push(a[i]);
            cout<<"c ";
        }
        while((!s1.empty()&&s1.top()==yy)||(!s2.empty()&&s2.top()==yy))
        {
            if(!s1.empty() && s1.top()==yy)
            {
                s1.pop();
                cout<<"b ";
            }
            else 
            {
                s2.pop();
                cout<<"d ";
            }
            ++yy;
        }
    }
    return 0;
}