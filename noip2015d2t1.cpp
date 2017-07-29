//
//  main.cpp
//  aaa
//
//  Created by 夏潇恒 on 2017/7/27.
//  Copyright © 2017年 夏潇恒. All rights reserved.
//

#include<iostream>
#include<cstdio>
using namespace std;
int ll,n,m,a[55555];
bool judge(int x)
{
    int w,pos,i;
    for (pos=w=0,i=1;i<=n;i++)
        if (a[i]-pos<x) ++w; else pos=a[i];
            return w<=m;
}
int main(){
    int ans = 0,l,mid,r,ii;
   // cin>>ll>>n>>m;
   // for(p=1;p<=n;p++) cin>>a[p];
    for(cin>>ll>>n>>m,ii=1;ii<=n;ii++) cin>>a[ii]; a[++n]=ll;
    for (l=0,r=ll;l<=r;)
        if(judge(mid=(l+r)>>1)) {ans=mid; l=mid+1;} else r=mid-1;
    cout<<ans<<endl;
    return 0;
}