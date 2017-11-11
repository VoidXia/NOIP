/*Solution:
观察题意可以得知，如果第i位和第j位同色，那么就一定能够组成一个三元组，并且三元组的价值完全与中间那个数无关。那么，我们就用一个数组存储同奇偶性的同色方块，用n表示数值，i和j表示坐标。那么价值就是(n i+n j)*(i+j)。

现在如果把每组的数的下标用a1～an表示，数值用n1～nk表示，用sum表示数值之和。答案就是(n1+n2)*(a1+a2)+……+……。如果这样做就是O(n^2)的算法。

但是我们现在可以针对每一个数，只求只与这个数的下标和其他数值有关的值，也就是a1(n1+n2)+a1(n1+n3)+a1(n1+n4)+……+a1(n1+nk)。一个同奇偶性同颜色的一组总和就是a取1到k的得数之和。又因为a1(n1+n2) + a1(n1+n3) + a1(n1+n4)+……+a1(n1+nk)=a1(n1*(n-1)+n2+……+nk)=a1*n1*(n-2)+a1*sum。这样转化过来就很好求了，O(n)的时间复杂度就能得到解。楼下16位大佬也都给了详细的解释，蒟蒻就不多说了，下附Pascal代码：

*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define mod 10007
int main(){
    int n,m,sum[2][100010];
    int d[2][100010];
    cin>>n>>m;
    int num[100010];
    int col[100010];
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&col[i]);
        sum[i&1][col[i]]+=num[i];
        sum[i&1][col[i]]%=mod;
        d[i&1][col[i]]++;
    }
    int s=0;
    for(int i=1;i<=n;i++){
        s+=(i%mod)*((sum[i&1][col[i]]+((d[i&1][col[i]]-2)%mod)*num[i])%mod)%mod;
        s%=mod;
    }
    cout<<s;
    return 0;
}