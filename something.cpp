#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int mo;
    int t;
    scanf("%d%d",&t,&mo);
    while(t--)
    {    //cin>>mo;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        int aa=a,bb=b;
        int cnt=0;
        bool f=0;
        while(a%mo!=0&&b%mo!=0){
            cnt++;
            if(cnt&1)a=(a+b)%mo;else b=(b+a)%mo;
            //cout<<a<<' '<<b<<'\n';
            if(a==aa&&b==bb&&(cnt&1)==1){cout<<"error"<<"\n";f=1;break;}
        }
        //cout<<cnt<<' '<<((int)cnt&1)<<"\n\n";
        if(!f)cout<<((int)cnt&1)<<'\n';
    }
    return 0;
}