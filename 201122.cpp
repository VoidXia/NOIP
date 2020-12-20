#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
const bool debugflag=1;
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    int n,tmp;
    scanf("%d",&n);
    int i=n-1;
    while(n--){
        scanf("%d",&tmp);
        q.push(tmp);
    }
    tmp=q.top();q.pop();
    int ans=0;ans-=tmp;
    while(!q.empty()&&i--){
        ans+=tmp;if(debugflag)cout<<tmp<<'\n';
        q.push(tmp);
        tmp=0;
        tmp+=q.top();if(debugflag)cout<<q.top()<<'+';
        q.pop();
        tmp+=q.top();if(debugflag)cout<<q.top()<<'=';
        q.pop();
    }ans+=tmp;if(debugflag)cout<<tmp<<'\n';
    cout<<ans;
    return 0;
}