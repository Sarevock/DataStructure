#include<stdio.h>

//Lab 3 Array Api

#define MAX 5

//inittialization of the array
void init(int* array){

    int idx;
    //set all to 0
    for(idx =0; idx < MAX; idx++){

        array[idx] = 0;
  
    }
}

//Show the content of the array
void display(int* array){

    int idx;

    for(idx =0; idx < MAX; idx++){

        printf("%d\t", array[idx]);

    }
    printf("\n");
}

//Insert data in the array
void insert(int* array, int pos, int num){

    int idx;

    for (idx = MAX -1; idx >= pos; idx--){

        array[idx] = array[idx-1];
    }

    array[idx] = num;

}

//Delete data from the array
void delete(int* array, int pos){

    int idx;
    for ( idx = pos ; idx < MAX ; idx ++){
        array [idx -1] = array [ idx ];
    }
    array [idx -1] = 0;
}

//Reverse position
void reverse(int* array){

    int idx;
    for(idx = 0; idx<MAX/2; idx++){
        int temp = array[idx];
        array[idx] = array[MAX-1-idx];
        array[MAX-1-idx] = temp;
    }
}

void search(int* array, int num){

    int idx;
    for ( idx =0; idx < MAX ; idx ++){
        if( array [ idx ] == num ){
            printf ("%d found in position %d\n", num , idx +1) ;
            return;
        }
    }
    if(idx == MAX ){
        printf ("%d not found in array \n", num );
    }
}

int main(void){
    
    int array [MAX];
    init(array);

    insert(array, 1, 11);
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);
    insert(array, 5, 15);

    printf("Array Content: \n");
    display(array);

    delete(array, 5);
    delete(array, 2);

    printf("After Decision: \n");
    display(array);

    insert(array, 2, 222);
    insert(array, 5, 555);

    printf("Array insertion: \n");
    display(array);

    reverse(array);

    printf("After Reverse: \n");
    display(array);

    search(array,222);
    search(array, 666);
 
    return 0;
}