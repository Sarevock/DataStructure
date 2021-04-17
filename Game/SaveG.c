#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Save Games

#define MAX 10

//Singolar Record
struct rec{
	int start;
	int re[84];
};
//Max 10 Saved games
struct saveGames{
	int salvataggio;
	struct rec save[MAX];
};

void init_Save(struct saveGames* );
void record(struct saveGames* , int , bool );
void print(struct saveGames* );

void test_init(struct saveGames* );

int main(){

struct saveGames save;

test_init(&save);

print(&save);

return 0;

}


//SaveGame

//Init

void init_Save(struct saveGames* sa){
	sa->salvataggio = -1;
}

void test_init(struct saveGames* sa){

	for(int i = 0; i < 84; i++){
		sa->save[0].re[sa->save->start] = i;
    	sa->save->start++;
	}
}

//Add
void record(struct saveGames* sa,  int pos, bool new){

	if(sa->salvataggio == MAX -1){
        printf("Save Game is full\n");
        return;    
    }

	if (new == true){
		sa->salvataggio++;
		sa->save->start = 0;
	}
	else{
		sa->save[sa->salvataggio].re[sa->save->start] = pos;
    	sa->save->start++;
	}
}
//Remove
void drocer(struct saveGames* sa, int pos){



}

//print

void print(struct saveGames* sa){

	for(int i = 0; i < 84; i++){

		printf("%d", sa->save[0].re[i]);

	}

}