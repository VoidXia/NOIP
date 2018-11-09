#include<bits/stdc++.h>
using namespace std;
const int maxn = 310;
//int ans[1010];
/*struct bign
{
       int len,a[1010];
       bign(){len=1;memset(a,0,sizeof(a));}
       bign operator = (const char* num)
       {
            len=strlen(num);
            for (int i=0;i<len;i++)a[i]=num[len-i-1]-'0';
            while (a[len-1]==0)--len;
            return *this;
       }
       void clean() 
       {
            while(len > 1 && a[len-1]==0) len--;
       }
       bign operator = (int num)
       {
            char s[1010];
            sprintf(s,"%d",num);
            *this=s;
            return *this;
       }
       bign(int num){*this=num;}
       bign(const char* num){*this=num;}
       string str()const
       {
              string res="";
              for (int i=0;i<len;i++)res=res+(char)(a[len-i-1]+'0');
              if (res=="")res="0";
              return res; 
       }
       bign operator +(const bign& b)const
       {
            bign c;
            c.len=max(len,b.len);
            for (int i=0;i<c.len;i++)
            {
                c.a[i]+=a[i]+b.a[i];
                c.a[i+1]+=c.a[i]/10;
                c.a[i]%=10;
            }
            if (c.a[c.len]!=0)c.len++;
            return c;
       }
       bign operator +=(const bign& b)
       {*this=*this+b;return *this;}
}ans;
ostream& operator << (ostream &out,const bign& x)
{
         out<<x.str();
         return out;
}*/
inline int read(){
    int x=0; char c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x;
}
int main(){
    //memset(ans,0,sizeof(ans));
    int n=read();
    int a[maxn];
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int b[maxn];
    int q=n;
    bool flg=0;
    for(int i=1;i<=n;i++){
        //cout<<q<<' ';
        b[i]=a[q];
        if(flg==0)q=n+1-q;
        if(flg==1)q=n-q;
        flg^=1;
    }
    //cout<<'\n';
    b[0]=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        int y=(b[i]-b[i-1])*(b[i]-b[i-1]);
        //cout<<y<<'\n';
        ans+=y;
    }
    cout<<ans;
    return 0;
}