//暴力骗分过样例
//UVA201

#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	char c;
	int kk=0;
	int m,n,ans[10]={0};
	bool h[10][10]={0},v[10][10]={0};
	while(cin>>n>>m){
	    kk++;
	memset(ans,0,sizeof(ans));
	memset(h,0,sizeof(h));
	memset(v,0,sizeof(v));
	for(int i=1;i<=m;i++){
		int FU,CK;
		cin>>c;
		cin>>FU>>CK;
		if(c=='V')v[CK][FU]=1;
		if(c=='H')h[FU][CK]=1;
	}
	for(int ro=1;ro<=n;ro++){
		for(int co=1;co<=n;co++){
			int mmm=min(n-ro,n-co);
			for(int cnt=1;cnt<=mmm;cnt++){
				bool flag=1;
				for(int i=0;i<cnt;i++){
					if(!h[co][ro+i]||!h[co+cnt][ro+i])flag=0;
				}
				for(int i=0;i<cnt;i++){
					if(!v[co+i][ro]||!v[co+i][ro+cnt])flag=0;
				}
				if(flag==1)ans[cnt]++;
			}
			
		}
	}
	int flag=1;
	if(kk!=1)cout<<'\n'<<"**********************************"<<'\n'<<'\n';
	cout<<"Problem #"<<kk<<'\n'<<'\n';
	for(int i=1;i<=n;i++){
	    if(ans[i]!=0)cout<<ans[i]<<" square (s) of size "<<i<<'\n',flag=0;
	}
	if (flag==1)cout<<"No completed squares can be found.";
//	cout<<'\n';
	}
	cout<<'\n';
	return 0;
}