#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len=s.length();

    for(int j=1;j<=25;j++){
        for(int i=0;i<len;i++){
            s[i]++;
            if(s[i]>122)s[i]-=26;
        }
        cout<<s<<'\n';
    }
    return 0;
    
}