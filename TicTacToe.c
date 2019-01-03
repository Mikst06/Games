#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void PlayerNUM(int *player);
void Print(char square[],int player,int score1,int score2);
void Change(char square[],int player);
int Answer(char square[]);
bool WIN(char square[],int *player,int *score1, int *score2);
bool Continue();
void main()
{
  int player = 2,score1 = 0,score2 = 0;
  char square[9] = { '1','2','3','4','5','6','7','8','9' };
  do
    {
    do
      {
	PlayerNUM(&player);
	Print(square,player,score1,score2);
      }while(WIN(square,&player,&score1,&score2) == false);
    square[0] = '1';
    square[1] = '2';
    square[2] = '3';
    square[3] = '4';
    square[4] = '5';
    square[5] = '6';
    square[6] = '7';
    square[7] = '8';
    square[8] = '9';
    }while(Continue() == true);
}
void PlayerNUM(int *player)
{
  if (*player == 1)
    {
      *player += 1;
    }
  else
    {
      *player -= 1;
    }
}
int Answer(char square[])
{
  int answer;
  do{
  printf("\t\t\t\t\t\tWhich square do you choose ?\t");
  scanf("%d",&answer);
  if (( square[answer-1] == 'X' ) || ( square[answer-1] == 'O' ))
    {
      printf("You can't choose that square. There is '%c' already.\n",square[answer-1]);
    }
  }while(( square[answer-1] == 'X' ) || ( square[answer-1] == 'O' ));
  return answer;
}
void Change(char square[],int player)
{
  if( player == 1 )
    {
      switch(Answer(square))
	{
	case 1: square[0] = 'X'; break;
	case 2: square[1] = 'X'; break;
	case 3: square[2] = 'X'; break;
	case 4: square[3] = 'X'; break;
	case 5: square[4] = 'X'; break;
	case 6: square[5] = 'X'; break;
	case 7: square[6] = 'X'; break;
	case 8: square[7] = 'X'; break;
	case 9: square[8] = 'X'; break;
	}
    }
  if( player == 2)
      {
      switch(Answer(square))
	{
	case 1: square[0] = 'O'; break;
	case 2: square[1] = 'O'; break;
	case 3: square[2] = 'O'; break;
	case 4: square[3] = 'O'; break;
	case 5: square[4] = 'O'; break;
	case 6: square[5] = 'O'; break;
	case 7: square[6] = 'O'; break;
	case 8: square[7] = 'O'; break;
	case 9: square[8] = 'O'; break;
	}
      }
}                  
void Print(char square[], int player,int score1,int score2)
{ 
  system("clear");
  printf("\t\t\t\t\t\tPlayer 1 'X', Player 2 'O'\n\t\t\t\t\t\tPlayer %d turn\n\t\t\t\t\t\tSCORE: Player 1 -%d- Player2 -%d- \n\n\n",player,score1,score2); 
  printf("\n\n\n\n\n\n");
  printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[0],square[1],square[2]);
  printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[3],square[4],square[5]);
  printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[6],square[7],square[8]);
  printf("\n\n");
  Change(square,player);
  
  
}
bool WIN(char square[],int *player,int *score1,int *score2)
{
  if ( (square[0] ==  square[1] && square [1] == square[2]) || (square[3] ==  square[4] && square [4] == square[5]) || (square[6] ==  square[7] && square [7] == square[8]) || (square[0] ==  square[3] && square [3] == square[6]) || (square[1] ==  square[4] && square [4] == square[7]) || (square[2] ==  square[5] && square [5] == square[8]) || (square[0] ==  square[4] && square [4] == square[8]) || (square[2] ==  square[4] && square [4] == square[6]) )
    {
      system("clear");
      printf("\n\n\n\n\n\n\n\n");      
      printf("\t\t\t\t\t\t\tPLAYER %d WINS\n\n",*player);
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[0],square[1],square[2]);
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[3],square[4],square[5]);
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[6],square[7],square[8]);
      printf("\n\n");
      if ( *player == 1 )
	{
	  *score1 +=1;
	}
      else
	{
	  *score2 +=1;
	}	
      return true;
    }
  else if (( square[0] != '1' ) && ( square[1] != '2' ) && ( square[2] != '3' ) && ( square[3] != '4' ) && ( square[4] != '5' ) && 
	   ( square[6] != '7' ) && ( square[7] != '8' ) && ( square[5] != '6' ) && ( square[8] != '9' ))
    {
      system("clear");
      printf("\n\n\n\n\n\n\n\n");      
      printf("\t\t\t\t\t\t\t     DRAW\n\n");
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[0],square[1],square[2]);
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[3],square[4],square[5]);
      printf("\t\t\t\t\t\t\t| %c | %c | %c |\n",square[6],square[7],square[8]);
      printf("\n\n");
      return true;
    }
}
bool Continue()
{
  char AnswerCont,space;
  printf("Do you want to play again ?\nY - yes N - no\n");
  scanf("%c",&space);
  scanf("%c",&AnswerCont); 
  if ( (AnswerCont == 'Y') || ( AnswerCont == 'y' ) )
    {
      return true;
    }
  else
    {
      return false;
    }
}
