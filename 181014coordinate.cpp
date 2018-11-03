#include<iostream>
#include<algorithm>
#include<queue>
#include<fstream>
//#include<bits/stdc++.h>

using namespace std;
struct stupid{
    int a,b,s;
}w,t;
void clear(queue<stupid>& q) {
    queue<stupid> empty;
    swap(empty, q);
}
int main(){
    //ifstream filein("coordinate.in");   
    //ofstream fileout("coordinate.out"); 
    //filein.eof();
    //freopen("coordinate.in","r",stdin);  //重定向所有标准的输入为文件输入
    //freopen("coordinate.out","w",stdout);//重定向所有标准的输出为文件输出
    int s;
    cin>>s;
        queue <stupid> q;
    //s=1000000;
    //for(int s=2;s<=700000;s++){
     //int   s=35000;
    int ma;
    int ok=0;
    int y=1;
    while(ok==0){
        y*=2;
        ma=0;
        clear(q);
        w.a=1;
        w.b=1;
        w.s=0;
        q.push(w);
        ok=0;
        while(!ok){
           w=q.front();
            //cout<<w.a<<' '<<w.b<<' '<<w.s<<'\n';
            q.pop();
            t.s=w.s+1;
            t.a=w.a+w.b;
            t.b=w.b;
            if(t.a==s)ok=t.s;
            ma=max(ma,t.a);
            if(ma>s*2)break;
            if(t.a>=ma/y)
            //cout<<ok<<' '<<t.s<<'A';
            q.push(t);
            t.a=w.a;
            t.b=w.a+w.b;
            if(t.b>=ma/y)
            q.push(t);
        }
    }
    //cout<<s<<' '<<ok<<'\n';}
    cout<<ok;
    return 0;
    //fclose(stdout);//输出结束
}