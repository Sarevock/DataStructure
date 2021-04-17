#include<stdio.h>

//Lab 2 Struct

typedef struct{
    int id;
    char name[30];
} employee;

int main(){
    //Set employee
    employee e1 = {1, "Simon"};
    //print
    printf("ID: %d\nName: %s\n", e1.id, e1.name);
    //size
    printf ("%zu %zu %zu \n", sizeof (e1.id), sizeof (e1. name ), sizeof (e1));
    return 0;
}