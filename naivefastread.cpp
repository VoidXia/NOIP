#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
template <typename tn>
void read(tn& a){
    a = 0; char c;
    while (!isdigit(c = getchar()));
    do a = a * 10 + c - '0'; while (isdigit(c = getchar()));
}