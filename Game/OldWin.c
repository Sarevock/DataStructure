//connect 4 row	
for (int i = 0; i< 6; i++){	
	while(vai){
		for (int j = x; j < y; j++){				

			if (cycle){
				tmp = campo->a[i][j];					
				x++;
				y++;
				
				if(!tmp == 0){
					cycle = false;
				}					
			}
			else{
				if(campo->a[i][j] == tmp){
					connect++;
				}
				else{
						//change portion of bynary search					
						x++;
						y++;
						tmp = campo->a[i][j];
						//stop if check completed	
						if (x > 3){
							vai = false;
							cycle = true;
							x = 0;
							y = 4;
							tmp = 0;
							break;
						}													
				}
			}		

			if(connect == 3 && (tmp == 1 || tmp ==2)){
				win = true;					
				vai = false;
				cycle = true;
				x = 0;
				y = 4;					
				printf("Player %d Win", tmp);
				tmp = 0;
			}
		}
	}
}

// Function to concatenate
// two integers into one
int concat(int a, int b)
{
 
    char s1[20];
    char s2[20];
 
    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
 
    // Concatenate both strings
    strcat(s1, s2);
 
    // Convert the concatenated string
    // to integer
    int c = atoi(s1);
 
    // return the formed integer
    return c;
}