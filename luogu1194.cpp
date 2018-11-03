#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int fa[510];
int a,b;
int cnt=1;
void init(){
    for(int i=1;i<=b;i++)fa[i]=i;
}
int find(int x){
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

bool check(int x,int y){return find(x)==find(y);}

struct node{
    int x,y,val;
};

bool operator < (const node &a, const node &b){
    return a.val>b.val;
}

int main(){
    cin>>a>>b;
    init();
    priority_queue<node>q;
    //int c=0;
    for(int i=1;i<=b;i++){
        for(int j=1;j<=b;j++){
            int x;
            cin>>x;
            //cout<<x<<'\n';
            if(i<j){
                if(x==0)x=a;
                q.push((node){i,j,x});
                //cout<<i<<' '<<j<<' '<<x<<'\n';
            }
        }
    }
    int ans=a;
    while(cnt!=b){
        node t=q.top();
        q.pop();
        //cout<<t.val<<'\n';
        if(find(t.x)!=find(t.y)){
            //cout<<fa[t.x]<<' '<<fa[t.y]<<'\n';
            //cout<<find(t.x)<<' '<<find(t.y)<<"\n\n";
            fa[find(t.x)]=find(t.y);
            cnt++;
            ans+=t.val;
            //cout<<t.x<<' '<<t.y<<' '<<t.val<<'\n';
        }
    }
    ans=(ans<a*b)?ans:a*b;
    cout<<ans;
    return 0;
}