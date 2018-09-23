#include<iostream>
#include<algorithm>
#include<queue>
#include<iomanip>
int aaa[8]={2,2,1,1,-1,-1,-2,-2};
int bbb[8]={1,-1,2,-2,2,-2,1,-1};
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int s[410][410]={0};
    queue<int> q,w;
    s[a][b]=1;
    q.push(a);w.push(b);
    int aa,bb;
    while(!q.empty()){
        aa=q.front();bb=w.front();
        q.pop();w.pop();
        for(int i=0;i<8;i++)
            if(s[aa+aaa[i]][bb+bbb[i]]==0&&aa+aaa[i]>=1&&aa+aaa[i]<=n&&bb+bbb[i]>=1&&bb+bbb[i]<=m)
            s[aa+aaa[i]][bb+bbb[i]]=s[aa][bb]+1,
            q.push(aa+aaa[i]),w.push(bb+bbb[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout<<s[i][j]-1<<' ';
            cout<<left<<setw(5)<<s[i][j]-1;//!!!!!!!!
        }
        cout<<'\n';
    }
    return 0;
}