/*101010101
101000101
101111101
100000001
000000000
 ?9:5


1010101
1011101
1000001
1111111
 ?7:4

10101
10001
11111
 ?5:3

101
111
 ?3:2

1010
1110
0000
 ?4:3

101010
101110
111110
111111
 ?6:4
 

ans=(num/2)+1;

101
10000


111101110111101
11110 0 0111101
1111  1  111101
0            01
1             1
0

111101110111101
1111010101
所有连通块中距离中间那个最近的好联通块
好联通块左右扩展的就(x/2)+1
剩下的联通块+x
here is (3/2)+1+(7-3)=6
10101000001
12345  6  7
10111110101
10000000101
11111111101
00000000001
11
0

12  3  4567
1010111
10100
1011
100
11
0
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("eliminate.in","r",stdin);freopen("eliminate.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long ans=0;
    string s;
    int poi[10010];int cnt=0;
    int l,r;
    char p;
    int len,found;
    while(m--){
        s.clear();
        cnt=0;
        cin>>s;
        //cout<<s<<'\n';
        p=s[0];
        len=s.length();
        poi[++cnt]=0;
        for(int i=1;i<len;i++){
            if(s[i]!=p){
                poi[++cnt]=i;
                //cout<<i<<' '<<s[i]<<' '<<p<<"fuck\n";
                //cout<<(s[i]==p)<<'\n';
                p=s[i];
            }
        }
        //cout<<cnt<<"cnt\n";
        if(cnt==len)continue;
        poi[cnt+1]=len;
        l=(1+cnt)/2;
        if(cnt&1)r=l;else r=l+1;
        //cout<<l<<' '<<r<<'\n';
        while(l>=1&&r<=cnt){
            if((poi[l+1]-poi[l])>1||(poi[r+1]-poi[r])>1){ans+=(l+(cnt-(2*(l-1)+1)));break;}
            //if((poi[r+1]-poi[r])>1){found=r;cout<<r<<' '<<(cnt+1-r)<<' '<<(cnt-(2*(cnt-r)+1))<<"r\n";ans+=(l+(cnt-(2*(l-1)+1)));break;}
            //if((poi[l+1]-poi[l])>1){ans+=(l+(cnt-(2*(l-1)+1)));break;}
            //if((poi[r+1]-poi[r])>1){ans+=((cnt+1-r)+(cnt-(2*(cnt-r)+1)));break;}
            l--;r++;
        }
    }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
/*
101000100010101000000100100101
1234  56  789012     34 56 789
10101010101010101
12345678901234567
10101010111010101
10101010000010101
10101011111110101
10101000000000101
10101         101
10100         001
1011           11
100            01
1 1
0
*/