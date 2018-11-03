#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
    int n;
    freopen("coordinate.in","r",stdin);
    freopen("coordinate.out","w",stdout);
    cin>>n;
    int ans=1e9;
    for(int i=1;i<n;i++){
        int q=i,w=n;
        int a=0;
        while(q>=1&&w>=1){
            if(q<w)swap(q,w);
            a+=q/w;
            //cout<<q<<' '<<w<<' '<<q/w<<'\n';
            q=q%w;
        }
        //cout<<i<<' '<<n<<' '<<q<<' '<<w<<' '<<a<<'\n';
        if(w==1)ans=min(ans,a-1);
    }
    cout<<ans;
    fclose(stdout);
    return 0;
}