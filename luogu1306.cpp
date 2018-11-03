#include<iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main(){
    ll a,b;
    cin>>a>>b;
    ll r=gcd(a,b);
    
}