#include<iostream>
#include<cstdio>
#include<algorithm>
#define II int
#define R register
#define I 123456
using namespace std;

struct node {
    II x,y;
    II w;
}aa[I];

II fa[I];

II n,m,ans,_tot;

bool maP(node a1,node a2)
{
    return a1.w>a2.w;
}

II find(R II x)
{
    if(fa[x]==x) return x;
      else return fa[x]=find(fa[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    _tot=22001;
    //监狱编号在>n时认为已经放到监狱中了
    //所以，为了避免与初始状态重复，我们令最小的监狱编号为n范围之外
    for(R II i=1;i<=40000;i++) fa[i]=i;
    for(R II i=1;i<=m;i++) scanf("%d%d%d",&aa[i].x,&aa[i].y,&aa[i].w);
    sort(aa+1,aa+m+1,maP);
    ans=0;
    for(R II i=1;i<=m;i++)
    {
        R II X=find(aa[i].x);
        R II Y=find(aa[i].y);
        if(X<=n&&Y<=n) fa[X]=++_tot,fa[Y]=++_tot;
        //情况<1>；
          else if(X<=n&&Y>n) fa[X]=fa[Y]^1;
          //情况<2>之一；
            else if(X>n&&Y<=n) fa[Y]=fa[X]^1;
            //情况<2>之二；
              else if(X>n&&Y>n){
                  if(X==Y) {
                      printf("%d\n",aa[i].w);
                      return 0;
                  }
                  //情况<4>;
                  if(X!=(Y^1)){
                      R II XXOR=X^1;
                      R II YXOR=Y^1;
                      fa[Y]=XXOR;
                      fa[YXOR]=X;
                  }
                  //情况<3>；
              }
    }
    cout<<0<<endl;
    return 0;
}