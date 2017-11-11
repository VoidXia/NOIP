#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m, s;
struct sta{
    int nxt, to, w;
};
sta edge[500010];
int edgeNum = 0;
int head[10010] = {0};
int dis[10010] = {0};
const int inf = 100000000;
bool exist[10010] = {0};

int read()
{
    int x = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}

void add_edge(int from, int to, int w)
{
    edge[++edgeNum].nxt = head[from];
    edge[edgeNum].to = to;
    edge[edgeNum].w = w;
    head[from] = edgeNum;
}

void SPFA()
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    queue <int> qu;
    qu.push(s);
    dis[s] = 0;
    exist[s] = true;
    while(!qu.empty())
    {
        int now = qu.front();
        qu.pop();
        exist[now] = false;
        for(int i = head[now]; i != 0; i = edge[i].nxt)
        {
            int to = edge[i].to;
            int w = edge[i].w;
            if(dis[to] > dis[now] + w)
            {
                dis[to] = dis[now] + w;
                if(!exist[to])
                {
                    qu.push(to);
                    exist[to] = true;
                }
            }
        }
    }
}

int main()
{
    n = read();
    m = read();
    s = read();
    for(int i = 1; i <= m; i++)
    {
        int x = read();
        int y = read();
        int w = read();
        add_edge(x, y, w);
    }
    
    SPFA();
    for(int i = 1; i <= n; i++)
    {
        if(dis[i] >= inf)
        {
            printf("2147483647 ");
        }
        else printf("%d ", dis[i]);
    }
    
    
    
    
    
    return 0;
}
//luogu3371