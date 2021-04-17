#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Connect 4 Pitch
struct pitch{	
	int a[6][7];
	int col[7];
};

//Save Games

//Singolar Record
struct rec{
	int move;
	int re[84];
};
//Max 10 Saved games
struct saveGames{
	int salvataggio;
	struct rec save[10];
};

// Function to concatenate
// two integers into one
int concat(int , int );

//Pitch
void init(struct pitch*);
void printPitch(struct pitch*);
int change(int );
void insert(struct pitch* , int , int );
bool winner (struct pitch* );

//Test
void vediamo(struct pitch* );


int main(){

	struct pitch campo;

	int player = 1;
	int position;

	bool win = false;

	int choice = 0;

	while (choice != 5)
	{
		system("cls");
		printf("\n\tConnect 4");
		printf("\n\t------------------------------");
		printf("\n\n\t 1. Play");
		printf("\n\t 2. Record");
		printf("\n\t 3. Exit");
		printf("\n\n Enter Your Choice: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:

			clrscr();
			init(&campo);

			while (win == false){

				clrscr();				
				printPitch(&campo);

				if (winner(&campo) == true){
					sleep(1);
					player = 1;
					choice = 4;
					break;
				}	

				printf("\n Player %d Enter Your Choice: ", player);
				scanf_s("%d", &position);

				if (position <= 1 || position <=7){
					if(campo.col[position] < 6){
						insert(&campo, player, position);
						player = change(player);
					}
					else{
						printf("\nThe Selected Column is Full\n");
						sleep(1);
					}
				}
				else{
					printf("\nSelect a column between 0 and 6\n");
					sleep(1);
				}										
			}		
			break;
		case 2:
			printf("\nYOU SELECTED OPTION 2 %c", 2);
			break;
		case 3:
			printf("\nYOU SELECTED OPTION 3 %c", 3);
			exit(0);
		case 4:
			player = 1;
			win = false;
			choice = 0;
			break;
		otherwise:
			printf("\nINVALID SELECTION...Please try again");
		}
		_getch();
	}	

	return 0;
}

void init(struct pitch* campo){
	for (int i = 0; i< 6; i++){
		for (int j = 0; j < 7; j++){
			campo->a[i][j] = 0;
			campo->col[j] = 0;
		}
	}
}

void printPitch(struct pitch* campo){
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

int change(int change){
	
	if(change == 1){
		change = 2;
	}
	else if (change == 2){
		change =1;
	}
	return change;
}

void insert(struct pitch* campo, int player, int pos){
	int dove = pos-1;
	if (player == 1){
		campo->a[campo->col[dove]][(dove)] = 1;
		campo->col[dove]++;
	}
	else{
		campo->a[campo->col[dove]][dove] = 2;
		campo->col[dove]++;
	}	
}

void vediamo(struct pitch* campo){
	//test
	campo->a[0][0] = 1;
	campo->a[1][1] = 1;
	campo->a[2][2] = 1;
	campo->a[3][3] = 1;
}

void out(struct pitch* campo, int player, int pos){
	
}

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

void clrscr(){
    system("@cls||clear");
}