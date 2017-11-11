#include<bits/stdc++.h>
using namespace std;
int read()
{
int x=0;int f=1;char ch=getchar();
while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}
bool prime[10001000];
int rec[10001000];
int cnt;
int n,m;
int init(int n)
{
    cnt=0;
    memset(prime,true,sizeof prime);
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        rec[cnt++]=i;
        for(int j=0;j<cnt&&rec[j]<=n/i;++j)
        {
            prime[rec[j]*i]=false;
            if(i%rec[j]==0) break;
        }
    }
}
int main()
{
    n=read();
    m=read();
    init(n);int x;
    for(int i=1;i<=m;i++)
    {
        x=read();
        if(prime[x]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}