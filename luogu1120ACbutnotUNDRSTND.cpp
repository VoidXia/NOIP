#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
//木棍棍
bool cmp(int a,int b){
    return a>b;
}
int ans=0;
int n;
int a[70];
int cnt=0;
int summ=0;
int maxnn=0;
bool q,pd[120];
void dfs(int record,int sum,int step,int begin){
    if(q)return;
    if(step*record==summ){
        ans=record;
        q=1;
        return;
    }
    if(sum==record)dfs(record,0,step+1,1);
    for(int i=begin;i<=n;i++){
        if(!pd[i]&&a[i]+sum<=record){
            pd[i]=1;
            dfs(record,sum+a[i],step,i+1);
            pd[i]=0;
            if(sum+a[i]==record||sum==0)break;
            while(a[i]==a[i+1])i++;
        }
    }
}

using namespace std;
int main(){
    scanf("%d",&n);
    for(/*register*/ int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x<=50){
            a[++cnt]=x;
            summ+=a[cnt];
            maxnn=max(a[cnt],maxnn);
        }
    }
    ans=summ;
    sort(a+1,a+n+1,cmp);
   // int sum=0;
   // for(register int i=n;i>=1;i--)if(a[i]>50)n--;else break;
   // for(register int i=1;i<=n;i++)sum+=a[i];

    for(int i=maxnn;i<=summ/2;i++){
        if(summ%i==0)//get;
           dfs(i,0,0,1);
        if (q) break;
    }
    cout<<ans;
 //   cout<<a[5];
    return 0;
}