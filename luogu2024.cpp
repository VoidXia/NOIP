#include<iostream>
using namespace std;
int fa[100010]={0};
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void unity(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
int main(){
    int n,k;
    cin>>n>>k;
    
}