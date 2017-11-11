#include<queue>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
    priority_queue<int> q;
    int n;
    cin>>n;
    int a[100010];
    int b[100010];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    int no=0;
    q.push(a[1]*b[1]);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            
        }
    }
}