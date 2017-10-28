#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
/*
 * freopen("shopping.in","r",stdin);
 * freopen("shopping.out","w",stdin);
 */
	int n, m;
	scanf( "%d%d", &n, &m );
	int dp[310][310]; /* 第几天,剩几个 ,值是花费 */
	memset( dp, 0, sizeof(dp) );
/*
 * int num[100010];
 * memset(num,0,sizeof(num));
 */
	int	u = 0;
	int	tt[310][310];
	memset( tt, 0, sizeof(tt) );
	while ( n-- )
	{
		u++;
		int a[100010];
		for ( int i = 1; i <= m; i++ )
			scanf( "%d", &a[i] );
		sort( a + 1, a + m + 1 );

		for ( int i = 1; i <= m; i++ )
		{
			for ( int j = i; j <= 300; j-- )
			{
				for ( int k = 1; k <= i; k++ )
				{
					dp[u][j] += a[k];
				}
				dp[u][j] += tt[u - 1][j - i];
/* for(int k=1;k<=m;k++) */
				tt[u][j] = min( dp[u][j], tt[u][j] );

				if ( j < u )
					dp[u][j] = 100100;  /* ya shi la liang fei fan */
			}
		}
	}
	int ans = 100100;
	for ( int j = u; j <= 300; j++ )
		ans = min( ans, dp[u][j] );
	printf( "%d", ans );
	return(0);
}


