#include"bits/stdc++.h"
using namespace std;
int m;
int main(){
    cin>>m;
    for(int k1=sqrt(2*m);k1>1;k1--)//枚举k1(注意是k1>1而不是k1>=1)
        if(2*m%k1==0 && (k1+2*m/k1)%2){//如果K2是整数而且与K1一奇一偶
            int k2=2*m/k1;
                cout<<(k2-k1+1)/2<<" "<<(k1+k2-1)/2<<endl;//输出答案
        }
    return 0;
}
/*设首项为L，末项为R，那么sum(L,R)=(L+R)(R-L+1)/2=M

即(L+R)(R-L+1)=2M

可以把2M分解成两个数之积，假设分成了两个数K1,K2，且K1<K2时，

可以列一个二元一次方程组

R-L+1=K1

L+R=K2 解得L=(K2-K1+1)/2, R=(K1+K2-1)/2

当K1,K2一奇一偶时，L,R才有自然数解.

不过有一种特殊情况，就是L=R的情况，这种情况是不允许的

即(K2-K1+1)/2≠(K1+K2-1)/2,解得K1≠1*/