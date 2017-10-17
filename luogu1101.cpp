#include<iostream>
using namespace std;
const char aaa[7]={'y','i','z','h','o','n','g'};
char a[101][101];
bool aa[101][101]={0};
int ans=0;
int tag=0;
int n;
void dfs(int i,int j,int num,int dire){
    if(a[i][j]!=aaa[num-1])return;
    if((i>n||i<1||j>n||j<1)&&num!=7)return;
    tag=0;
    if(num==7){tag=1;aa[i][j]=1;return;}
    if(dire==1)dfs(i+1,j,num+1,dire);
    if(dire==2)dfs(i,j+1,num+1,dire);
    if(dire==3)dfs(i,j-1,num+1,dire);
    if(dire==4)dfs(i-1,j,num+1,dire);
    if(dire==5)dfs(i+1,j-1,num+1,dire);
    if(dire==6)dfs(i+1,j+1,num+1,dire);
    if(dire==7)dfs(i-1,j+1,num+1,dire);
    if(dire==8)dfs(i-1,j-1,num+1,dire);
    if(tag==1){
        aa[i][j]=1;

    }

}
int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='y'){

                dfs(i,j,1,1);
                dfs(i,j,1,2);
                dfs(i,j,1,3);
                dfs(i,j,1,4);
                dfs(i,j,1,5);
                dfs(i,j,1,6);
                dfs(i,j,1,7);
                dfs(i,j,1,8);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(aa[i][j]==1)cout<<a[i][j];else cout<<'*';
        }
        cout<<'\n';
    }
    return 0;

}