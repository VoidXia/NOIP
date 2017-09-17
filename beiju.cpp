#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    char s[25];
    int next[25],last,cur;
    while(cin>>(s+1)){
        int n=strlen(s+1);
        last=cur=0;
        next[0]=0;
        for(int i=1;i<=n;i++){
            char ch=s[i];
            if (ch=='[')cur=0;
            else if (ch==']')cur=last;
            else{
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last)last=i;
                cur=i;
            }
        }
        for(int i=next[0];i!=0;i=next[i])cout<<s[i];

    }
    return 0;
}