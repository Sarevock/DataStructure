#include <stdio.h>

//Lab 2.1

int main (){

    //Size of primitive datatypes
    
    //Long Vesion
    int integerVariable ;
    size_t size ;

    size = sizeof ( integerVariable );

    printf (" Size of Integer Variable is %zu bytes \n", size );


    //Refined evrsion
    int integerVariable2 ;

    printf (" Size of Integer Variable is %zu bytes \n", sizeof ( integerVariable2 ));

    return 0;

}