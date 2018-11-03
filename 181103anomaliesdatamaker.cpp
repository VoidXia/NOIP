#include<iostream>
using namespace std;
int main(){
    srand((int)time(0));
    int y=150000;
    int q=1;
    freopen("anomalies.in","w",stdout);
    cout<<y<<'\n';
    while(y--){
        cout<<abs(q-rand()%1000000000)<<' ';
        cout<<q<<' ';
        q=rand()%1000000000;
        cout<<q<<'\n';
    }
    fclose(stdout);
    return 0;
}