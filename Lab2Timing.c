#include<stdio.h>
#include<time.h>

void code(){

    for (int i=0; i <10000; i++){
        printf(".");
    }
    printf("\n");
}

//Lab2 Timer

int main(){

    clock_t t;
    printf("start: %d \n",(int) (t=clock()));

    code();

    printf("stop: %d \n", (int) (t=clock()-t));
    
    printf("elapsed: %f seconds\n", (double) t/CLOCKS_PER_SEC);

    return 0;

}