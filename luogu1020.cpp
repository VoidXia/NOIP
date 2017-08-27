#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){ 
   return a>b;
}
int main(){
    while(cin>>b[n])n++;
    ans[1]=b[1];
    len=1;
    for(int i=2;i<=n;i++){
        if (b[i]<=ans[len])ans[++len]=b[i];
        else{
            pos=lower_bound(ans,ans+len,b[i],cmp)-ans;
            ans[pos]=b[i];
        }
    cout<<len<<endl;
    memset(ans,0,sizeof(ans));
    
    ans[1]=b[1];
    len=1;
    for(int i=2;i<=n;i++){
        if (b[i]>=ans[len])ans[++len]=b[i];
        else{
            pos=lower_bound(ans,ans+len,b[i])-ans;
            ans[pos]=b[i];
        }
    cout<<len<<endl;

}