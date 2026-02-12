#include <sstream>
#include <iostream>
#include "adder.h"

int main( int argc , char *argv[] ) {
    int a, b, d;

    if( argc != 3 ) return 1 ;

    std::string sa( argv[ 1 ] ) ;
    std::string sb( argv[ 2 ] ) ;

    std::stringstream ssa( sa ) ;
    std::stringstream ssb( sb ) ;

    ssa >> a ;
    ssb >> b ;

    d = add( a , b );
    std::cout << d ;

    return 0 ;
}
