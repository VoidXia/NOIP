#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int f[51][100001],s[200011],t[501],n,k,p,tot;
struct po
{
    int w;
    int v;
};
po a[200001];
int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].w>>a[i].v;
        f[a[i].w][++t[a[i].w]]=i;//记录第i个是每种色调的第几个
        if(a[i].v<=p)//维护前缀和
        s[i]=s[i-1]+1;
        else
        s[i]=s[i-1];
    }
    for(int i=0;i<=k-1;i++)//暴力枚举所有色调
    {
        for(int j=1;j<t[i];j++)//使用前缀和进行枚举，枚举每个区间是否满足条件。
         for(int q=j+1;q<=t[i];q++)
         {
             if(s[f[i][q]]-s[f[i][j]-1])//如果能够满足现在的，那么以j为初始的后面的所有区间都能满足，所以直接加上然后break
             {
                 tot+=t[i]-q+1;//后面的所有种类一共是q-1种，想不明白的自己去画图。
                 break;
                 //optimize
            }
         }
    }
    cout<<tot;
}