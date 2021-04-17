#include<stdio.h>

//Lab 2 Struct

int main(){

    int a[100];
    size_t s = sizeof(a);
    printf("%xu bytes\n", s);

    size_t num = s/sizeof(int);
    printf("space fro storing %zu elements\n", num);

    return 0;
}