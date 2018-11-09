#include <bits/stdc++.h>
using namespace std;



int main()
{
	multiset<int> def,mis;
	multiset<int>::iterator iter1,iter2;
	int m=0,n=0;
	int s;
	scanf("%d %d",&m,&n);
	for (int i=0;i!=m;i++)
	{
		int p;
		scanf("%d",&p);
		def.insert(p);
	}
	for (int i=0;i!=n;i++)
	{
		int p;
		scanf("%d",&p);
		mis.insert(p);
	}
	if (m>n)
	{
		printf("%d\n",0);
		return(0);
	}
	s=0;
	for (iter1=def.begin(),iter2=mis.begin();(iter1!=def.end());iter2++)
	{
		if (!(iter2!=mis.end()))
		{
			printf("%d",0);
			return(0);
		}
		if (*iter1>*iter2) {s=s+*iter2;}
		else {iter1++;}
	}
	for (;iter2!=mis.end();iter2++) {s=s+*iter2;}
	cout<<s;
	return(0);
}