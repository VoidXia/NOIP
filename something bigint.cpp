#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long

using namespace std;
struct bign
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
       bign operator *(const bign& b)const
       {
            bign c;
            c.len=len+b.len;
            for (int i=0;i<len;i++)
            for (int j=0;j<b.len;j++)
            c.a[i+j]+=a[i]*b.a[j];
            for (int i=0;i<c.len;i++)
            {
                c.a[i+1]+=c.a[i] /10;
                c.a[i]%=10;
            }
            c.clean();
            return c;
       }
       bign operator *=(const bign& b)
       {*this=*this*b;return *this;}
       bign operator / (const int& num)
       {
            bign c;c.len=len;
            long long rest=0;
            for (int i=len-1;i>=0;i--)
            {
                rest=rest*10+a[i];
                if (rest>=num)
                {
                              c.a[i]=rest/num;
                              rest%=num;
                }
            }
            c.clean();
            return c;
       }              
       bign operator /= (int b)
       {*this=*this/b;return *this;}
       bign operator - (const bign& b)const
       {
            bign c;c.len=len-b.len+1;
            for (int i=0;i<len;i++)
            c.a[i]=a[i]-b.a[i];
            for (int i=0;i<len;i++)
            if (c.a[i]<0){c.a[i]+=10;c.a[i+1]-=1;}
            c.clean();
            return c;
       }
                
};
istream& operator >> (istream &in,bign& x)
{
         string s;
         in>>s;
         x=s.c_str();
         return in;
}
ostream& operator << (ostream &out,const bign& x)
{
         out<<x.str();
         return out;
}

const int maxn = 1050;
int a[maxn][maxn], fa[maxn*maxn], cnt[maxn*maxn], n, m;
int id(int x, int y){
    return x * n + y;
}
int find1(int x){
    return fa[x] == x ? x : fa[x] = find1(fa[x]);
}
void union1(int x, int y){
    int fx = find1(x), fy = find1(y);
    if (fx != fy){
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
    }
}
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main()
{
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) fa[id(i,j)] = id(i,j);
    rep(i, n) rep(j, m) cnt[id(i,j)] = 1;
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    rep(i, n) rep(j, m) rep(k, 4){
        int nx = i + dx[k], ny = j + dy[k];
        if (a[i][j] && a[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m)
            union1(id(i,j), id(nx,ny));
    }
    bign ans = 0;
    rep(i, n) rep(j, m){
        int iid = id(i,j);
        if (fa[iid] == iid && a[i][j]) {
            bign tmp = cnt[iid];
            ans = ans + tmp * tmp * tmp * tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}


