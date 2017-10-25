#include<bits/stdc++.h>
using namespace std;
//#define p u/v;
int n,m,q,u,v,t;
int a[10010];
queue<int> q1;
queue<int> q2;
queue<int> q3;

int maxxx(){
  int ans=-0x7f7f7f7f;
  if(!q1.empty()&&ans<q1.front())ans=q1.front();
  if(!q2.empty()&&ans<q2.front())ans=q2.front();
  if(!q3.empty()&&ans<q3.front())ans=q3.front();
  if(ans==q1.front())q1.pop();
  else if(ans==q2.front())q2.pop();
  else if(ans==q3.front())q3.pop();
  return ans;
}
int main(){
  scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  sort(a+1,a+n+1);
  for(int i=n;i>=1;i--){
    q1.push(a[i]);
  }
  int j=0;
  for(int i=1;i<=m;i++,j+=q){
    int mm=maxxx();
    mm+=j;
    if(i%t)printf("%d ",mm);
    int pp;
    pp=mm*u/v;
    pp-=j;
    pp-=q;
    int qq;
    qq=(mm-pp);
    if(pp>qq)swap(pp,qq);
    q2.push((int)qq);
    q3.push((int)pp);
  }
  for(int i=1;!q1.empty()&&!q2.empty()&&!q3.empty();i++){
    int ansa=maxxx();
    if(i%t)==0)printf("%d ",ansa+j);
    
  }
  return 0;
  
  
}