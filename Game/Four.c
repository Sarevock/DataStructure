#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Connect 4 Board
struct pitch{	
	int a[6][7];
	int col[7];
};

//Save Games
//Max Save Slots
#define MAX 10
//Max Moves
#define MAX2 84

//Singolar Record
struct rec{
	int start;
	int re[MAX2];
};
//Memory Card
struct saveGames{
	int salvataggio;
	struct rec save[MAX];
};

//Board
void init(struct pitch*);
void printBoard(struct pitch*);
int change(int );
void insert(struct pitch* , int , int );
bool winner (struct pitch* );

//SaveGames

//Singola Save
void singolar_init(struct rec* );
void singolar_add(struct rec* , int );
int *singolar_do(struct rec* , int );
int *singolar_undo(struct rec* , int );
void printami(struct rec* );

//Memory Card
void init_memory(struct saveGames* );
void record(struct saveGames* ,  struct rec );
bool isEmpty (struct saveGames * );
void selection(struct saveGames* );
void exchange(struct rec* , struct saveGames , int );
void vedere(struct saveGames* );


int main(){

	//Board
	struct pitch campo;
	//Game 1
	int player = 1;
	int position;
	bool win = false;
	//SaveGame
	int save = 0;	
	int move = -1;
	struct saveGames sa;
	struct rec ve;
	bool saveGa = false;
	bool replay = false;
	//init memory
	init_memory(&sa);
	int *i = NULL ;

	//Menu
	int choice = 0;

	while (choice != 5)
	{		
		if(replay == false){
			system("cls");
			printf("\n\tConnect 4");
			printf("\n\t------------------------------");
			printf("\n\n\t 1. Play");
			printf("\n\t 2. Record");
			printf("\n\t 3. Exit");
			printf("\n\n Enter Your Choice: ");
			scanf_s("%d", &choice);
		}		
		switch (choice)
		{
		case 1:
			win = false;
			clrscr();
			if (replay == false){
				init(&campo);
				singolar_init(&ve);
			}						
			while (win == false){

				clrscr();				
				printBoard(&campo);

				if (winner(&campo) == true){
					player = 1;
					printf("\n\nPress 1 : Yes");
					printf("\nPress 2 : No");
					printf("\nSave the Game?: ", choice);					
					scanf_s("%d", &choice);
					if (choice == 1){
						record(&sa, ve);
						printf("\nSaved!");
						printf("\nRedirecting to Main Menu!");
						replay = false;
						sleep(1);
						break;
					}
					else if (choice == 2){
						printf("\nRedirecting to Main Menu!");
						replay = false;
						sleep(1);
						break;
					}
					else{
						printf("\nRedirecting to Main Menu!");
						replay = false;
						sleep(1);
						break;
					}					
				}	
				printf("\nPress  0 : Reset the Game");
				printf("\nPress 1-7: Select a Column");
				printf("\n\nPlayer %d Enter Your Choice: ", player);
				scanf_s("%d", &position);

				if(position == 0){
					player = 1;
					init(&campo);
					singolar_init(&ve);
				}
				else if (position <= 1 || position <=7){
					position--;
					if(campo.col[position] < 6){
						insert(&campo, player, position);
						singolar_add(&ve, position);
						player = change(player);
					}
					else{
						printf("\nThe Selected Column is Full\n");
						sleep(1);
					}
				}
				else{
					printf("\nSelect a Correct Number\n");
					sleep(1);
				}										
			}	
			break;
		case 2:
			saveGa = false;
			player = 1;
			save = -1;
			move = -1;
			clrscr();
			init(&campo);
			singolar_init(&ve);

			if(isEmpty(&sa) ==  true){
				printf("No Save Data"); 
				saveGa = true;
			}
			else{

				printf("\nConnect 4");
				printf("\n------------------------------\n");
				selection(&sa);
				printf("\n\n Enter Your Choice: ");
				scanf_s("%d", &choice);
				save = choice - 1;
				//pass data
				exchange(&ve, sa, save);
				move = -1;
				//print on screen
				printf("\nManual Replay : 1");
				printf("\nAuto Replay : 2");
				printf("\n\nSelect 1 or 2?: ");					
				scanf_s("%d", &choice);
			}	

			while(saveGa == false){
				
				clrscr();				
				printBoard(&campo);	

				if (choice == 1){

					printf("\n\t 1. Do");
					printf("\n\t 2. Undo");
					printf("\n\t 3. Play From Here");
					printf("\n\t 4. Exit");

					printf("\n\n Enter Your Choice: ");
					scanf_s("%d", &position);

					if (position == 1){
						move++;
						i = singolar_do (&ve, move);
						if(i){							
							printf (" Move Restored : %d\n", *i); 							
							insert(&campo, player, *i);
							player = change(player);												
							sleep(1);
						}
						else{
							move--;
						}
					}
					else if(position == 2){
						i = singolar_undo (&ve , move);
						if(i){
							printf (" Move Removed : %d\n", *i); 
							out(&campo,  *i);
							player = change(player);
							move--;
						}
						sleep(1);
					}
					else if (position == 3){
						replay = true;
						choice = 1;					
						break;
					}
					else if (position == 4){
						choice = 0;
						player = 1;
						break;
					}
				}
				else if (choice == 2){
					if (winner(&campo) == true){
						player = 1;
						break;
					}
					if(move == -1){
						move = 0;
					}
					position = ve.re[move];
					printf("%d", ve.re[move]);
					insert(&campo, player, position);
					player = change(player);
					move++;	
					sleep(1);								
				}				
			}
			break;
		case 3:
			printf("\nYOU SELECTED OPTION 3 %c", 3);
			exit(0);
		otherwise:
			printf("\nINVALID SELECTION...Please try again");
		}
		_getch();
	}	

	return 0;
}


//Game

//Change player
int change(int change){
	if(change == 1){
		change = 2;
	}
	else if (change == 2){
		change =1;
	}
	return change;
}
//Screen Clear
void clrscr(){
    system("@cls||clear");
}

//Board
//Initialization
void init(struct pitch* campo){
	for (int i = 0; i< 6; i++){
		for (int j = 0; j < 7; j++){
			campo->a[i][j] = 0;
			campo->col[j] = 0;
		}
	}
}
//Print Board on screen
void printBoard(struct pitch* campo){
	printf("Connect Four\n");
	printf("-----------------------------\n");
	for (int i = 5; i >= 0; i--){
		for (int j = 0; j <= 6; j++){

			printf("| %d ",campo->a[i][j]);		
		}
		printf("|\n");
	}
	printf("-----------------------------\n");


	for (int j = 1; j <= 7; j++){
		printf("  %d ", j);
	}
	printf("\n");

	for (int j = 0; j < 7; j++){
		printf("  %d ", campo->col[j]);
	}
	printf("\n");
}
//Insert player token
void insert(struct pitch* campo, int player, int pos){
	if (player == 1){
		campo->a[campo->col[pos]][(pos)] = 1;
		campo->col[pos]++;
	}
	else{
		campo->a[campo->col[pos]][pos] = 2;
		campo->col[pos]++;
	}	
}
//Remove move
void out(struct pitch* campo, int pos){
	campo->col[pos] = campo->col[pos] -1;
	int sapere = campo->col[pos];
	campo->a[sapere][pos] = 0;
}
//Algoriths to find a winner
bool winner (struct pitch* campo){

	int connect = 0;
	int tmp = 0;
	int center = 3;
	int search = 0;

	bool left = true;
	bool right = true;
	bool up = true;
	bool down = true;
	
	bool win;
	//Row Check
	for (int i = 0; i < 6; i++){
		//take center value
		tmp = campo->a[i][center];
		search = center;
		//If player token is here
		if(!tmp == 0){
			//check left side
			while(left){			
				search --;
				if(tmp == campo->a[i][search]){
					connect++;				
				}
				else{
					search = center;					
					break;
				}

				if(search == 0){
					win = true;
					break;
				}
			}
			//check right
			if (win != true){
				while(right){
					search++;
					if(tmp == campo->a[i][search]){
						connect++;
					}
					else{
						search = center;
						break;
					}

					if(search == 6){
						win = true;
						break;
					}
				}
			}	

			//Win
			if (connect == 3 || win == true){				
				win = true;									
				printf("\nPlayer %d Win", tmp);
				tmp = 0;
				connect = 0;
				return win;	
				break;				
			}
			connect = 0;
		}		
	}
	//Column Check
	for (int j = 0; j < 7; j++){
		//take center value
		tmp = campo->a[center][j];
		search = center;
		//If player token is here
		if(!tmp == 0){
			//check down
			while(down){
				search--;		
				if(tmp == campo->a[search][j]){
					connect++;
				}
				else{
					search = center;
					break;
				}
				if(search == 0){
					win = true;
					break;
				}
			}
			//check up side
			if (win != true || connect >= 1){
				while(up){		
					search ++;
					if(tmp == campo->a[search][j]){
						connect++;			
					}
					else{
						search = center;
						break;
					}
					if(search == 5){
						search = center;
						break;
					}
				}
			}

			//Win
			if (connect == 3 || win == true){			
				win = true;									
				printf("\nPlayer %d Win", tmp);
				tmp = 0;
				connect = 0;
				return win;	
				break;				
			}
			connect = 0;		
		}
	}	
	//Laterale
	for(int i = 3; i < 7; i++){
		for(int j = 0; j < 6 - 3; j++){
			if (!campo->a[i][j] == 0){
				if (campo->a[i][j] == campo->a[i-1][j+1] && campo->a[i-1][j+1] == campo->a[i-2][j+2] && campo->a[i-2][j+2] == campo->a[i-3][j+3]){
					tmp = campo->a[i][j];					
					win = true;									
					printf("\nPlayer %d Win", tmp);
					tmp = 0;
					return win;	
					break;	
				}
			}				
		}
	}
	//Latarale Reverse
	for(int i = 0; i < 7 - 3; i++){
		for(int j = 0; j < 6 - 3; j++){
			if (!campo->a[i][j] == 0){
				if (campo->a[i][j] == campo->a[i+1][j+1]  && campo->a[i+1][j+1] == campo->a[i+2][j+2] && campo->a[i+2][j+2] == campo->a[i+3][j+3] ){
					tmp = campo->a[i][j];
					win = true;									
					printf("\nPlayer %d Win", tmp);
					tmp = 0;
					return win;	
					break;					
				}
			}
		}
	}
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
	//to add remove savegame
}
//Test Print
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
		printf("%d", sa->save->start);
	}	
}
//Check Data
bool isEmpty (struct saveGames* sa){
	if (sa->salvataggio == -1){
		return true;
	}
	else{
		return false;
	}
}
//Create SaveGames Selection
void selection(struct saveGames* sa){
	int save;
	for (int i = 0; i <= sa->salvataggio; i++){
		save = i + 1;
		printf("Replay Salvataggio %d\n", save);
	}
}
//Retrieve Save Game and cast it to Singolar Save
void exchange(struct rec* ve, struct saveGames sa, int which){
	for (int i = 0; i <= sa.save[which].start; i++){
		singolar_add(ve, sa.save[which].re[i]);
	}
}


//Singolar Save
void singolar_init(struct rec* sa){
	sa->start = -1;
}
//Add
void singolar_add(struct rec* sa, int pos){
	if(sa->start == MAX2 -1){
        printf("Save Game is full\n");
        return;    
    }
	sa->start++;
	sa->re[sa->start] = pos;
}
//Redo
int *singolar_do(struct rec* sa, int move){
	int *data;
	if(move == sa->start + 1){
		printf("Last Move\n");
		sleep(1);	
		return NULL;
	}

	data = &sa->re[move];
	return data;
}
//Undo
int *singolar_undo(struct rec* sa, int move){
	int *data;
	if(move == -1){
        printf("No more Undo\n");	
		sleep(1);	
        return NULL;		
    }

	data = &sa->re[move];
    return data;
}
//Test Print
void printami(struct rec* sa){
	for (int i = 0; i < sa->start; i++){
		printf("%d", sa->re[sa->start]);
		printf("\n%d", sa->start);
	}
}