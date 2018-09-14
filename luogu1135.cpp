#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a;
    cin>>b;
    int k[210]={0};
    //int bb[210]={0};
    int st[210]={0};
    for(int i=1;i<=n;i++)cin>>k[i];
    //int ans=-1;
    queue<int> q;
    q.push(a);
    st[a]=0;
    //bb[a]=1;
    //int itr=-1;
    if(a==b){cout<<'0';return 0;}
    while(st[b]==0&&!q.empty()){
        //itr++;
        //for(unsigned int i=1;i<=q.size();i++){
            int u=q.front();
            //cout<<u<<'\n';
            //if(u==b){ans=1;break;}
            q.pop();
           // bb[u]=1;
            //cout<<q.front()<<"\n\n";
            if(u+k[u]<=n&&st[u+k[u]]==0)q.push(u+k[u]),st[u+k[u]]=st[u]+1;
            if(u-k[u]>=1&&st[u-k[u]]==0)q.push(u-k[u]),st[u-k[u]]=st[u]+1;
        //}
    }
   // cout<<ans<<' ';
    if(st[b])cout<<st[b];else cout<<"-1";
    return 0;
}