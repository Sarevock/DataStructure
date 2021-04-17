#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Save Games

#define MAX 10
#define MAX2 84

//Singolar Record
struct rec{
	int start;
	int re[MAX2];
};
//Max 10 Saved games
struct saveGames{
	int salvataggio;
	struct rec save[MAX];
};

//Singola Save

void singolar_init(struct rec* );
void singolar_add(struct rec* , int );
int *singolar_do(struct rec* , int );
int *singolar_undo(struct rec* );

//MemoryCard

void init_memory(struct saveGames* );
void record(struct saveGames* ,  struct rec );
void vedere(struct saveGames* );
void print(struct saveGames* );
void exchange(struct rec* , struct saveGames , int );


int main(){

	int choice = 0;

	struct rec ve;
	struct saveGames sa;

	singolar_init(&ve);
	init_memory(&sa);

	singolar_add(&ve, 0);
	singolar_add(&ve, 1);
	singolar_add(&ve, 2);

	record(&sa, ve);

	singolar_init(&ve);

	exchange(&ve, sa, 1);

	bool win = false;

	int *i = NULL ;
	int last = ve.start;

	while (win == false){

		system("cls");
		printf("\n\tConnect 4");
		printf("\n\t------------------------------");
		for (int i = 0; i <= ve.start; i++){
			printf("\n%d", ve.re[i]);
		}
		printf("\n\t 2. Do");
		printf("\n\t 2. Undo");
		printf("\n\n Enter Your Choice: ");
		scanf_s("%d", &choice);

		switch(choice){
			
			case 1:			
			i = singolar_do (&ve, last);
    		if(i) { printf (" Move Restored : %d\n", *i); }
			sleep(2);
			break;
			case 2:
			i = singolar_undo (&ve);
    		if(i) { printf (" Move Removed : %d\n", *i); }
			sleep(2);
			break;
			case 3:
			record(&sa, ve);	
			vedere(&sa);
			sleep(1);
			break;
		}

	}
	return 0;
}


//SaveGame

//Init
void init_memory(struct saveGames* sa){
	sa->salvataggio = -1;
}
//Add
void record(struct saveGames* sa,  struct rec ve){

	if(sa->salvataggio == MAX -1){
        printf("Save Game is full\n");
        return;    
    }

	sa->salvataggio++;
	sa->save[sa->salvataggio] = ve;
}
//Remove
void drocer(struct saveGames* sa, int ve){

}
//Print
void vedere(struct saveGames* sa){

	if(sa->salvataggio < 0){
		printf("Nothing Here!");
	}
	else{
		for (int i = 0; i <= sa->salvataggio; i++){
			for (int j = 0; j <= sa->save[i].start; j++){
				printf("%d", sa->save[i].re[j]);
			}
			printf("\n");
		}
	}	
}

//Exchange data
void exchange(struct rec* ve, struct saveGames sa, int which){

	for (int i = 0; i <= sa.save[0].start; i++){
		singolar_add(ve, sa.save[0].re[i]);
	}
}

//singolar save
void singolar_init(struct rec* sa){
	sa->start = -1;
}

void singolar_add(struct rec* sa, int pos){
	if(sa->start == MAX2 -1){
        printf("Save Game is full\n");
        return;    
    }
	sa->start++;
	sa->re[sa->start] = pos;
}

int *singolar_do(struct rec* sa,  int last){
	int *data;
	if(sa->start == last){
		printf("Last Move\n");
		return NULL;
	}

	sa->start++;
	data = &sa->re[sa->start];
	return data;
}

int *singolar_undo(struct rec* sa){
	int *data;
	if(sa->start == -1){
        printf("No more Undo\n");
        return NULL;
    }

	data = &sa->re[sa->start];
    sa->start--;
    return data;
}
