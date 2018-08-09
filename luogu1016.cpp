//贪心
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ss{
    double d,p;
}a[10];

bool cmp(ss a,ss b){
    return a.d<b.d;
}
int main(){
    double d1,c,d2,p;
    int n;
    cin>>d1>>c>>d2>>p>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i].d>>a[i].p;
     //   a[i].num=i;
    }

    a[n+1].d=d1;
    a[0].p=p;
    a[0].d=0;

    sort(a,a+n+1,cmp);
    //for(int i=0;i<=n;i++)cout<<a[i].p<<' '<<a[i].d<<' '<<i<<'\n';
    double curr=0;
    double cost=0;
    for(int i=0;i<=n;){
        int j=i;
        while(a[j].p>=a[i].p)j++;
        if(d2*c>=a[j].d-a[i].d){
            double gasneeded=((a[j].d-a[i].d)/d2);
            if(gasneeded>curr){
                cost+=(gasneeded-curr)*a[i].p;
                //cout<<"add gas at "<<i<<" for "<<(gasneeded-curr)*a[i].p<<'\n';
                curr=gasneeded;
            }
            curr-=gasneeded;
            i=j;
            //continue;
        }
        if(d2*c<a[j].d-a[i].d){
            int k=i+1;//STILL DONT KNOW WHY WHEN K=1 WILL TLE!!!
            //When k=i, yy.d will always = i, making it impossible to proceed.
            struct ss yy;
            yy.p=999999;
            while(a[k].d-a[i].d<d2*c){
                //k++;
                //cout<<k<<' '<<a[k].p<<' '<<yy.p<<'\n';
                if(a[k].p<yy.p)yy.d=k,yy.p=a[k].p;
                k++;
            }
            if(a[i+1].d-a[i].d>d2*c){cout<<"No Solution";return 0;}
            cost+=(c-curr)*a[i].p;
            //cout<<"add gas full at "<<i<<" for "<<(c-curr)*a[i].p<<'\n';
            //cout<<"Heading to "<<yy.d<<'\n';
            //cout<<"Best Offer "<<yy.p<<'\n';
            curr=c-((a[(int)yy.d].d-a[i].d)/d2);
            i=yy.d;

            //continue;
        }
        
        //cout<<curr;
        //cout<<cost<<'\n';

    }
    printf("%.2f\n",(double)cost);
    return 0;    
}