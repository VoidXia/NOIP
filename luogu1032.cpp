#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>

const int maxn=15;
using namespace std;

string a,b;
string ori[maxn];
string tra[maxn];

struct st{
    string s;
    int step;
};

queue<st> q;

string find(string s,int i,int j){
    string ans="";
    for(int w=0;w<ori[j].length();w++)
        if(s[i+w]!=ori[j][w])return ans;
    ans=s.substr(0,i);
    ans+=tra[j];
    ans+=s.substr(i+ori[j].length());
    return ans;
}
map <string,int> ma;
int main(){
    cin>>a>>b;
    int n=0;
    while(cin>>ori[n]>>tra[n])n++;
    st s;
    s.s=a;
    s.step=0;
    q.push(s);
    int ans=15;
    while(!q.empty()){
        st u=q.front();
        q.pop();
        if(ma[u.s]==1)continue;
        if(u.s==b){ans=u.step;break;}
        ma[u.s]=1;
        for(int i=0;i<u.s.length();i++){
            for(int j=0;j<n;j++){
                string aans=find(u.s,i,j);
                if(aans!=""){
                    st v;
                    v.s=aans;
                    v.step=u.step+1;
                    q.push(v);
                }
            }
        }
    }
    if(ans>10)cout<<"NO ANSWER!";
    else cout<<ans;
    return 0;
}