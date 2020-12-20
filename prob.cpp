#include <iomanip>
#include <iostream>
using namespace std;
double p = 0.99;
double s = 0.0015;

double pow( double x, int n ) {
    if ( n == 0 )
        return 1;
    else {
        while ( ( n & 1 ) == 0 ) {
            n >>= 1;
            x *= x;
        }
    }
    double result = x;
    n >>= 1;
    while ( n != 0 ) {
        x *= x;
        if ( n & 1 ) result *= x;
        n >>= 1;
    }
    return result;
}

int main() {
    cout << setprecision( 14 );
    double a[ 200 ] = {0};
    for ( int i = 1; i <= 30; i++ ) {
        a[ i ] = ( 1 - p ) * pow( p, i - 1 );
        cout << a[ i ] << '\n';
    }
    double tmp = pow( p, 30 );
    for ( int i = 31; i <= 99; i++ ) {
        a[ i ] = tmp * ( 1 - p ) + s * ( i - 30 );
        for ( int j = 31; j <= i - 1; j++ ) {
            a[ i ] *= ( p - s * ( j - 30 ) );
        }
        cout << a[ i ] << '\n';
    }
    a[ 100 ] = tmp;
    for ( int j = 31; j <= 100; j++ ) {
        a[ 100 ] *= ( p - s * ( j - 30 ) );
    }
    cout << a[ 100 ] << '\n';
    double ansa = 0, ansb = 0;
    for ( int i = 1; i <= 100; i++ ) {
        ansa += a[ i ] * i;
        ansb += a[ i ] * i * i;
    }
    cout << "E=" << ansa << '\n';
    cout << "D=" << ansb - ansa * ansa << '\n';
    return 0;
}
