const int maxn=100010;
    int n,m,c[4],d[4];
    long long f[maxn],p;
    inline void rongchi(int i,int n,int k){
      if(i==4){p+=f[n]*k;return;}
      if((long long)c[i]*(d[i]+1)<=n)rongchi(i+1,n-c[i]*(d[i]+1),-k);
    scanf("%d%d%d%d%d",c,c+1,c+2,c+3,&m);
    f[0]=1;
    for(int i=0;i<4;i++)for(int j=c[i];j<=maxn;j++)f[j]+=f[j-c[i]];
    while(m--){
      scanf("%d%d%d%d%d",d,d+1,d+2,d+3,&n);
      p=0;
      rongchi(0,n,l);
      printf("%lld\n",p);
    }