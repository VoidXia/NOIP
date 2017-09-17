#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string c;
    //没有范围，一定是假的；
    int st[1000]={0};
    int top=0;
    getline(cin,c);
    int len=c.length();
    for(int i=0;i<len;i++){
        if(c[i]==' ')top++;
        if(isdigit(c[i]))st[top]=st[top]*10+int(c[i])-48/*,cout<<top<<' '<<i<<' '<<st[top]<<'\n'*/;
        if(c[i]=='+')top-=2,st[top]=st[top]+st[top+1],st[top+1]=0;
        if(c[i]=='-')top-=2,st[top]=st[top]-st[top+1],st[top+1]=0;
        if(c[i]=='/')top-=2,st[top]=st[top]/st[top+1],st[top+1]=0;
        if(c[i]=='*')top-=2,st[top]=st[top]*st[top+1],st[top+1]=0;

    }
    cout<<st[top];
    //简单粗暴
}