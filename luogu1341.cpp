#include<iostream>
using namespace std;
struct edge{
    int a,b;
}a[2700];
struct num{
    int va,in;
}b[210];
bool cmp(num a,num b){
    if(a.va!=b.va)return a.va<b.va;
    else return a.in<b.in;
}
int main(){
    int n;
    for(int i=1;i<=n;i++){
        char c,d;
        cin>>c>>d;
        a[i].a=c-'A';
        a[i].b=d-'A';
        b[2*i-1].va++;
        b[2*i-1].in=c-'A';
        b[2*i].va++;
        b[2*i].in=d-'A';
    }
    for(int i=1;i<=n;i++){
        /*sort(b+1,b+2*n,cmp);
        int j=1;
        while(b[j].va!=1)j++;
        while()*/
        for(int j=1;j<=n;j++){
            
        }
    }


}