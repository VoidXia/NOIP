#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include<cstdio>
using namespace std;
#define mo 998244353
struct node{
    int a,b;
};
int main(){
    int n;
    cin>>n;
    int a[1010];
    set <int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.insert(a[i]);
        //cout<<'B';
    }
    sort(a+1,a+n+1);
    int cnt=0;
    //cout<<'A';
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++){
        int j=i+1;
        set <int> s;
        while(j<=n&&!s.count(j)){
            s.insert(j);
            int k=1;
            int c=2;
            int temp=a[j]+(a[j]-a[i])*k;
            if(a[j]-a[i]==0){
                j++;
                cnt+=3;
                continue;
            }
            while(q.count(temp)){
                //int temp=a[j]+(a[j]-a[i])*k;
                cout<<temp<<' '<<i<<' '<<j<<'\n';
                s.insert(temp);
                temp+=a[j]-a[i];
                c++;
                k++;
            }
            cout<<i<<' '<<j<<' '<<c<<' '<<pow(2,c)-1<<'\n';
            cnt+=pow(2,c)-1;
            j++;
        }
    }
    cout<<cnt+n;
    return 0;
}