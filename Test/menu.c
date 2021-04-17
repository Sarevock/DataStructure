#include <stdio.h>


int main()
{


  int row1[7]={0,0,0,0,0,0,0};
  int row2[7]={0,0,0,0,0,0,0};
  int row3[7]={0,0,0,0,0,0,0};
  int row4[7]={0,0,0,0,0,0,0};
  int row5[7]={0,0,0,0,0,0,0};
  int row6[7]={0,0,0,0,0,0,0};
  int row7[7]={0,0,0,0,0,0,0};


  int move1;
  int win=0;
  int j;
  int i;
  int onescore=0;
  int twoscore=0;
  char again='y';




  for(i=0;i<7;++i)
    {
      //row1.push_back('O');
      row1[0]='1';
      //row2.push_back('O');
      row2[0]='2';
      //row3.push_back('O');
      row3[0]='3';
      //row4.push_back('O');
      row4[0]='4';
      //row5.push_back('O');
      row5[0]='5';
      //row6.push_back('O');
      row6[0]='6';
      //row7.push_back('O');
      row7[0]='7';
    }


  while(again=='Y'||again=='y')
	{
		for(i=0;i<7;i++)
				{
				if(i==0)
					printf("\n\n\n   %d %d %d %d %d %d %d  \n  ---------------\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
				if(i>0&&i<7)
					printf(" | %d %d %d %d %d %d %d |\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
				if(i==6)
					printf("  ---------------\n |               |\n\n\n");
				}


      while(win==0)
        {
          ////////////////////////////////////////////////////////
          if(win==0)
            {
              printf("Player1:  ");
              scanf("%d", &move1);
              printf("\n\n");
              while(move1<1||move1>7||(move1==1&&(row1[1]=='1'||row1[1]=='2'))||(move1==2&&(row2[1]=='1'||row2[1]=='2'))||(move1==3&&(row3[1]=='1'||row3[1]=='2'))||(move1==4&&(row4[1]=='1'||row4[1]=='2'))||(move1==5&&(row5[1]=='1'||row5[1]=='2'))||(move1==6&&(row6[1]=='1'||row6[1]=='2'))||(move1==7&&(row7[1]=='1'||row7[1]=='2')))
                {
                  printf("Can't let you move there!\n\n\nPlayer1:  ");
                  scanf("%d", &move1);
                }
              if(move1==1)
                {
                  j=6;
                  while(row1[j]=='1'||row1[j]=='2')
                    {
                      j--;
                    }
                  row1[j]='1';
                }
              else if(move1==2)
                {
                  j=6;
                  while(row2[j]=='1'||row2[j]=='2')
					{
                      j--;
                    }
                  row2[j]='1';
                }
              else if(move1==3)
                {
                  j=6;
                  while(row3[j]=='1'||row3[j]=='2')
                    {
                      j--;
                    }
                  row3[j]='1';
                }
              else if(move1==4)
                {
                  j=6;
                  while(row4[j]=='1'||row4[j]=='2')
                    {
                      j--;
  					}
                  row4[j]='1';
                }
              else if(move1==5)
                {
                  j=6;
                  while(row5[j]=='1'||row5[j]=='2')
                    {
                      j--;
                    }
                  row5[j]='1';
                }
              else if(move1==6)
                {
                  j=6;
                  while(row6[j]=='1'||row6[j]=='2')
                    {
                      j--;
                    }
                  row6[j]='1';
                }
  			   else if(move1==7)
                {
                  j=6;
                  while(row7[j]=='1'||row7[j]=='2')
                    {
                      j--;
                    }
                  row7[j]='1';


                }
              //      printf('*', move1);
            }
          ////////////////////////////////////////////////////////
          for(i=0;i<7;++i)
            {
              if(i==0)
                printf("\n\n\n   %d %d %d %d %d %d %d  \n  ---------------\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
              if(i>0&&i<7)
                printf(" | %d %d %d %d %d %d %d |\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
              if(i==6)
                printf("  ---------------\n |               |\n\n\n");
  			}


          for(i=6;i>0;--i)
            {
              if((row1[i]=='1'&&row2[i]=='1'&&row3[i]=='1'&&row4[i]=='1')||(row5[i]=='1'&&row2[i]=='1'&&row3[i]=='1'&&row4[i]=='1')||(row5[i]=='1'&&row6[i]=='1'&&row3[i]=='1'&&row4[i]=='1')||(row5[i]=='1'&&row6[i]=='1'&&row7[i]=='1'&&row4[i]=='1'))
                win=1; //for horizontal
            }
          for(i=6;i>2;--i)
            {
              if((row1[i]=='1'&&row1[i-1]=='1'&&row1[i-2]=='1'&&row1[i-3]=='1')||(row2[i]=='1'&&row2[i-1]=='1'&&row2[i-2]=='1'&&row2[i-3]=='1')||(row3[i]=='1'&&row3[i-1]=='1'&&row3[i-2]=='1'&&row3[i-3]=='1')||(row4[i]=='1'&&row4[i-1]=='1'&&row4[i-2]=='1'&&row4[i-3]=='1')||(row5[i]=='1'&&row5[i-1]=='1'&&row5[i-2]=='1'&&row5[i-3]=='1')||(row6[i]=='1'&&row6[i-1]=='1'&&row6[i-2]=='1'&&row6[i-3]=='1')||(row7[i]=='1'&&row7[i-1]=='1'&&row7[i-2]=='1'&&row7[i-3]=='1'))
                win=1; //for vertical
              if((row1[i]=='1'&&row2[i-1]=='1'&&row3[i-2]=='1'&&row4[i-3]=='1')||(row2[i]=='1'&&row3[i-1]=='1'&&row4[i-2]=='1'&&row5[i-3]=='1')||(row3[i]=='1'&&row4[i-1]=='1'&&row5[i-2]=='1'&&row6[i-3]=='1')||(row4[i]=='1'&&row5[i-1]=='1'&&row6[i-2]=='1'&&row7[i-3]=='1'))
                win=1; //for diagonally up right
			if((row7[i]=='1'&&row6[i-1]=='1'&&row5[i-2]=='1'&&row4[i-3]=='1')||(row6[i]=='1'&&row5[i-1]=='1'&&row4[i-2]=='1'&&row3[i-3]=='1')||(row5[i]=='1'&&row4[i-1]=='1'&&row3[i-2]=='1'&&row2[i-3]=='1')||(row4[i]=='1'&&row3[i-1]=='1'&&row2[i-2]=='1'&&row1[i-3]=='1'))
                win=1; //for diagonally up left
            }
          ////////////////////////////////////////////////////////
          if(win==0)
            {
              printf("Player 2:  ");
              scanf("%d", &move1);
              printf("\n\n");
              while(move1<1||move1>7||(move1==1&&(row1[1]=='1'||row1[1]=='2'))||(move1==2&&(row2[1]=='1'||row2[1]=='2'))||(move1==3&&(row3[1]=='1'||row3[1]=='2'))||(move1==4&&(row4[1]=='1'||row4[1]=='2'))||(move1==5&&(row5[1]=='1'||row5[1]=='2'))||(move1==6&&(row6[1]=='1'||row6[1]=='2'))||(move1==7&&(row7[1]=='1'||row7[1]=='2')))
                {
                  printf("Can't let you move there!\n\n\nPlayer 2:  ");
                  scanf("%d", &move1);
                }


              if(move1==1)
                {
                  j=6;
                  while(row1[j]=='1'||row1[j]=='2')
 					{
                      j--;
                    }
                  row1[j]='2';
                }
              else if(move1==2)
                {
                  j=6;
                  while(row2[j]=='1'||row2[j]=='2')
                    {
                      j--;
                    }
                  row2[j]='2';
                }
              else if(move1==3)
                {
                  j=6;
                  while(row3[j]=='1'||row3[j]=='2')
                    {
            		}
                  row3[j]='2';
                }
              else if(move1==4)
                {
                  j=6;
                  while(row4[j]=='1'||row4[j]=='2')
                    {
                      j--;
                    }
                  row4[j]='2';
                }
              else if(move1==5)
                {
                  j=6;
                  while(row5[j]=='1'||row5[j]=='2')
                    {
                      j--;
                    }
                  row5[j]='2';
                }
 			  else if(move1==6)
                {
                  j=6;
                  while(row6[j]=='1'||row6[j]=='2')
                    {
                      j--;
                      {
                        j--;
                      }
                      row6[j]='2';
                    }
                }
                  else if(move1==7)
                    {
					  if(row7[1]=='1'||row7[1]=='2')
                        printf("nope");
                      else
                        {
                          j=6;
                          while(row7[j]=='1'||row7[j]=='2')
 							{
                              j--;
                            }
                          row7[j]='2';
                        }
                    }




              // printf('X', move1);
            }
              ////////////////////////////////////////////////////////
              for( i=0;i<7;++i)
                {
                  if(i==0)
                    printf("\n\n\n   %d %d %d %d %d %d %d  \n  ---------------\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
                  if(i>0&&i<7)
                    printf(" | %d %d %d %d %d %d %d |\n", row1[i], row2[i], row3[i], row4[i], row5[i], row6[i], row7[i]);
                  if(i==6)
                    printf("  ---------------\n |               |\n\n\n");
                }
				for(i=6;i>0;--i)
                {
    				if((row1[i]=='2'&&row2[i]=='2'&&row3[i]=='2'&&row4[i]=='2')||(row5[i]=='2'&&row2[i]=='2'&&row3[i]=='2'&&row4[i]=='2')||(row5[i]=='2'&&row6[i]=='2'&&row3[i]=='2'&&row4[i]=='2')||(row5[i]=='2'&&row6[i]=='2'&&row7[i]=='2'&&row4[i]=='2'))
                    win=2; //for horizontal
                }
                for(i=6;i>2;--i)
                {
                  if((row1[i]=='2'&&row1[i-1]=='2'&&row1[i-2]=='2'&&row1[i-3]=='2')||(row2[i]=='2'&&row2[i-1]=='2'&&row2[i-2]=='2'&&row2[i-3]=='2')||(row3[i]=='2'&&row3[i-1]=='2'&&row3[i-2]=='2'&&row3[i-3]=='2')||(row4[i]=='2'&&row4[i-1]=='2'&&row4[i-2]=='2'&&row4[i-3]=='2')||(row5[i]=='2'&&row5[i-1]=='2'&&row5[i-2]=='2'&&row5[i-3]=='2')||(row6[i]=='2'&&row6[i-1]=='2'&&row6[i-2]=='2'&&row6[i-3]=='2')||(row7[i]=='2'&&row7[i-1]=='2'&&row7[i-2]=='2'&&row7[i-3]=='2'))
                    win=2; //for vertical
                  if((row1[i]=='2'&&row2[i-1]=='2'&&row3[i-2]=='2'&&row4[i-3]=='2')||(row2[i]=='2'&&row3[i-1]=='2'&&row4[i-2]=='2'&&row5[i-3]=='2')||(row3[i]=='2'&&row4[i-1]=='2'&&row5[i-2]=='2'&&row6[i-3]=='2')||(row4[i]=='2'&&row5[i-1]=='2'&&row6[i-2]=='2'&&row7[i-3]=='2'))
                    win=2; //for diagonally up right
                  if((row7[i]=='2'&&row6[i-1]=='2'&&row5[i-2]=='2'&&row4[i-3]=='2')||(row6[i]=='2'&&row5[i-1]=='2'&&row4[i-2]=='2'&&row3[i-3]=='2')||(row5[i]=='2'&&row4[i-1]=='2'&&row3[i-2]=='2'&&row2[i-3]=='2')||(row4[i]=='2'&&row3[i-1]=='2'&&row2[i-2]=='2'&&row1[i-3]=='2'))
                    win=2; //for diagonally up left
                }
              /////////////
            }


          if(win==2)
            {
              ++twoscore;
              printf("Player 2 Wins!!!\n\nWould you like to play again? (Y/N): ");
            }
          else if(win==1)
            {
              ++onescore;
              printf("Player 1 Wins!!!\n\nWould you like to play again? (Y/N): ");
            }


          scanf("%c" ,&again);


          while(again!='Y'&&again!='y'&&again!='N'&&again!='n')
            {
              printf("Would you like to play again? (Y/N): ");
              scanf("%c", &again);
            }


          printf("\n\n\n\n\n\n");


          win=0;


          for(i=1;i<7;i++)
            {
              row1[i]='O';
              row2[i]='O';
              row3[i]='O';
              row4[i]='O';
              row5[i]='O';
              row6[i]='O';
              row7[i]='O';
            }
        }


      printf("Thanks for Playing!\n\n");
      return 0;
    }

	