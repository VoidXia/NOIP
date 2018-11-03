#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#define MAXN 1005
#define INF 0x7f7f7f7f
#define B 1
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
int n;
int a[MAXN],f[MAXN];
vector<int> e[MAXN];
int color[MAXN];
stack<int> s1,s2;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    color[s]=B;
    while(!q.empty())
    {
        int now=q.front();
        for(int i=0; i<e[now].size(); ++i)
        {
            int next=e[now][i];
            if(color[next]==-1)
            {
                color[next]=color[now]^1;
                q.push(next);
            }
            else if(color[next]!=(color[now]^1))
            {
                cout<<0;
                exit(0);
            }
        }
        q.pop();
    }
}
int main()
{
    memset(color,-1,sizeof(color));
    cin>>n;
    for(int i=1; i<=n; ++i)cin>>a[i];
    f[n+1]=INF;
    for(int i=n; i>=1; --i)f[i]=min(f[i+1],a[i]);
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            if(a[i]>f[j+1] && a[i]<a[j])
                e[i].push_back(j),e[j].push_back(i);
    for(int i=1; i<=n; ++i)
        if(color[i]==-1)
            bfs(i);
    int cnt=1;
    for(int i=1; i<=n; ++i)
    {
        if(color[i]==B)
        {
            s1.push(a[i]);
            cout<<"a ";
        }
        else
        {
            s2.push(a[i]);
            cout<<"c ";
        }
        while((!s1.empty() && s1.top()==cnt) || (!s2.empty() && s2.top()==cnt))
        {
            if(!s1.empty() && s1.top()==cnt)
            {
                s1.pop();
                cout<<"b ";
            }
            else
            {
                s2.pop();
                cout<<"d ";
            }
            ++cnt;
        }
    }
    return 0;
}