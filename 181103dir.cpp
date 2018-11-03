#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("dir.in","r",stdin);
    //freopen("dir.out","w",stdout);
    char c,d;
    d='0';
    int sum=0;
    int l=0;
    int g[100000];
    memset(g,0,sizeof(g));
    int last=0;
    bool flg=0;
    while(cin>>c){
        cout<<c<<'\n';
        if(c==')')break;
        cout<<"FUC";
        if((c!='F')&&(d=='L'||d=='R')){
            g[last++]=((d=='L')?1:-1);
            flg=1;
        }
        if((flg==1)&&(c=='F')){
            g[last++]=((d=='L')?1:-1);
            sum++;
            g[last]=0;
            for(int i=last-1;i>=0;i++){
                g[i]=g[i]+g[i+1];
                if((last-i)%4==0&&g[i]%4==0)sum--;
            }
            //memset(g,0,sizeof(g));
            last=0;
            flg=0;
        }
        if(c=='F')sum+=2;
        else sum+=1;
        d=c;
        cout<<sum<<"SUM\n";
    }
    if(c=='F')sum--;
    cout<<sum;
    cin>>sum;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}