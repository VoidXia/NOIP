#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int aa[8]={1,0,-1,0,0,1,0,-1};
struct node{
    int i,j;
};
int main(){
    int n,m;
    bool s[1010][1010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c[1010];
        cin>>c;
        for(int j=1;j<=n;j++){
            s[i][j]=c[j-1]-'0';
        }
    }
    int mark[1010][1010]={0};
    queue<node> q,w;
    while(m--){
        int counter=0;
        node init;
        cin>>init.i>>init.j;
        //init.step=0;
        if(mark[init.i][init.j]!=0){
            cout<<mark[init.i][init.j]<<'\n';
            continue;
        }
        mark[init.i][init.j]=1;
        q.push(init);
        w.push(init);
        //int maxx=0;
        while(!q.empty()){
            node temp;
            temp=q.front();
            q.pop();
            //cout<<temp.i<<' '<<temp.j<<'\n';
            //maxx=max(temp.step,maxx);
            //cout<<temp.step<<'\n';
            counter++;
            for(int x=0;x<4;x++){
                if(temp.i+aa[x]>=1&&temp.i+aa[x]<=n&&temp.j+aa[x+4]>=1&&temp.j+aa[x+4]<=n)
                    if(s[temp.i+aa[x]][temp.j+aa[x+4]]!=s[temp.i][temp.j]&&mark[temp.i+aa[x]][temp.j+aa[x+4]]==0){
                        node yy;
                        yy.i=temp.i+aa[x];
                        yy.j=temp.j+aa[x+4];
                        /*cout<<temp.i<<' '<<temp.j<<'\n';
                        cout<<yy.i<<' '<<yy.j<<'\n';
                        cout<<'\n';*/
                        //yy.step=temp.step+1;
                        mark[temp.i+aa[x]][temp.j+aa[x+4]]=mark[temp.i][temp.j]+1;
                        q.push(yy);
                        w.push(yy);
                    }
            }
        }
        while(!w.empty()){
            node rr;
            rr=w.front();
            w.pop();
            mark[rr.i][rr.j]=counter;
            //cout<<rr.i<<' '<<rr.j<<'\n'<<'\n';
        }
        cout<<counter<<'\n';
    }
    return 0;
}