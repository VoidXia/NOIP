#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int debugflg = 0;
#define maxint 19260817
queue<int> q;

struct node {
    int val;
} node[ maxint ];

int head[ maxint ] = { 0 };

struct lingjiebiao {
    int val;
    int nxt;
    int to;
} llink[ maxint ];

int maxsize = 1;

void addson( int fat, int son ) {
    cout << "     [DEBUG]ADDING EDGE FROM " << fat << " TO " << son << '\n';
    // if(head[fat]==0)head[fat]=maxsize++;
    // int tmp=head[fat];while(llink[tmp].nxt!=-1)tmp=llink[tmp].nxt;
    llink[ maxsize ].to  = son;
    llink[ maxsize ].nxt = head[ fat ];
    head[ fat ]          = maxsize;
    maxsize++;
}

int nodes  = 0;
int levels = 0;

int readdata( int fatt ) {

    levels++;
    // cout<<levels<<'\n';
    nodes++;
    int nownode = nodes;
    cout << "\n\nNODE NUMBER " << nodes << "\n";
    if ( levels == 1 ) {
        cout << "This is root node.\n";
    } // addson(0,nodes);}
    cout << "Please enter the value of that node:";
    cin >> node[ nodes ].val;
    if ( node[ nodes ].val == 0 ) {
        levels--;
        if ( fatt == 0 ) return 7;
        cout << "backing to UPPERLEVEL, same hierarchy as NUMBER " << fatt
             << " ,with VALUE " << node[ fatt ].val << '\n';
        return 9;
    }
    addson( fatt, nodes );
    cout << "Please enter the son's values of that node, note that nodes "
            "should be inputed recursively.\n";
    while ( readdata( nownode ) != 9 )
        ;
    levels--;
    return 0;
}

bool searchx( int x, int root ) {
    while ( !q.empty() )
        q.pop();
    q.push( root );
    int tmp = root;
    while ( !q.empty() ) {
        tmp = llink[ q.front() ].to;
        if ( debugflg )
            cout << "\n   [DEBUG]NOW AT " << tmp << " WITH VAL OF "
                 << node[ tmp ].val;
        q.pop();
        if ( node[ tmp ].val == x ) return 1;
        for ( int i = head[ tmp ]; i > 0; i = llink[ i ].nxt ) {
            q.push( i );
            if ( debugflg )
                cout << "\n   [DEBUG]PUSHING " << llink[ i ].to
                     << " WITH VAL OF " << node[ llink[ i ].to ].val;
        }
    }
    return 0;
}

int main() {
    for ( int i = 1; i <= 100; i++ )
        llink[ i ].nxt = -1;
    for ( int i = 1; i <= 100; i++ )
        head[ i ] = -1;
    levels = 0;
    while ( readdata( 0 ) != 7 )
        levels = 0;
    cout << "\nREAD DATA COMPLETE.\n\n";

    int  x    = 19260817;
    bool flag = 0;
    flag      = 0;
    cout << "\n\nInput the value of the searching node: ";
    cin >> x;
    while ( x != 0 ) {
        for ( int i = head[ 0 ]; i > 0; i = llink[ i ].nxt ) {
            if ( debugflg ) cout << "\n\n   [DEBUG]ROOT AT " << llink[ i ].to;
            if ( searchx( x, i ) ) {
                cout << "\n\nFOUND AT TREE WITH ROOT " << llink[ i ].to
                     << ".\n";
                flag = 1;
                // break;//whether to search multiple results.
            }
        }
        if ( !flag ) cout << "\n\nNOT FOUND.\n";
        flag = 0;
        cout << "\n\nInput the value of the searching node: ";
        cin >> x;
    }
    cout << "\n\nEXIT\n";
    return 0;
}