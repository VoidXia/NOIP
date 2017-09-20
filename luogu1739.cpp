#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int ans;
    bool naotou=1;
    ios::sync_with_stdio(false);
    while(cin>>c){
        if(c=='(')ans++;
        if(c==')')ans--;
        if(ans<0)naotou=0;
    }
    if(ans<0)naotou=0;
    if(naotou)printf("YES");
    else printf("NO");
return 0;
}